EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 7250 1200 2    50   Output ~ 0
5V
$Comp
L power:GND #PWR0101
U 1 1 616D7A98
P 6500 1650
F 0 "#PWR0101" H 6500 1400 50  0001 C CNN
F 1 "GND" H 6505 1477 50  0000 C CNN
F 2 "" H 6500 1650 50  0001 C CNN
F 3 "" H 6500 1650 50  0001 C CNN
	1    6500 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 3050 1350 3050
Wire Wire Line
	6500 1500 6500 1550
$Comp
L nano-ble-sense-speaker-rev0-rescue:LM78L05_TO92-Linear-reg U1
U 1 1 616D28C0
P 6500 1200
F 0 "U1" H 6500 1442 50  0000 C CNN
F 1 "LM78L05_TO92" H 6500 1351 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 6500 1425 50  0001 C CIN
F 3 "https://www.onsemi.com/pub/Collateral/MC78L06A-D.pdf" H 6500 1150 50  0001 C CNN
	1    6500 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C2
U 1 1 616F6CCF
P 7050 1450
F 0 "C2" H 7141 1496 50  0000 L CNN
F 1 "C" H 7141 1405 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 7050 1450 50  0001 C CNN
F 3 "~" H 7050 1450 50  0001 C CNN
	1    7050 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C1
U 1 1 616FACC5
P 5950 1450
F 0 "C1" H 5859 1496 50  0000 R CNN
F 1 "C" H 5859 1405 50  0000 R CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 5950 1450 50  0001 C CNN
F 3 "~" H 5950 1450 50  0001 C CNN
	1    5950 1450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6800 1200 7050 1200
Wire Wire Line
	7050 1350 7050 1200
Connection ~ 7050 1200
Wire Wire Line
	7050 1200 7250 1200
Wire Wire Line
	5950 1350 5950 1200
Wire Wire Line
	5950 1200 6200 1200
Wire Wire Line
	5950 1550 6500 1550
Connection ~ 6500 1550
Wire Wire Line
	6500 1550 6500 1650
Wire Wire Line
	7050 1550 6500 1550
$Comp
L power:+9V #PWR0103
U 1 1 61703537
P 5400 1200
F 0 "#PWR0103" H 5400 1050 50  0001 C CNN
F 1 "+9V" H 5415 1373 50  0000 C CNN
F 2 "" H 5400 1200 50  0001 C CNN
F 3 "" H 5400 1200 50  0001 C CNN
	1    5400 1200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J2
U 1 1 6170C5E3
P 6500 2000
F 0 "J2" H 6528 1976 50  0000 L CNN
F 1 "Conn_01x02_Female" H 6528 1885 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 6500 2000 50  0001 C CNN
F 3 "~" H 6500 2000 50  0001 C CNN
	1    6500 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 1200 5400 2000
Wire Wire Line
	5950 1550 5950 2100
Wire Wire Line
	5950 2100 6300 2100
Connection ~ 5950 1550
$Comp
L SSD1306-128x64_OLED:SSD1306 Brd1
U 1 1 61713D71
P 4200 1850
F 0 "Brd1" H 4478 1954 50  0000 L CNN
F 1 "SSD1306" H 4478 1863 50  0000 L CNN
F 2 "SSD1306:128x64OLED" H 4200 2100 50  0001 C CNN
F 3 "" H 4200 2100 50  0001 C CNN
	1    4200 1850
	1    0    0    -1  
$EndComp
Text GLabel 3900 1300 0    50   Input ~ 0
3V3
$Comp
L power:GND #PWR0104
U 1 1 61718B31
P 3800 1500
F 0 "#PWR0104" H 3800 1250 50  0001 C CNN
F 1 "GND" H 3805 1327 50  0000 C CNN
F 2 "" H 3800 1500 50  0001 C CNN
F 3 "" H 3800 1500 50  0001 C CNN
	1    3800 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1450 4050 1500
Wire Wire Line
	4150 1300 4150 1500
Text GLabel 4450 1450 2    50   Output ~ 0
OLED_SCL
Text GLabel 4450 1300 2    50   Output ~ 0
OLED_SDA
Text GLabel 1150 2450 0    50   Output ~ 0
OLED_SDA
Text GLabel 1150 2550 0    50   Output ~ 0
OLED_SCL
Wire Wire Line
	1150 2450 1350 2450
Wire Wire Line
	1150 2550 1350 2550
$Comp
L Device:R 2.7K2
U 1 1 616C6DBD
P 4500 1200
F 0 "2.7K2" V 4293 1200 50  0000 C CNN
F 1 "R" V 4384 1200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4430 1200 50  0001 C CNN
F 3 "~" H 4500 1200 50  0001 C CNN
	1    4500 1200
	0    1    1    0   
