# 2-Punktregler_mit_Arduino
[![TestCompile](https://github.com/dewomser/2-Punktregler_mit_Arduino/workflows/TestCompile/badge.svg)](https://github.com/dewomser/2-Punktregler_mit_Arduino/actions)

Arduinocode zur Blumentopffeuchteüberwachung, feste Hysterese , Schaltpunkt im EEPROM

Getestet mit Arduino Duemilanove

1. Analog Pin 0 ist für den Feuchtefühler 0-1023
2. Pin 9 ist für den Buzzer (Blumentopferde ist zu trocken)
3. Schaltpunkt kann über den seriellen Monitor jederzeit geändert werden. Wert von 0-255
6. Schaltpunkt wird ins EEPROM Addresse 0 geschrieben  
7. Hysterese ist im Programmcode fest an die Variable "hysterese" gebunden

Viel Spass damit !
