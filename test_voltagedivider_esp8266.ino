/*
DC Voltmeter Using a Voltage Divider
Based on Code Created By
T.K.Hareendran
http://henrysbench.capnfatz.com/henrys-bench/arduino-voltage-measurements/arduino-25v-voltage-sensor-module-user-manual/
adapt for ESP8266 board (A0 max 3.3V) by Nicu FLORICA
http://www.arduinotehniq.com
*/

int analogInput = A0;
float vout = 0.0;
float vin = 0.0;

// V+ ---|==43k==|---A0---|==1k1==|-----GND
float R1 = 1.1; //  
float R2 = 43.; // 
int value = 0;
float Vref = 3.3; 
void setup(){
   pinMode(analogInput, INPUT);
   Serial.begin(9600);
   Serial.print("DC VOLTMETER");
}
void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * Vref) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   
Serial.print("INPUT V= ");
Serial.println(vin,2);

delay(500);
}