$EndComp
$Comp
L Device:R 2.7K1
U 1 1 616C707B
P 4100 1200
F 0 "2.7K1" V 3893 1200 50  0000 C CNN
F 1 "R" V 3984 1200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4030 1200 50  0001 C CNN
F 3 "~" H 4100 1200 50  0001 C CNN
	1    4100 1200
	0    1    1    0   
$EndComp
Text GLabel 4700 1200 2    50   Input ~ 0
3V3
Text GLabel 3900 1200 0    50   Input ~ 0
3V3
Wire Wire Line
	3800 1450 3800 1500
Wire Wire Line
	3800 1450 4050 1450
Wire Wire Line
	3900 1300 4150 1300
Wire Wire Line
	3900 1200 3950 1200
Wire Wire Line
	4250 1500 4250 1450
Wire Wire Line
	4450 1300 4350 1300
Wire Wire Line
	4450 1450 4250 1450
Connection ~ 4250 1450
Wire Wire Line
	4250 1450 4250 1200
Wire Wire Line
	4350 1500 4350 1300
Wire Wire Line
	4650 1200 4700 1200
Wire Wire Line
	4350 1200 4350 1300
Connection ~ 4350 1300
$Comp
L LED:HDSP-4830_2 BAR_LED1
U 1 1 61C9BEEE
P 4400 2800
F 0 "BAR_LED1" H 4400 3467 50  0000 C CNN
F 1 "HDSP-4830_2" H 4400 3376 50  0000 C CNN
F 2 "Display:HDSP-4830" H 4400 2000 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-1798EN" H 2400 3000 50  0001 C CNN
	1    4400 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D1
U 1 1 61CA4EDA
P 5750 1200
F 0 "D1" H 5750 983 50  0000 C CNN
F 1 "D_Schottky" H 5750 1074 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 5750 1200 50  0001 C CNN
F 3 "~" H 5750 1200 50  0001 C CNN
	1    5750 1200
	-1   0    0    1   
$EndComp
Connection ~ 5400 1200
Wire Notes Line width 20 style dash_dot rgb(194, 7, 1)
	3450 3450 550  3450
$Comp
L Connector:Barrel_Jack J3
U 1 1 61D1122D
P 6500 2600
F 0 "J3" V 6511 2788 50  0000 L CNN
F 1 "Barrel_Jack" V 6602 2788 50  0000 L CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 6550 2560 50  0001 C CNN
F 3 "~" H 6550 2560 50  0001 C CNN
	1    6500 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	5900 1200 5950 1200
Connection ~ 5950 1200
$Comp
L power:+9V #PWR0105
U 1 1 61D1A076
P 6600 3050
F 0 "#PWR0105" H 6600 2900 50  0001 C CNN
F 1 "+9V" H 6615 3223 50  0000 C CNN
F 2 "" H 6600 3050 50  0001 C CNN
F 3 "" H 6600 3050 50  0001 C CNN
	1    6600 3050
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 61D1A6D7
P 6400 3050
F 0 "#PWR0106" H 6400 2800 50  0001 C CNN
F 1 "GND" H 6405 2877 50  0000 C CNN
F 2 "" H 6400 3050 50  0001 C CNN
F 3 "" H 6400 3050 50  0001 C CNN
	1    6400 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 2900 6600 3050
Wire Wire Line
	6400 2900 6400 3050
Wire Wire Line
	5400 2000 6300 2000
Wire Wire Line
	5400 1200 5600 1200
Wire Notes Line width 20 style dash_dot rgb(194, 11, 0)
	3450 3450 7650 3450
$Comp
L power:GND #PWR0102
U 1 1 616D7EA0
P 1250 3050
F 0 "#PWR0102" H 1250 2800 50  0001 C CNN
F 1 "GND" H 1255 2877 50  0000 C CNN
F 2 "" H 1250 3050 50  0001 C CNN
F 3 "" H 1250 3050 50  0001 C CNN
	1    1250 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 3150 1350 3150
Text GLabel 1200 3150 0    50   Input ~ 0
5V
Wire Wire Line
	1150 1850 1350 1850
Text GLabel 1150 1850 0    50   Output ~ 0
3V3
$Comp
L Arduino-nano-33:Arduino-NANO-33 J1
U 1 1 6140B0DA
P 1850 2450
F 0 "J1" H 1850 3515 50  0000 C CNN
F 1 "Arduino-NANO-33" H 1850 3424 50  0000 C CNN
F 2 "Nano_33:NANO_33_Socket_Castell" H 1525 2350 50  0001 C CNN
F 3 "~" H 1525 2350 50  0001 C CNN
	1    1850 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2400 4600 2500
Connection ~ 4600 2500
Wire Wire Line
	4600 2500 4600 2600
Connection ~ 4600 2600
Wire Wire Line
	4600 2600 4600 2700
Connection ~ 4600 2700
Wire Wire Line
	4600 2700 4600 2800
Connection ~ 4600 2800
Connection ~ 4600 2900
Wire Wire Line
	4600 2900 4600 3000
Connection ~ 4600 3000
Wire Wire Line
	4600 3000 4600 3100
