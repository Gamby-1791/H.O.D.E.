EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:IOW56Paddle-cache
EELAYER 25 0
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
$Comp
L CONN_01X04 J3
U 1 1 60BA38B2
P 2200 2100
F 0 "J3" H 2200 2350 50  0000 C CNN
F 1 "CONN_01X04" V 2300 2100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 2200 2100 50  0001 C CNN
F 3 "" H 2200 2100 50  0001 C CNN
	1    2200 2100
	0    1    1    0   
$EndComp
$Comp
L CONN_02X13 J5
U 1 1 60BA3933
P 8250 3600
F 0 "J5" H 8250 4300 50  0000 C CNN
F 1 "CONN_02X13" V 8250 3600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x13_Pitch2.54mm" H 8250 2450 50  0001 C CNN
F 3 "" H 8250 2450 50  0001 C CNN
	1    8250 3600
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X13 J1
U 1 1 60BA3996
P 4150 3600
F 0 "J1" H 4150 4300 50  0000 C CNN
F 1 "CONN_02X13" V 4150 3600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x13_Pitch2.54mm" H 4150 2450 50  0001 C CNN
F 3 "" H 4150 2450 50  0001 C CNN
	1    4150 3600
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X20 J4
U 1 1 60BA39B7
P 6200 5850
F 0 "J4" H 6200 6900 50  0000 C CNN
F 1 "CONN_02X20" V 6200 5850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x20_Pitch2.54mm" H 6200 4900 50  0001 C CNN
F 3 "" H 6200 4900 50  0001 C CNN
	1    6200 5850
	0    1    1    0   
$EndComp
$Comp
L USB_B J2
U 1 1 60BA3A26
P 2150 1050
F 0 "J2" H 1950 1500 50  0000 L CNN
F 1 "USB_B" H 1950 1400 50  0000 L CNN
F 2 "Connectors:USB_B" H 2300 1000 50  0001 C CNN
F 3 "" H 2300 1000 50  0001 C CNN
	1    2150 1050
	0    1    1    0   
$EndComp
Text Notes 2410 2300 3    60   ~ 0
top right
Text Notes 2110 2300 3    60   ~ 0
top left
$Comp
L GND #PWR1
U 1 1 60BA4449
P 1650 2050
F 0 "#PWR1" H 1650 1800 50  0001 C CNN
F 1 "GND" H 1650 1900 50  0000 C CNN
F 2 "" H 1650 2050 50  0001 C CNN
F 3 "" H 1650 2050 50  0001 C CNN
	1    1650 2050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 60BA4610
P 7600 5700
F 0 "#PWR2" H 7600 5450 50  0001 C CNN
F 1 "GND" H 7600 5550 50  0000 C CNN
F 2 "" H 7600 5700 50  0001 C CNN
F 3 "" H 7600 5700 50  0001 C CNN
	1    7600 5700
	1    0    0    -1  
$EndComp
Text Notes 5150 350  0    60   ~ 0
skip P1.0, P1.1, P1.7, P1.5,\nP6.0 = ground to indicate low power device
$Comp
L GND #PWR3
U 1 1 60BA5D7B
P 9600 3100
F 0 "#PWR3" H 9600 2850 50  0001 C CNN
F 1 "GND" H 9600 2950 50  0000 C CNN
F 2 "" H 9600 3100 50  0001 C CNN
F 3 "" H 9600 3100 50  0001 C CNN
	1    9600 3100
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 60BD11C0
P 5000 2050
F 0 "R9" V 5080 2050 50  0000 C CNN
F 1 "R" V 5000 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 4930 2050 50  0001 C CNN
F 3 "" H 5000 2050 50  0001 C CNN
	1    5000 2050
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 60BD139D
P 5100 2550
F 0 "R10" V 5180 2550 50  0000 C CNN
F 1 "R" V 5100 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5030 2550 50  0001 C CNN
F 3 "" H 5100 2550 50  0001 C CNN
	1    5100 2550
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 60BD1413
P 5250 2050
F 0 "R11" V 5330 2050 50  0000 C CNN
F 1 "R" V 5250 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5180 2050 50  0001 C CNN
F 3 "" H 5250 2050 50  0001 C CNN
	1    5250 2050
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 60BD1419
P 5350 2550
F 0 "R12" V 5430 2550 50  0000 C CNN
F 1 "R" V 5350 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5280 2550 50  0001 C CNN
F 3 "" H 5350 2550 50  0001 C CNN
	1    5350 2550
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 60BD154B
P 5550 2050
F 0 "R13" V 5630 2050 50  0000 C CNN
F 1 "R" V 5550 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5480 2050 50  0001 C CNN
F 3 "" H 5550 2050 50  0001 C CNN
	1    5550 2050
	1    0    0    -1  
