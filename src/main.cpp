#include <Arduino.h>
#include <ESP32Servo.h>


Servo myServo;
int val;
float valSmoth;
float valPrew;


void setup() {

  Serial.begin(115200);
  myServo.attach(GPIO_NUM_27);
  
  myServo.write(0);
  pinMode(GPIO_NUM_25,INPUT_PULLUP);

}

void loop() {
 
  int i=0;
  i++;
  
  Serial.println(i);

  val = digitalRead(GPIO_NUM_25);
  val=val*100;
  valSmoth = (val*0.07)+(valPrew*0.93);
  valPrew=valSmoth;
  Serial.print(">val:");
  Serial.println(val);
  Serial.print(">SmVal:");
  Serial.println(valSmoth);
 

  valSmoth=map(valSmoth,0,100,40,110);

  myServo.write(valSmoth);

  delay(10);
 

   
}