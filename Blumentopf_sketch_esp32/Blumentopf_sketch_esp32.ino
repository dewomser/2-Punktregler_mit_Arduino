/*
  Analog input, analog output, digital output
 
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to test against eeprom  if true set  an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * buzzer connected from digital pin 9 to ground
 
 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe
 
  Code hacked by Stefan Höhn
  27.11.2020

 
 This example code is in the public domain.
 
 */
#include <EEPROM.h>
#define EEPROM_SIZE 1

int addr = 0;
int eeprom0;
int isdauer1;

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = 2;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Digital output pin that the buzzer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
String isdauer ="0";
int hysterese =5;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode (analogOutPin, OUTPUT);
  EEPROM.begin(EEPROM_SIZE);
  EEPROM.commit();
  inputString.reserve(200);
  
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out v  if (outputValue < inputString )
  eeprom0 = EEPROM.read(addr);
  EEPROM.commit();
  
 // if ( outputValue < isdauer.toInt() ) {
  if ( outputValue < eeprom0) {  
digitalWrite(analogOutPin, HIGH); }
  else if ( outputValue > isdauer.toInt()+ hysterese ) {
digitalWrite(analogOutPin, LOW); }
 // else {
// digitalWrite(analogOutPin, LOW); }
  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t output = ");
  Serial.print(outputValue); 
  Serial.print("\t eeprom = "); 
  Serial.println(eeprom0);
       
    

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading

// print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    isdauer=inputString;
    // clear the string:
    inputString = "";
    stringComplete = false;

// isdauer to eeprom
    isdauer1 =isdauer.toInt();
    int val = isdauer1;
    EEPROM.write(addr, val);
    EEPROM.commit();
  }
 
delay(1000);                   
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
