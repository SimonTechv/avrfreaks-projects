/*********************************************************************************************************
	��������� ��� ���������� c ������������� ������� Ethernet IIM7010A WIZnet Inc.
	��� ��������� ������ ������������ UDP ��������.
 _________________________________________________________________________________________________________
*	
* ��������� ������������� ��� ����������� AT90CAN128. ������� ������ - 6 ���. ������� - 3.3�
* � ������ ���������� ������ ������ Ethernet IIM7010A WIZnet Inc., ��� ������������ ����������,
* ���������� WDT, ����������� � ������������ �������.
----------------------------------------------------------------------------------------------------
* �������������� �������� � ������� Ethernet �������� � ������ indirect Bus mode � ��������� ������� 0xfff0-0xfff3. 
	0xfff0 �������-IDM_OR d7=IND_EN d1=L/B d0=AUTO_INC
	0xfff1 �������-IDM_AR0 indirect bus I/F mode address0 register
	0xfff2 �������-IDM_AR1 indirect bus I/F mode address1 register
	0xfff3 �������-IDM_DR  indirect bus I/F mode data register
----------------------------------------------------------------------------------------------------
* ����� 0xfff6 ����������� ��� ������ ������ Ethernet � ��������� �������� ������-����������� ������.
	0xfff6 ������ d6=reset_ethernet
	0xfff6 ������ d6=reset_ethernet
----------------------------------------------------------------------------------------------------
*
* �������� ����� �����������:
* PE3 - ������� ��������� �������� ���������� VH1
* PE2 - ������� ��������� �������� ���������� VH2
* PD4 - �������-������ ������ �������� ��������� ������� �� 4.58�
* PD7 - ������������ - ����� �������� ����������� �������
*_________________________________________________________________________________________________________
*
* ������ �������� ������� � ������������ ���������, ��������� � ����� defGlobal.h.
* ��������� UDP �����.
* ��� ���������� ������ ������� �� ������ � �������� UDP �������, ������ ���������
* ���������� ������� ETH_work().
*_________________________________________________________________________________________________________
*
* ��� ������ ������ ���� ������������ ��������� - struct ETH_Request	ETH_Rec;   
* struct ETH_Request
* {	
*	unsigned char		req;	// ������� ������� ������� ���������� ������ ��� ����� ������ �� ���� ethernet
*	unsigned char		leng;	// ����� �������� ���������� ��� �������, ������ � 8� �������� ����������
* };
* ���� ETH_Rec.req != 0, ��� ��������� �� ����� ������ ������, ��� ��� ����� �� ����.
* ���� leng ��������� �� ����� �������� ����������.
* ���������� �������� ��������� ������ �������� ������� ETH_Rec.rec, � ������������ ������ leng ����
* ��������� ������ ethRCbuff[]. ������, ���� ������ ������� ���� �����, �� ������ 8�� ����
* ����� ���������. ������ 2� ����� - ��� ����� ���������, ������� ��� ������� �����, ����� 4�
* ����� - IP ����� ��������� ���������, ����� 2� ����� - ����� ����� ��������� ���������.
* ������� ���� � ����� �����, IP ������ � ������ ����� ���� �������.
* ����� ���� ���������������� UDP ������.
*_________________________________________________________________________________________________________
*
* ��� ���������� �������� ������ � ������� UDP �������, ������������ ���������
* struct ETH_Request	ETH_Send;
* struct ETH_Request
* {	
*	unsigned char	req;	// ������� ������� �������� ������ � ������ ethernet
*	unsigned char	leng;	// ����� ������������ � �������� ������
* };
* �������������� ��������� ������� ��������� ������� �������� req.
* ���� ������� �������, �� ����� �������������� ������� ��������� ������ ������ � ����� ��������.
* ������ �������� � �����.
* ���������� ����� ������������ ������ � ��������� leng ��������� � ����������
* ������� ������� �������� ������ � ������ ethernet req=1.
*_________________________________________________________________________________________________________
*
* ������ �������� ����� �������� �� ������� ������ ��������� � �����������.
* �������� ����� ������� ���� unsigned char.
* ethTRbuff[ETH_TR_SIZE] - ��������� ����� �����������, ��������������� � ���� ������������ ������ �� ����������.
* ethRCbuff[ETH_RC_SIZE] - ����� ���������, ������������ ������ ������ �������� �����.
*
* ETH_RC_SIZE		dd		// ������ ������ ������ ������, ������� ������ �� ���� ethernet.
* ETH_TR_SIZE		dd-8	// ������ ������ ������ �������������� �������� ��������������� ��� �������� �� ethernet.
* ��� dd <= 255. ��������������� � ����� defConstant.h!
*_________________________________________________________________________________________________________
* 
* ��������� ������������� ������� ������ �� ������� ���������� 25 ��, ��� ������������ ��������� ��������
* �������� ����������� ���������. ��������� ������� ���������� � ����������.
* ������ ��� ������� �������������� �� ���� ���������� ������� time_out[4]. ���������� � �������� ����,
* ������������� �� ��������� �������� ���������� ������, �������� �������� ����������.
*_________________________________________________________________________________________________________
* 
* ��������� ������������� � ����������� ���������� � ������� ���������� ������.
* ����������� �������� ������������ ���������������� ������ Ethernet, 
* ������� ������ ������� �� ��������������� ��������� ����� �������������.
* ���� � ������� �������� �������� ������������� ���� ������,
* �� ����� ������ � ��������� ������������� ����� ���� ���������
* ������� ���������� � 0 �������� ��������� ETH_stat.phase.
****************************************************************************/
//#define MYTEST
/****************************************************************/
#include <avr/io.h>
#include <avr/wdt.h>
#include "headers/MACRO.H"
#include "headers/defConstant.h"
#include "headers/defGlobal.h"
#include "headers/defFunction.h"
/****************************************************************/

int		main(void);

/****************************************************************/

int main(void)
{
	wdt_disable();
	initCPU();									// Hardware CPU initialization
	INT_enable();								// ���������� ����������
	
	#ifdef MYTEST								// ��� ���������� ������� ��������� ���������� ���������
	{
	
	}
	#endif
	
	GREEN_ON();
	RED_OFF();
	ETH_stat.initRequest = 1;					//�������-���������� ��������� ������ �� FLASH

	while(1)
	{
		/**/
		while((PIND & 0x10) == 0)				//������� ���������� ��������� ��� �������� ��������� �������
		{
			WDText();							// ����� �������� ����������� �������
			wdt_reset();						// ����� ����������� ����������� �������
			if(time_out[1] == 0)				// �������� ��� ����������� ������� ���������� ��������� ������ �������
			{
				time_out[1]=12;					// ����� �������
				RED_TOG();						// ������������ ���������� ��������� ������ �������
				GREEN_OFF();					// ���������� ���������� ������
			}
		}
		/**/
		if(time_out[1] == 0) RED_OFF();		// ���������� ���������� �� ��������� ��������� �������
		if(time_out[0] == 0)					// �������� ��� ����������� ������� ���������� ��������� ������
		{
			time_out[0]=25;						// ��������� �������
			GREEN_TOG();						// ������������ ���������� ������
		}
		WDText();								// ����� �������� ����������� �������
		wdt_reset();							// ����� ����������� ����������� �������
		ETH_work();								// ������ � ������� WIZnet
	}
	return 0;
}


/****************************************************************/
/****************************************************************/
