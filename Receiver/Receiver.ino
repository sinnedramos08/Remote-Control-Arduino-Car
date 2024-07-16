/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
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


//Setup Pins for L298N
int enA = 9;
int in1 = 2;
int in2 = 3;
int enB = 6;
int in3 = 4;
int in4 = 5;


//Set Motor Speed Initial Value
int MotorASpeed=0;
int MotorBSpeed=0;


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  //Set Pin Modes
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}

struct Data_Package {
  int vry= 0;
  int vrx= 0;
};
Data_Package data; //Create a variable with the above structure

//Set the tolerance for identifying the neutral/rest position
int tolerance = 50;
int ytolerance_lower=512-tolerance;
int ytolerance_upper=512+tolerance; 

int xtolerance_lower=519-tolerance;
int xtolerance_upper=519+tolerance; 

//Set minimum and maximum speed for each motor
int max_speedA=255;
int max_speedB=255;

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package)); // Read the whole data and store it into the 'data' structure
    
    //Move Forward and Backward
    //vry at neutral is 512, up joystick is 1023, down joystick is 0
    if (data.vry>ytolerance_upper){
      //Move Forward: input 1 is 5V, input 2 is GND
      //Set Motor A Forward
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      //Set Motor B Forward
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
  
      //Determine the motor speed based on the joystick position
      MotorBSpeed = map(data.vry, ytolerance_upper, 1023, 0, max_speedB);
      MotorASpeed = map(data.vry, ytolerance_upper, 1023, 0, 255);
      
    }

    else if (data.vry<ytolerance_lower){
      //Move Backward: input 1 is GND, input 2 is 5V
      //Set Motor A Backward
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      //Set Motor B Backward
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
  
      //Determine the motor speed based on the joystick position

      //Note, we need to reverse the reading of the joystick which is 512 for neutral, and 0 for full back
      //so we can map it to values 0 to 255
      //invert the values for vry for backwards, 0 becomes 482, 482 becomes 0
      int data_backward=data.vry-ytolerance_lower;
      data_backward=data_backward*-1;

      MotorBSpeed = map(data_backward, 0, ytolerance_lower, 0, max_speedB);
      MotorASpeed = map(data_backward, 0, ytolerance_lower, 0, 255);
      
    }
  
    else{
      

      //stop the motor 
      MotorBSpeed = 0;
      analogWrite(enB, 0);
      

      analogWrite(enA, 0);
      MotorASpeed = 0;
      
      }

    
    
    //Left and Right Control
    //vrx at neutral is 512, left joystick is 1023, right joystick is 0
    //Motor A:  left motor Motor B: right motor
    if (data.vrx>xtolerance_upper){
      //Move Left

      //Map the vrx position to a value of 255 max
      int data_left= map(data.vrx, xtolerance_upper, 1023, 0, 255);

      //Motor B (right motor) should speed up if steering to the left
      MotorBSpeed= MotorBSpeed + data_left;
      MotorASpeed= 90+ MotorASpeed - data_left;

      //if motor speed exceeds range 0 to 255
      if (MotorBSpeed > 255)MotorBSpeed = 255;
      if (MotorASpeed < 0)MotorASpeed = 0;

      
      
      }

    else if (data.vrx<xtolerance_lower){
      //Move Right

      //invert the data first
      int data_right = data.vrx-xtolerance_lower;
      data_right=data_right*-1;

      //map the data_right (ranges 0 to xtolerance_lower) to range 0 to 255
      data_right= map(data_right, 0, xtolerance_lower, 0, 255);

      //Motor A (Left motor) should speed up if steering to the right
      MotorASpeed= MotorASpeed + data_right;
      MotorBSpeed= 90+ MotorBSpeed - data_right; //add a tolerance of 90 speed if the joystick is position slanted

      //if motor speed exceeds range 0 to 255
      if (MotorASpeed > 255)MotorASpeed = 255;
      if (MotorBSpeed < 0)MotorBSpeed = 0;      
      }

    

    //Set the Motor Speed
    //Motor A: Left Motor, Motor B: Right Motor
    analogWrite(enA, MotorASpeed);
    

    analogWrite(enB, MotorBSpeed);
    
    
    Serial.print("Motor A Speed: ");
    Serial.print(MotorASpeed);
    
    Serial.print(" Motor B Speed: ");
    Serial.println(MotorBSpeed);
    
  }
  
}
