#include <SoftwareSerial.h> 
SoftwareSerial mySerial(2,3); //RX,TX 
int start=8; //sensor de inicio 
void setup()
{
  pinMode(start,INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  }
  void loop()
  {
    if(digitalRead(start)==HIGH)
    {
      mySerial.write('1');
      Serial.println("arranca");
      delay(15000);
      mySerial.write('R');
      }
      else
      {
        mySerial.write('0');
        Serial.println("nada");
        }
    }
