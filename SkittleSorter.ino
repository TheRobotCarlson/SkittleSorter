#include <Servo.h> 
/*
// TCS230 color recognition sensor 
// Sensor connection pins to Arduino are shown in comments

Color Sensor      Arduino
-----------      --------
 VCC               5V
 GND               GND
 s0                8
 s1                9
 s2                12
 s3                11
 OUT               10
 OE                GND
*/
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
   
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   

// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup()   
{  
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  myservo.attach(5);  // attaches the servo on pin 5 to the servo object 

  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);
myservo.write(91); 
}  
    
void loop() 
{  
  color(); 
  Serial.print("R: ");  
  Serial.print(red, DEC);  
  Serial.print(" G: ");  
  Serial.print(green, DEC);  
  Serial.print(" B: ");  
  Serial.print(blue, DEC);  
  //Serial.println();  

  if (red < blue && red < green && red < 20)
  {  
   Serial.println(" - (Red Color)");
   //myservo.write(1);   
  }  

  else if (blue < red && blue < green)   
  {  
   Serial.println(" - (Blue Color)"); 
  //myservo.write(3); 
  }  

  else if (green < red && green < blue)  
  {  
   Serial.println(" - (Green Color)"); 
  //myservo.write(2); 
  }  
  else{
  Serial.println();  
  }
    delay(3000);
  //myservo.write(0);
   
 }  
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