Connection ~ 4600 3100
Wire Wire Line
	4600 3100 4600 3200
Connection ~ 4600 3200
Wire Wire Line
	4600 3200 4600 3300
$Comp
L power:GND #PWR0107
U 1 1 61D97016
P 4800 3100
F 0 "#PWR0107" H 4800 2850 50  0001 C CNN
F 1 "GND" H 4805 2927 50  0000 C CNN
F 2 "" H 4800 3100 50  0001 C CNN
F 3 "" H 4800 3100 50  0001 C CNN
	1    4800 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2800 4600 2900
$Comp
L Device:R 1e1
U 1 1 61D9A28A
P 4800 2650
F 0 "1e1" H 4870 2696 50  0000 L CNN
F 1 "R" H 4870 2605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4730 2650 50  0001 C CNN
F 3 "~" H 4800 2650 50  0001 C CNN
	1    4800 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2500 4800 2500
Wire Wire Line
	4800 2800 4800 3100
Text GLabel 2550 2750 2    50   Input ~ 0
BAR_LED1
Text GLabel 2550 2650 2    50   Input ~ 0
BAR_LED2
Text GLabel 2550 2550 2    50   Input ~ 0
BAR_LED3
Text GLabel 2550 2450 2    50   Input ~ 0
BAR_LED4
Text GLabel 2550 2350 2    50   Input ~ 0
BAR_LED5
Text GLabel 2550 2250 2    50   Input ~ 0
BAR_LED6
Text GLabel 2550 2150 2    50   Input ~ 0
BAR_LED7
Text GLabel 2550 2050 2    50   Input ~ 0
BAR_LED8
Text GLabel 2550 1950 2    50   Input ~ 0
BAR_LED9
Text GLabel 2550 1850 2    50   Input ~ 0
BAR_LED10
Wire Wire Line
	2550 1850 2350 1850
Wire Wire Line
	2550 1950 2350 1950
Wire Wire Line
	2550 2050 2350 2050
Wire Wire Line
	2550 2150 2350 2150
Wire Wire Line
	2550 2250 2350 2250
Wire Wire Line
	2550 2350 2350 2350
Wire Wire Line
	2350 2450 2550 2450
Wire Wire Line
	2350 2550 2550 2550
Wire Wire Line
	2350 2650 2550 2650
Wire Wire Line
	2350 2750 2550 2750
Text GLabel 4000 2400 0    50   Input ~ 0
BAR_LED1
Text GLabel 4000 2500 0    50   Input ~ 0
BAR_LED2
Text GLabel 4000 2600 0    50   Input ~ 0
BAR_LED3
Text GLabel 4000 2700 0    50   Input ~ 0
BAR_LED4
Text GLabel 4000 2800 0    50   Input ~ 0
BAR_LED5
Text GLabel 4000 2900 0    50   Input ~ 0
BAR_LED6
Text GLabel 4000 3000 0    50   Input ~ 0
BAR_LED7
Text GLabel 4000 3100 0    50   Input ~ 0
BAR_LED8
Text GLabel 4000 3200 0    50   Input ~ 0
BAR_LED9
Text GLabel 4000 3300 0    50   Input ~ 0
BAR_LED10
Wire Wire Line
	4000 3300 4200 3300
Wire Wire Line
	4000 3200 4200 3200
Wire Wire Line
	4000 3100 4200 3100
Wire Wire Line
	4000 3000 4200 3000
Wire Wire Line
	4000 2900 4200 2900
Wire Wire Line
	4000 2800 4200 2800
Wire Wire Line
	4200 2700 4000 2700
Wire Wire Line
	4200 2600 4000 2600
Wire Wire Line
	4200 2500 4000 2500
Wire Wire Line
	4200 2400 4000 2400
Wire Notes Line width 20 style dash_dot rgb(194, 1, 0)
	3250 3450 3250 450 
Wire Notes Line width 20 style dash_dot rgb(194, 1, 0)
	5200 3450 5200 450 
Wire Notes Line width 20 style dash_dot rgb(194, 1, 0)
	7650 3450 7650 450 
$Comp
L Connector:Conn_01x04_Male MQ_Conn1
U 1 1 61CBB754
P 7900 1300
F 0 "MQ_Conn1" H 8008 1581 50  0000 C CNN
F 1 "Conn_01x04_Male" H 8008 1490 50  0000 C CNN
F 2 "MQ-sensor:MQ-3" H 7900 1300 50  0001 C CNN
F 3 "~" H 7900 1300 50  0001 C CNN
	1    7900 1300
	1    0    0    -1  
$EndComp
Text Notes 1550 850  0    50   ~ 0
Microcontroller
Text Notes 4050 700  0    50   ~ 0
UI Components
Text Notes 6200 700  0    50   ~ 0
Power Section
Text Notes 7750 600  0    50   ~ 0
MQ sensor
$EndSCHEMATC
