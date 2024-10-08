
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
int distance;       // The distance measurements from the sensor
int sensorInput;       // The time it takes for the sensor to recieve the signal it sends
int(offTime);
int degX;
int degY;
int degChange = 2;


//
// setup function to initialize hardware and software
//
void setup()
{ 
  //
  // start the serial port
  //
  ServoX.attach(servoX);
  ServoY.attach(servoY);
  Serial.begin(9600);
}



//
// main loop
//

void loop()
{
  ServoX.write(0);
  ServoY.write(0);
  for (degX = 40; degX<= 180; degX = degX + degChange)
  {
  ServoX.write(degX); // Make servo go to 0 degrees 
  ServoY.write(0);
  delay(10);
    if (degX % 4 == 0){
  	for (degY = 10; degY<= 75; degY = degY + degChange)
    {
      ServoY.write(degY); // Make servo go to 0 degrees 
      read();
      delay(10);
    }
    }
    else{
    for (degY = 75; degY>= 10; degY = degY - degChange)
    {
      ServoY.write(degY); // Make servo go to 0 degrees 
      read();
      delay(10);
    }
    }
  
  delay(10);
  }
   delay(offTime);
}




void read()
{
  sensorInput=analogRead(sensorPin);
  distance=round(sensorInput);
  // debug();
  csv();
  delay(100);
}
void csv()
{
  // Code to print sensor values as they would be seen in a csv
  Serial.print(distance);
  Serial.print(",");
  Serial.print(degX);
  Serial.print(",");
  Serial.println(degY);

  delay(400);
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