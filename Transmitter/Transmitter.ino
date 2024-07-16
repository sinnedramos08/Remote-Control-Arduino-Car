/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

//create a struct for the Data package


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(5, OUTPUT);

}

void loop() {
  struct Data_Package {
  int vry= analogRead(A1);
  int vrx= analogRead(A4);
  };

  Data_Package data; //create an instance of the data package

  
  radio.write(&data, sizeof(Data_Package));
  delay(5);
  Serial.print("transmitter vrx: ");
  Serial.print(data.vrx);
  Serial.print(" transmitter vry: ");
  Serial.println(data.vry);
}