$EndComp
$Comp
L R R14
U 1 1 60BD1551
P 5750 2550
F 0 "R14" V 5830 2550 50  0000 C CNN
F 1 "R" V 5750 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5680 2550 50  0001 C CNN
F 3 "" H 5750 2550 50  0001 C CNN
	1    5750 2550
	1    0    0    -1  
$EndComp
$Comp
L R R15
U 1 1 60BD1557
P 5950 2050
F 0 "R15" V 6030 2050 50  0000 C CNN
F 1 "R" V 5950 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5880 2050 50  0001 C CNN
F 3 "" H 5950 2050 50  0001 C CNN
	1    5950 2050
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 60BD155D
P 6150 2550
F 0 "R16" V 6230 2550 50  0000 C CNN
F 1 "R" V 6150 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6080 2550 50  0001 C CNN
F 3 "" H 6150 2550 50  0001 C CNN
	1    6150 2550
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 60BD1707
P 3100 2050
F 0 "R1" V 3180 2050 50  0000 C CNN
F 1 "R" V 3100 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3030 2050 50  0001 C CNN
F 3 "" H 3100 2050 50  0001 C CNN
	1    3100 2050
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 60BD170D
P 3200 2550
F 0 "R2" V 3280 2550 50  0000 C CNN
F 1 "R" V 3200 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3130 2550 50  0001 C CNN
F 3 "" H 3200 2550 50  0001 C CNN
	1    3200 2550
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 60BD1713
P 3300 2050
F 0 "R3" V 3380 2050 50  0000 C CNN
F 1 "R" V 3300 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3230 2050 50  0001 C CNN
F 3 "" H 3300 2050 50  0001 C CNN
	1    3300 2050
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 60BD1719
P 3400 2550
F 0 "R4" V 3480 2550 50  0000 C CNN
F 1 "R" V 3400 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3330 2550 50  0001 C CNN
F 3 "" H 3400 2550 50  0001 C CNN
	1    3400 2550
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 60BD171F
P 3500 2050
F 0 "R5" V 3580 2050 50  0000 C CNN
F 1 "R" V 3500 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3430 2050 50  0001 C CNN
F 3 "" H 3500 2050 50  0001 C CNN
	1    3500 2050
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 60BD1725
P 3600 2550
F 0 "R6" V 3680 2550 50  0000 C CNN
F 1 "R" V 3600 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3530 2550 50  0001 C CNN
F 3 "" H 3600 2550 50  0001 C CNN
	1    3600 2550
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 60BD172B
P 3700 2050
F 0 "R7" V 3780 2050 50  0000 C CNN
F 1 "R" V 3700 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3630 2050 50  0001 C CNN
F 3 "" H 3700 2050 50  0001 C CNN
	1    3700 2050
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 60BD1731
P 3800 2550
F 0 "R8" V 3880 2550 50  0000 C CNN
F 1 "R" V 3800 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3730 2550 50  0001 C CNN
F 3 "" H 3800 2550 50  0001 C CNN
	1    3800 2550
	1    0    0    -1  
$EndComp
$Comp
L R R25
U 1 1 60BD19EB
P 8600 2050
F 0 "R25" V 8680 2050 50  0000 C CNN
F 1 "R" V 8600 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 8530 2050 50  0001 C CNN
F 3 "" H 8600 2050 50  0001 C CNN
	1    8600 2050
	1    0    0    -1  
