'(*********************************************************************************************************************************
                 TRANSMITTER V10_0.BAS
written for    : BASCOM-AVR Version 2.0.7.3 build 001
by             : Jan Huygh (jan.huygh@gmail.com)
in             : December 2011

-----[Copyright (c) 2011 Jan Huygh jan.huygh@gmail.com]----------------------------------------------------------------------------

The author would appreciate it if enhancements to this software or it's documentation would be communicated to him.

In an effort to encourage the development of enhancements to this software permission is hereby granted, free of charge, to any
person obtaining a copy of this software, to deal in the software without restriction, including without limitation the right to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of this software, and to permit persons to whom the
software is furnished to do so if the above copyright notice and this permission notice is included in all copies of this software
or a substantial portion of this software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

-----[Introduction]----------------------------------------------------------------------------------------------------------------

If you want to build your own RC transmitter then using a commercial HF module such as the Graupner/JR Sender-HF-Modul
Part Nr 4057 or the Graupner/JR PLL-SYNTHESIZER-Sender HF-Modul Part Nr 4059 is a good idea. Another alternative is a 2.4GHz
module like the Jeti Duplex TU2 EX (http://jetimodel.com/index.php?page=product&id=197)
Using such a module you will not have to worry about a transmitter license nor will you have to worry about building the HF-portion
of the transmitter. Such modules take a Pulse Position Modulation signal as input.
I can buy such a module for about 75 Euro. If somebody can tell me where I can buy a comparable module for less please send me a
mail. jan.huygh@gmail.com

-----[Description of the positive Pulse Position Modulation signal]----------------------------------------------------------------

The line goes low for 0,4ms then high for 1 to 2 ms then low again for 0,4 ms. The 1 to 2 ms pulse represents channel-1.
You can now add channel-2 to channel-8 by bringing the line high for 1 to 2 ms and then low again for 0,4 ms for each channel.
After channel 8 you have to end with a 0,4 ms low. This pulsetrain is repeated every 20 ms. Since all the channels might want to
transmit a 2 ms pulse and we need to separate the channels with a 0,4 ms pulse we can transmit 8 channels within 20 ms since
0,4 + 8 * (0,4 + 2) = 19.6 ms. You do not need to transmit 8 channels. You can stop after any channel just don't forget to end with
a 0,4ms low.

-----[Connecting to a Graupner/JR Sender-HF-Modul]---------------------------------------------------------------------------------

  |                    If you put the HF module in front of you with the connector (5 small holes) in the lower left corner
  |  � PPM             the connections are as indicated here on the left.
  |  � +5V
  |  � +8V                PPM is the Positive Pulse Position Signal
  |  � GND                + 5V is a stabelized 5V tention
  |  � To Antenna         + 8V to this you connect your main battery (8 * 1.5 = 12V is OK too ).
  |______________         GND is the ground connection (the - from the battery)

-----[Connecting to a Jeti Duplex TU2 EX modul]------------------------------------------------------------------------------------

That can not be simpler : 5V to 5V, Ground to ground, PPM output from your AVR to PPM input of the module. DONE !

-----[My version numbering system]-------------------------------------------------------------------------------------------------

When I start with a completely new program that will be the version 1_0.
As more functionality is introduced sucessive versions will be named 1_1, 1_2, ...
At a certain point in time I will have the first supposed usable version that will be version 2_0
When bug fixes and minor functionality changes are introduced the version numbers will be 2_1, 2_2, ...
When I start developing major functionality changes that version will be version 3_0, 3_1, 3_2, ...
The first usable version of that code will be version 4_0.
So in summary : versions starting with an odd number (1,3,5,...) are development versions not for use
                versions strating with an even number (2,4,6,...) are supposed to be usable.

-----[Version planning for Transmitter]--------------------------------------------------------------------------------------------

Version 10_0 : The two channel single model transmitter (Computer required to program)
Reads the potentiometer for the speed and the steering stick on the transmitter.
Reads the potentiometer for the speed trim and the steering trim on the transmitter.
Reads the fixed programmed Sub-trim setting for steer and speed.
Reads the fixed programmed values for steer maximum, steer minimum, speed maximum, speed minimuml. (Neutral = subtrim)
Reads the fixed programmed Steer_reverse (yes or no) and Speed_reverse (yes or no) setting.
Reads the fixed programmed values for steer and speed exponential.
Calculates the pulse lengths.
Generates the Pulse Position Modulation signal.

Version 12_0 :The two channel multiple model transmitter
Reads the battery voltage and displays it on an LCD.
Reads a selector switch that selects what model is used (9 models supported)
Menu system that enables the user to program into the EEPROM (for each of the 9 models supported) the values for
- Steer_normal_reverse, Steer_subtrim, Steer_high_max, Steer_low_max, Steer_exponential
- Speed_normal_reverse, Speed_subtrim, Speed_high_max, Speed_low_max, Speed_exponential
- Model_name (10 characters)
Reads the potentiometer for the speed and the steering stick on the transmitter.
Reads the potentiometer for the speed-trim and the steering-trim on the transmitter.
Reads the EEPROM value for Sub-trim setting for steer and speed.
Reads the EEPROM value for values for steer maximum, steer minimum, speed maximum, speed minimuml. (Neutral = subtrim)
Reads the EEPROM value for Steer_reverse (yes or no) and Speed_reverse (yes or no) setting.
Reads the EEPROM value for values for steer and speed exponential.
Calculates the pulse lengths.
Generates the Pulse Position Modulation signal.

Version 14_0 to 18_0 :The two channel multiple model transmitter
Skipped on purpose to accomodate for eventual changes in the above numbering and still be able to start with the first version
with a timer as version 20_0

Version 20_0
Same as previous version PLUS
A timer/lap counter

Version 22_0 to 28_0
Skipped on purpose to accomodate for versions that have different functionality of the lab counter and still be able to start with
the first version with an automatic sequence as version 30_0

Version 30_0
Same as previous version PLUS
By pushing a button the user can trigger a sequence of events.
The purpose of this functionality would be to aim for a perfect combination of actions for a specific manouvre.

-----[CPU cycle table and timing table for 8 bit timer Timer0 when running with a 16Mhz external crystal]--------------------------

Prescale  Maximum CPU Cycles before       Precision        With a 16MHz external crystal   With 16Mhz external crystal
  Factor            Timer0 overflow     CPU Cyclse]  Maxumum time before Timer0 Overflow    Highest possible precision

      1         65 536 =     65 536               1        65 536/16 000 000 =     4 096 �s                  0,0625 �s
      8     8 X 65 536 =    524 288               8       524 288/16 000 000 =    32 768 �s                  0,5 �s
     64    64 X 65 536 =  4 194 304              64     4 194 304/16 000 000 =   262 144 �s                  4 �s
    256   256 X 65 536 = 16 777 216             256    16 777 216/16 000 000 = 1 048 576 �s                 16 �s

