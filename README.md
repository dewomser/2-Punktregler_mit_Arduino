# 2-Punktregler_mit_Arduino
Arduinocode zur Blumentopffeuchteüberwachung, feste Hysterese , Schaltpunkt im EEPROM

Getestet mit Arduino Duemilanove

1. Analog Pin 0 ist für den Feuchtefühler 0-1023
2. Pin 9 ist für den Buzzer (Topf ist zu trocken)
3. Schaltpunkt kann über den seriellen Monitor jederzeit geändert werden. Wert von 0-255
6. Schaltpunkt wird ins EEPROM Addresse 0 geschrieben  
7. Hysterese ist im Programmcode fest an die Varianle "hysterese" gebunden

Viel Spass damit !
