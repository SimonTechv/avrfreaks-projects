#include <avr/io.h>
#include "Define/MACRO.H"
#include "Define/defConstant.h"
#include "Define/defStruct.h"
/****************************************************************/
/*
	������������� ����� ��������� ���������� �
	��������� ���� ������ �� �������� 3.
*/
/****************************************************************/
extern struct descWork dw;				// ��������� - ��������� ���� ������ ����������
/****************************************************************/

void cryptInit(void)
{
	if(dw.phase != 2)	return;			//������� �� ������� �� ���� �������������
	/*-----------------------------*/
	/*������������� ����� ��������� ���������� (���������� �� ������������)*/
	dw.phase=3;
}