-----------------------------------------------------------------------------------------------------------------------------------
')

'We are using an ATmega16 with a 16MHz crystal
$regfile = "m16def.dat" : $crystal = 16000000

Config Adc = Single , Prescaler = Auto , Reference = Avcc : Start Adc

'We use TIMER1 to generate the Pulse Place Modulation Signal
Config Timer1 = Timer , Prescale = 8 : On Timer1 Timer1_isr : Stop Timer1
Enable Timer1 : Enable Interrupts

'We will use a 20 character per line, 2 line Liquid Cristal Display connected as indicated in the statements here below
Config Lcdpin = Pin , Db4 = Portc.0 , Db5 = Portc.1 , Db6 = Portc.2 , Db7 = Portc.3 , E = Portc.5 , Rs = Portc.4
Config Lcd = 20 * 2 : Initlcd : Cursor Off : Cls :

'Here we indicate what transmitter controll is connecetd to what AVR-pin
Ppm_output_pin Alias Portc.6 : Config Ppm_output_pin = Output
Get_steerstick_position Alias Getadc(0)
Get_speedstick_position Alias Getadc(2)
Get_steertrim_position Alias Getadc(1)
Get_speedtrim_position Alias Getadc(3)
'Here we enter the values that are linked to the mechanics of the transmitter
Const Steerstick_lowest = 108
Const Steerstick_neutral = 518
Const Steerstick_maximum = 904
Const Speedstick_lowest = 126
Const Speedstick_neutral = 378
Const Speedstick_maximum = 893
Const Steertrim_lowest = 144
Const Steertrim_neutral = 507
Const Steertrim_maximum = 896
Const Speedtrim_lowest = 167
Const Speedtrim_neutral = 510
Const Speedtrim_maximum = 897
'Here we calculate values that are linked to the mechanics of the transmitter
Const Steerstick_lower_range = Steerstick_neutral - Steerstick_lowest
Const Steerstick_upper_range = Steerstick_maximum - Steerstick_neutral
Const Speedstick_lower_range = Speedstick_neutral - Speedstick_lowest
Const Speedstick_upper_range = Speedstick_maximum - Speedstick_neutral
Const Steertrim_lower_range = Steertrim_neutral - Steertrim_lowest
Const Steertrim_upper_range = Steertrim_maximum - Steertrim_neutral
Const Speedtrim_lower_range = Speedtrim_neutral - Speedtrim_lowest
Const Speedtrim_upper_range = Speedtrim_maximum - Speedtrim_neutral
'Here we set values that later on will need to come from the EEPROM
Const Steer_r_setting = 0       'has to be 0 or 1
Const Speed_r_setting = 0       'has to be 0 or 1
Const Steer_subtrim = 0       'Range is -200 to +200
Const Speed_subtrim = 0       'Range is -200 to +200
Const Steer_low_reduction = 0       'Range is 0 to 300
Const Steer_high_reduction = 0       'Range is 0 to 300
Const Speed_low_reduction = 0       'Range is 0 to 300
Const Speed_high_reduction = 0       'Range is 0 to 300
Const Steer_exponential = 100       'Range is -100 to + 100 but stored as 0=100 so 200 = 100
Const Speed_exponential = 100       'Range is -100 to +100 but stored as 0=100 so 200 = 100