$EndComp
$Comp
L R R26
U 1 1 60BD19F1
P 8700 2550
F 0 "R26" V 8780 2550 50  0000 C CNN
F 1 "R" V 8700 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 8630 2550 50  0001 C CNN
F 3 "" H 8700 2550 50  0001 C CNN
	1    8700 2550
	1    0    0    -1  
$EndComp
$Comp
L R R27
U 1 1 60BD19F7
P 8800 2050
F 0 "R27" V 8880 2050 50  0000 C CNN
F 1 "R" V 8800 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 8730 2050 50  0001 C CNN
F 3 "" H 8800 2050 50  0001 C CNN
	1    8800 2050
	1    0    0    -1  
$EndComp
$Comp
L R R28
U 1 1 60BD19FD
P 8900 2550
F 0 "R28" V 8980 2550 50  0000 C CNN
F 1 "R" V 8900 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 8830 2550 50  0001 C CNN
F 3 "" H 8900 2550 50  0001 C CNN
	1    8900 2550
	1    0    0    -1  
$EndComp
$Comp
L R R29
U 1 1 60BD1A03
P 9000 2050
F 0 "R29" V 9080 2050 50  0000 C CNN
F 1 "R" V 9000 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 8930 2050 50  0001 C CNN
F 3 "" H 9000 2050 50  0001 C CNN
	1    9000 2050
	1    0    0    -1  
$EndComp
$Comp
L R R30
U 1 1 60BD1A09
P 9100 2550
F 0 "R30" V 9180 2550 50  0000 C CNN
F 1 "R" V 9100 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 9030 2550 50  0001 C CNN
F 3 "" H 9100 2550 50  0001 C CNN
	1    9100 2550
	1    0    0    -1  
$EndComp
$Comp
L R R31
U 1 1 60BD1A0F
P 9200 2050
F 0 "R31" V 9280 2050 50  0000 C CNN
F 1 "R" V 9200 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 9130 2050 50  0001 C CNN
F 3 "" H 9200 2050 50  0001 C CNN
	1    9200 2050
	1    0    0    -1  
$EndComp
$Comp
L R R32
U 1 1 60BD1A15
P 9300 2550
F 0 "R32" V 9380 2550 50  0000 C CNN
F 1 "R" V 9300 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 9230 2550 50  0001 C CNN
F 3 "" H 9300 2550 50  0001 C CNN
	1    9300 2550
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 60BD1A1B
P 6250 2050
F 0 "R17" V 6330 2050 50  0000 C CNN
F 1 "R" V 6250 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6180 2050 50  0001 C CNN
F 3 "" H 6250 2050 50  0001 C CNN
	1    6250 2050
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 60BD1A21
P 6450 2550
F 0 "R18" V 6530 2550 50  0000 C CNN
F 1 "R" V 6450 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6380 2550 50  0001 C CNN
F 3 "" H 6450 2550 50  0001 C CNN
	1    6450 2550
	1    0    0    -1  
$EndComp
$Comp
L R R19
U 1 1 60BD1A27
P 6650 2050
F 0 "R19" V 6730 2050 50  0000 C CNN
F 1 "R" V 6650 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6580 2050 50  0001 C CNN
F 3 "" H 6650 2050 50  0001 C CNN
	1    6650 2050
	1    0    0    -1  
$EndComp
$Comp
L R R20
U 1 1 60BD1A2D
P 6850 2550
F 0 "R20" V 6930 2550 50  0000 C CNN
F 1 "R" V 6850 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6780 2550 50  0001 C CNN
F 3 "" H 6850 2550 50  0001 C CNN
	1    6850 2550
	1    0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 60BD1A33
P 7050 2050
F 0 "R21" V 7130 2050 50  0000 C CNN
F 1 "R" V 7050 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 6980 2050 50  0001 C CNN
F 3 "" H 7050 2050 50  0001 C CNN
	1    7050 2050
	1    0    0    -1  
