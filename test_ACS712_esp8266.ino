/*
Measuring Current Using ACS712
http://henrysbench.capnfatz.com/henrys-bench/arduino-current-measurements/the-acs712-current-sensor-with-an-arduino/
adapt for ESP8266 board (A0 max 3.3V) by Nicu FLORICA
http://www.arduinotehniq.com
*/

const int analogIn = A0;
int mVperAmp = 185; // use 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 2500; 
double Voltage = 0;
double Voltage2 = 0;
double Amps = 0;

// V+ ---|==3k3==|---A0---|==1k1==|-----GND
float R3 = 1.1;
float R4 = 3.3;
float Vref = 3300;  // reference voltage

void setup(){ 
 Serial.begin(9600);
}

void loop(){
 
 RawValue = analogRead(analogIn);
 Voltage = (RawValue / 1024.0) * Vref; // Gets you mV
 Voltage2 = (R4+R3)/R3 * Voltage;
 Amps = ((Voltage2 - ACSoffset) / mVperAmp);
 
 Serial.print("Raw Value = " ); // shows pre-scaled value 
 Serial.print(RawValue); 
 Serial.print("\t mV = "); // shows the voltage measured 
 Serial.print(Voltage,3); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("\t mV = "); // shows the voltage measured 
 Serial.print(Voltage2,3); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("\t Amps = "); // shows the voltage measured 
 Serial.println(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point
 delay(500); 
 
}
