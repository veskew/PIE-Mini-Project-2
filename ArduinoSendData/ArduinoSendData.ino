
//      ******************************************************************
//      *                                                                *
//      *     Example Arduino program that transmits data to a laptop    *
//      *                                                                *
//      ******************************************************************

#include <Servo.h>
int servoX = 13;   // Declare the X servo pin
int servoY = 12; // Declare the Y servo pin
Servo ServoX;        // Create a servo object 
Servo ServoY;
int sensorPin=A0;    // Declare the pins for the sensor input and output
float distance;       // The distance measurements from the sensor
float sensorInput;       // The time it takes for the sensor to recieve the signal it sends
int(offTime);
int degX;
int degY;
int degChange = 20;


//
// setup function to initialize hardware and software
//
void setup()
{ 
  //
  // start the serial port
  //
  long baudRate = 9600;       // NOTE1: The baudRate for sending & receiving programs must match
  Serial.begin(baudRate);     // NOTE2: Set the baudRate to 115200 for faster communication

  ServoX.attach(servoX);
  ServoY.attach(servoY);
  Serial.begin(9600);
}



//
// main loop
//

void loop()
{
  
  for (degX = 0; degX<= 180; degX = degX + degChange)
  {
  ServoX.write(degX); // Make servo go to 0 degrees 
  ServoY.write(0);
  delay(100);
  	for (degY = 0; degY<= 180; degY = degY + degChange)
    {
      ServoY.write(degY); // Make servo go to 0 degrees 
      read();
      delay(100);
    }
    
  
  delay(100);
  }
   delay(offTime);
}



void read()
{
  sensorInput=analogRead(sensorPin);
  distance=sensorInput;
  // debug();
  csv();
  delay(100);
}
void csv()
{
  // Code to print sensor values as they would be seen in a csv
  Serial.print("\n");
  Serial.print(distance);
  Serial.print(",");
  Serial.print(degX);
  Serial.print(",");
  Serial.print(degY);
}
void debug()
{
  // Code to print sensor values with units
  Serial.print("\n Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  
  Serial.print(" | X: ");
  Serial.print(degX);
  Serial.print(" degrees");
  
  Serial.print(" | Y: ");
  Serial.print(degY);
  Serial.print(" degrees");
}