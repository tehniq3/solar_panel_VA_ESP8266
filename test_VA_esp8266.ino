/*
Measuring Current Using ACS712
http://henrysbench.capnfatz.com/henrys-bench/arduino-current-measurements/the-acs712-current-sensor-with-an-arduino/
DC Voltmeter Using a Voltage Divider Based on Code Created By T.K.Hareendran
http://henrysbench.capnfatz.com/henrys-bench/arduino-voltage-measurements/arduino-25v-voltage-sensor-module-user-manual/
adapt for ESP8266 board (A0 max 3.3V) by Nicu FLORICA
http://www.arduinotehniq.com
*/

#define pintensiune D7 // pin for control voltage
#define pincurent D6 //  pin for control current
#define analogIn A0 // ADC 

int mVperAmp = 185; // use 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int RawValue1= 0;

int ACSoffset = 2500; 
double Voltage = 0;
double Voltage2 = 0;
double Voltage1 = 0;
double Voltage3 = 0;


double Amps = 0;
// V+ ---|==3k3==|---A0---|==1k1==|-----GND  // voltage divider for ACS712
float R3 = 1.1;
float R4 = 3.34;

// V+ ---|==43k==|---A0---|==1k1==|-----GND // voltage divider
float R1 = 1.1; //  
float R2 = 43.; // 
float Vref = 3300;  // equivalent reference voltage

void setup(){ 
Serial.begin(9600);

pinMode(pintensiune, OUTPUT);
pinMode(pincurent, OUTPUT);
digitalWrite(pintensiune, LOW);
digitalWrite(pincurent, LOW); 
}

void loop(){

 digitalWrite(pincurent, HIGH);  // actiVate chanel for measure current
 delay(100);
 RawValue = analogRead(analogIn);
 Voltage = (RawValue / 1024.0) * Vref; // Gets you mV
 Voltage2 = (R3+R4)/R3 * Voltage;
 Amps = ((Voltage2 - ACSoffset) / mVperAmp);
 digitalWrite(pincurent, LOW);  // deactiVate chanel for measure current

 Serial.print("Raw Value = " ); // shows pre-scaled value 
 Serial.print(RawValue); 
 Serial.print("\t mV = "); // shows the voltage measured 
 Serial.print(Voltage,3); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("\t mV = "); // shows the voltage measured 
 Serial.print(Voltage2,3); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("\t Amps = "); // shows the voltage measured 
 Serial.println(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point

 digitalWrite(pintensiune, HIGH);  // actiVate chanel for measure current
 delay(100);
 RawValue1 = analogRead(analogIn);
 Voltage1 = (RawValue1 / 1024.0) * Vref; // Gets you mV
 Voltage3 = (R2+R1)/R1 * Voltage1;
 digitalWrite(pintensiune, LOW);  // deactiVate chanel for measure current

 Serial.print("Raw Value1 = " ); // shows pre-scaled value 
 Serial.print(RawValue1); 
 Serial.print("\t mV = "); // shows the voltage measured 
 Serial.print(Voltage1,3); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("\t mV = "); // shows the voltage measured 
 Serial.println(Voltage3,3); // the '3' after voltage allows you to display 3 digits after decimal point

 delay(500); 
 
}