$EndComp
$Comp
L R R22
U 1 1 60BD1A39
P 7150 2550
F 0 "R22" V 7230 2550 50  0000 C CNN
F 1 "R" V 7150 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7080 2550 50  0001 C CNN
F 3 "" H 7150 2550 50  0001 C CNN
	1    7150 2550
	1    0    0    -1  
$EndComp
$Comp
L R R23
U 1 1 60BD1A3F
P 7300 2050
F 0 "R23" V 7380 2050 50  0000 C CNN
F 1 "R" V 7300 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7230 2050 50  0001 C CNN
F 3 "" H 7300 2050 50  0001 C CNN
	1    7300 2050
	1    0    0    -1  
$EndComp
$Comp
L R R24
U 1 1 60BD1A45
P 7400 2550
F 0 "R24" V 7480 2550 50  0000 C CNN
F 1 "R" V 7400 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 7330 2550 50  0001 C CNN
F 3 "" H 7400 2550 50  0001 C CNN
	1    7400 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 1350 2150 1900
Wire Wire Line
	2250 1900 2250 1600
Wire Wire Line
	2250 1600 2050 1600
Wire Wire Line
	2050 1600 2050 1350
Wire Wire Line
	1750 950  1650 950 
Wire Wire Line
	1650 950  1650 2050
Wire Wire Line
	1650 1800 2050 1800
Wire Wire Line
	2050 1800 2050 1900
Wire Wire Line
	1750 1050 1650 1050
Connection ~ 1650 1050
Wire Wire Line
	2350 1900 2350 1350
Connection ~ 1650 1800
Wire Wire Line
	6950 5550 6950 5600
Wire Wire Line
	6750 5550 6750 5600
Connection ~ 6950 5550
Wire Wire Line
	6550 5550 6550 5600
Connection ~ 6750 5550
Wire Wire Line
	6350 5550 6350 5600
Connection ~ 6550 5550
Wire Wire Line
	6050 5550 6050 5600
Connection ~ 6350 5550
Wire Wire Line
	5850 5550 5850 5600
Connection ~ 6050 5550
Wire Wire Line
	5650 5550 5650 5600
Connection ~ 5850 5550
Wire Wire Line
	5450 5550 5450 5600
Connection ~ 5650 5550
Wire Wire Line
	6250 2200 6250 5600
Wire Wire Line
	6250 3400 8000 3400
Wire Wire Line
	8000 3500 6450 3500
Wire Wire Line
	6450 2700 6450 5600
Wire Wire Line
	6650 2200 6650 5600
Wire Wire Line
	6650 3600 8000 3600
Wire Wire Line
	6850 2700 6850 5600
Wire Wire Line
	6850 3700 8000 3700
Wire Wire Line
	7050 2200 7050 5600
Wire Wire Line
	7050 3800 8000 3800
Wire Wire Line
	7150 2700 7150 5600
Wire Wire Line
	7150 3900 8000 3900
Wire Wire Line
	7150 6100 7150 6200
Wire Wire Line
	7150 6200 7300 6200
Wire Wire Line
	7300 6200 7300 2200
Wire Wire Line
	7300 4000 8000 4000
Wire Wire Line
	8000 4100 7400 4100
Wire Wire Line
	7400 2700 7400 6300
Wire Wire Line
	7400 6300 7050 6300
Wire Wire Line
	7050 6300 7050 6100
Wire Wire Line
	8500 4100 8600 4100
Wire Wire Line
	8600 2200 8600 6400
Wire Wire Line
	8600 6400 6950 6400
Wire Wire Line
	6950 6400 6950 6100
Wire Wire Line
	6850 6100 6850 6500
Wire Wire Line
	6850 6500 8700 6500
Wire Wire Line
	8700 6500 8700 2700
Wire Wire Line
	8700 4000 8500 4000
Wire Wire Line
	8500 3900 8800 3900
Wire Wire Line
	8800 2200 8800 6600
Wire Wire Line
	8800 6600 6750 6600
Wire Wire Line
	6750 6600 6750 6100
Wire Wire Line
	6650 6100 6650 6700
Wire Wire Line
	6650 6700 8900 6700
Wire Wire Line
	8900 6700 8900 2700