Dim B1 As Byte , Count As Byte , Ch(3) As Word , W1 As Word , L1 As Long , L2 As Long , L3 As Long , L4 As Long
Dim Xbp As Integer , Ybp As Integer , Expo As Integer
Dim Steer_r As Bit , Speed_r As Bit

Steer_r = Steer_r_setting
Speed_r = Speed_r_setting
Count = 1
For B1 = 1 To 2
   Ch(b1) = 500
Next
Start Timer1

Do

   L1 = Get_steerstick_position
   If L1 < Steerstick_lowest Then L1 = Steerstick_lowest
   If L1 > Steerstick_maximum Then L1 = Steerstick_maximum
   L1 = L1 - Steerstick_neutral
   L1 = L1 * 500
   If L1 < 0 Then L1 = L1 / Steerstick_lower_range Else L1 = L1 / Steerstick_upper_range

   'exponential
   Expo = Steer_exponential - 100       ' -100 < expo < 100
   Expo = Expo * 2       ' -200 < expo < 200
   If L1 > 0 Then
      Xbp = 250 - Expo
      Ybp = 250 + Expo
      If L1 < Xbp Then       ' Y = A1 * X
         L2 = Ybp * L1 : L1 = L2 / Xbp
      Else
         L2 = Ybp - 500
         L3 = Xbp - 500
         L4 = L2 * L1 : L4 = L4 / L3 : L4 = L4 + 500 : L2 = L2 * 500 : L2 = L2 / L3 : L1 = L4 - L2
      End If
   Else       'If L1 =< 0
      Xbp = -250 + Expo
      Ybp = -250 - Expo
      If L1 > Xbp Then       'Y = A1 * X
         L2 = Ybp * L1 : L1 = L2 / Xbp
      Else
         L2 = Ybp + 500
         L3 = Xbp + 500
         L4 = L2 * L1 : L4 = L4 / L3 : L4 = L4 - 500 : L2 = L2 * 500 : L2 = L2 / L3 : L1 = L4 + L2
      End If
   End If       ' L1

   'Trim
   L2 = Get_steertrim_position
   If L2 < Steertrim_lowest Then L2 = Steertrim_lowest
   If L2 > Steertrim_maximum Then L2 = Steertrim_maximum
   L2 = L2 - Steertrim_neutral
   L2 = L2 * 200
   If L2 < 0 Then L2 = L2 / Steertrim_lower_range Else L2 = L2 / Steertrim_upper_range

   L2 = L2 + Steer_subtrim : If L2 > 200 Then L2 = 200 : If L2 < -200 Then L2 = -200
   If L1 > 0 Then
      L3 = 500 - L2
      L3 = L3 - Steer_high_reduction
   Else
      L3 = 500 + L2
      L3 = L3 - Steer_low_reduction
   End If
   L1 = L3 * L1 : L1 = L1 / 500 : L1 = L1 + L2

   If Steer_r = 0 Then Ch(1) = L1 + 500 Else Ch(1) = 500 - L1


   L1 = Get_speedstick_position
   If L1 < Speedstick_lowest Then L1 = Speedstick_lowest
   If L1 > Speedstick_maximum Then L1 = Speedstick_maximum
   L1 = L1 - Speedstick_neutral
   L1 = L1 * 500
   If L1 < 0 Then L1 = L1 / Speedstick_lower_range Else L1 = L1 / Speedstick_upper_range

   'exponential
   Expo = Speed_exponential - 100       ' -100 < expo < 100
   Expo = Expo * 2       ' -200 < expo < 200
   If L1 > 0 Then
      Xbp = 250 - Expo
      Ybp = 250 + Expo
      If L1 < Xbp Then       ' Y = A1 * X
         L2 = Ybp * L1 : L1 = L2 / Xbp
      Else
         L2 = Ybp - 500
         L3 = Xbp - 500
         L4 = L2 * L1 : L4 = L4 / L3 : L4 = L4 + 500 : L2 = L2 * 500 : L2 = L2 / L3 : L1 = L4 - L2
      End If
   Else       'If L1 =< 0
      Xbp = -250 + Expo
      Ybp = -250 - Expo
      If L1 > Xbp Then       'Y = A1 * X
         L2 = Ybp * L1 : L1 = L2 / Xbp
      Else
         L2 = Ybp + 500
         L3 = Xbp + 500
         L4 = L2 * L1 : L4 = L4 / L3 : L4 = L4 - 500 : L2 = L2 * 500 : L2 = L2 / L3 : L1 = L4 + L2
      End If
   End If       ' L1

   L2 = Get_speedtrim_position
   If L2 < Speedtrim_lowest Then L2 = Speedtrim_lowest
   If L2 > Speedtrim_maximum Then L2 = Speedtrim_maximum
   L2 = L2 - Speedtrim_neutral
   L2 = L2 * 200
   If L2 < 0 Then L2 = L2 / Speedtrim_lower_range Else L2 = L2 / Speedtrim_upper_range

   L2 = L2 + Speed_subtrim : If L2 > 200 Then L2 = 200 : If L2 < -200 Then L2 = -200
   If L1 > 0 Then
      L3 = 500 - L2
      L3 = L3 - Speed_high_reduction
   Else
      L3 = 500 + L2
      L3 = L3 - Speed_low_reduction
   End If
   L1 = L3 * L1 : L1 = L1 / 500 : L1 = L1 + L2

   If Speed_r = 0 Then Ch(2) = L1 + 500 Else Ch(2) = 500 - L1

Loop

End

Timer1_isr:
   If Count = 1 Or Count = 3 Or Count = 5 Then
      Reset Ppm_output_pin
      Timer1 = 64752
   Elseif Count = 2 Or Count = 4 Then
      Set Ppm_output_pin
      B1 = Count / 2 : W1 = Ch(b1) * 2 : Timer1 = 63576 - W1
   Elseif Count = 6 Then
      Set Ppm_output_pin
      W1 = 0
      For B1 = 1 To 2
         W1 = W1 + Ch(b1)
      Next
      W1 = 15800 - W1 : W1 = W1 * 2 : Timer1 = 63536 - W1
   End If
   Incr Count : If Count = 7 Then Count = 1
Return