Wire Wire Line
	8900 3800 8500 3800
Wire Wire Line
	8500 3700 9000 3700
Wire Wire Line
	9000 2200 9000 6800
Wire Wire Line
	9000 6800 6550 6800
Wire Wire Line
	6550 6800 6550 6100
Wire Wire Line
	6450 6100 6450 6900
Wire Wire Line
	6450 6900 9100 6900
Wire Wire Line
	9100 6900 9100 2700
Wire Wire Line
	9100 3600 8500 3600
Wire Wire Line
	8500 3500 9200 3500
Wire Wire Line
	9200 2200 9200 7000
Wire Wire Line
	9200 7000 6350 7000
Wire Wire Line
	6350 7000 6350 6100
Wire Wire Line
	6250 6100 6250 7100
Wire Wire Line
	6250 7100 9300 7100
Wire Wire Line
	8500 3400 9300 3400
Wire Wire Line
	9300 7100 9300 2700
Wire Wire Line
	6150 2700 6150 5600
Wire Wire Line
	6150 3400 4400 3400
Wire Wire Line
	4400 3500 5950 3500
Wire Wire Line
	5950 2200 5950 5600
Wire Wire Line
	5750 2700 5750 5600
Wire Wire Line
	5750 3600 4400 3600
Wire Wire Line
	4400 3700 5550 3700
Wire Wire Line
	5550 2200 5550 5600
Wire Wire Line
	5350 2700 5350 5600
Wire Wire Line
	5350 3800 4400 3800
Wire Wire Line
	4400 3900 5250 3900
Wire Wire Line
	5250 2200 5250 5600
Wire Wire Line
	5250 6100 5250 6200
Wire Wire Line
	5250 6200 5100 6200
Wire Wire Line
	5100 6200 5100 2700
Wire Wire Line
	5100 4000 4400 4000
Wire Wire Line
	4400 4100 5000 4100
Wire Wire Line
	5000 2200 5000 6300
Wire Wire Line
	5000 6300 5350 6300
Wire Wire Line
	5350 6300 5350 6100
Wire Wire Line
	3900 4100 3800 4100
Wire Wire Line
	3800 2700 3800 6400
Wire Wire Line
	3800 6400 5450 6400
Wire Wire Line
	5450 6400 5450 6100
Wire Wire Line
	5550 6100 5550 6500
Wire Wire Line
	5550 6500 3700 6500
Wire Wire Line
	3700 6500 3700 2200
Wire Wire Line
	3700 4000 3900 4000
Wire Wire Line
	3900 3900 3600 3900
Wire Wire Line
	3600 2700 3600 6600
Wire Wire Line
	3600 6600 5650 6600
Wire Wire Line
	5650 6600 5650 6100
Wire Wire Line
	5750 6100 5750 6700
Wire Wire Line
	5750 6700 3500 6700
Wire Wire Line
	3500 6700 3500 2200
Wire Wire Line
	3500 3800 3900 3800
Wire Wire Line
	3900 3700 3400 3700
Wire Wire Line
	3400 2700 3400 6800
Wire Wire Line
	3400 6800 5850 6800
Wire Wire Line
	5850 6800 5850 6100
Wire Wire Line
	5950 6100 5950 6900
Wire Wire Line
	5950 6900 3300 6900
Wire Wire Line
	3300 6900 3300 2200
Wire Wire Line
	3300 3600 3900 3600
Wire Wire Line
	3900 3500 3200 3500
Wire Wire Line
	3200 2700 3200 7000
Wire Wire Line
	3200 7000 6050 7000
Wire Wire Line
	6050 7000 6050 6100
Wire Wire Line
	6150 6100 6150 7100
Wire Wire Line
	6150 7100 3100 7100
Wire Wire Line
	3100 7100 3100 2200
Wire Wire Line
	3100 3400 3900 3400
Wire Wire Line
	5450 5550 7600 5550
Wire Wire Line
	7600 5550 7600 5700
Wire Wire Line
	8500 3000 9600 3000
Wire Wire Line
	9600 3000 9600 3100
Wire Wire Line
	2350 1800 9200 1800
Wire Wire Line
	2700 2300 9300 2300
Wire Wire Line
	9300 2300 9300 2400
Connection ~ 2350 1800
Wire Wire Line
	9100 2400 9100 2300
Connection ~ 9100 2300
Wire Wire Line
	8900 2400 8900 2300
Connection ~ 8900 2300
Wire Wire Line
	8700 2400 8700 2300
Connection ~ 8700 2300
Wire Wire Line
	7400 2400 7400 2300
Connection ~ 7400 2300
Wire Wire Line
	7150 2400 7150 2300
Connection ~ 7150 2300
Wire Wire Line
	6850 2400 6850 2300
Connection ~ 6850 2300
Wire Wire Line
	6450 2400 6450 2300
Connection ~ 6450 2300
Wire Wire Line
	6150 2400 6150 2300
Connection ~ 6150 2300
Wire Wire Line
	5750 2400 5750 2300
Connection ~ 5750 2300
Wire Wire Line
	5350 2400 5350 2300
Connection ~ 5350 2300
Wire Wire Line
	5100 2400 5100 2300
Connection ~ 5100 2300
Wire Wire Line
	3800 2400 3800 2300
Connection ~ 3800 2300
Wire Wire Line
	3600 2400 3600 2300
Connection ~ 3600 2300
Wire Wire Line
	3400 2400 3400 2300
Connection ~ 3400 2300
Wire Wire Line
	3200 2400 3200 2300
Connection ~ 3200 2300
Wire Wire Line
	9200 1800 9200 1900
Connection ~ 2700 1800
Wire Wire Line
	9000 1900 9000 1800
Connection ~ 9000 1800
Wire Wire Line
	8800 1900 8800 1800
Connection ~ 8800 1800
Wire Wire Line
	8600 1900 8600 1800
Connection ~ 8600 1800
Wire Wire Line
	7300 1900 7300 1800
Connection ~ 7300 1800
Wire Wire Line
	7050 1900 7050 1800
Connection ~ 7050 1800
Wire Wire Line
	6650 1900 6650 1800
Connection ~ 6650 1800
Wire Wire Line
	6250 1900 6250 1800
Connection ~ 6250 1800
Wire Wire Line
	5950 1900 5950 1800
Connection ~ 5950 1800
Wire Wire Line
	5550 1900 5550 1800
Connection ~ 5550 1800
Wire Wire Line
	5250 1900 5250 1800
Connection ~ 5250 1800
Wire Wire Line
	5000 1900 5000 1800
Connection ~ 5000 1800
Wire Wire Line
	3700 1900 3700 1800
Connection ~ 3700 1800
Wire Wire Line
	3500 1900 3500 1800
Connection ~ 3500 1800
Wire Wire Line
	3300 1900 3300 1800
Connection ~ 3300 1800
Wire Wire Line
	3100 1900 3100 1800
Connection ~ 3100 1800
Connection ~ 9300 3400
Connection ~ 9200 3500
Connection ~ 9100 3600
Connection ~ 9000 3700
Connection ~ 8900 3800
Connection ~ 8800 3900
Connection ~ 8700 4000
Connection ~ 8600 4100
Connection ~ 7400 4100
Connection ~ 7300 4000
Connection ~ 7150 3900
Connection ~ 7050 3800
Connection ~ 6850 3700
Connection ~ 6650 3600
Connection ~ 6450 3500
Connection ~ 6250 3400
Connection ~ 6150 3400
Connection ~ 5950 3500
Connection ~ 5750 3600
Connection ~ 5550 3700
Connection ~ 5350 3800
Connection ~ 5250 3900
Connection ~ 5100 4000
Connection ~ 5000 4100
Connection ~ 3800 4100
Connection ~ 3700 4000
Connection ~ 3600 3900
Connection ~ 3500 3800
Connection ~ 3400 3700
Connection ~ 3300 3600
Connection ~ 3200 3500
Connection ~ 3100 3400
Wire Wire Line
	2700 2300 2700 1800
$EndSCHEMATC