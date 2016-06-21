#include <Servo.h>

double x = 98;
double y = 72;

int buttonPin = 4;
int buttonState = 0;

int laserPin = 7;
long lastTime = 0;

int right = 3;
int left = 2;
int down = 1;
int up = 0;

Servo servoHR;
int servo1 = 5;

Servo servoLR;
int servo2 = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoLR.attach(servo1);
  servoHR.attach(servo2);
  
  pinMode(laserPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(right) == 0){
    if ( y < 103){  
      y += 0.1;
    }
  }else if(digitalRead(left) == 0){
    if ( y > 55){  
      y2.0. -= 0.1;
    }
  }else if(digitalRead(up) == 0){
    if ( x < 106){  
      x += 0.1;
    }
  }else if(digitalRead(down) == 0){
    if ( x > 82){  
      x -= 0.1;
    }
  }
  
  /*Serial.println(digitalRead(down));
  Serial.println("Runter\n");
  Serial.println(digitalRead(up));
  Serial.println("Hoch\n");
  Serial.println(digitalRead(left));
  Serial.println("Links\n");
  Serial.println(digitalRead(right));
  Serial.println("Rechts\n");
  
  Serial.println(y);
  Serial.println("Y\n");
  Serial.println(x);
  Serial.println("X\n");*/
  
  if (digitalRead(buttonPin) == 1){
    digitalWrite(laserPin, HIGH);
    lastTime = millis();
   // Serial.println("AN_BUTTON\n");
  }else if (digitalRead(buttonPin) == 0 && millis() - lastTime > 100) {
    digitalWrite(laserPin, LOW);
   // Serial.println("AUS_BUTTON\n");
  }
  
  servoHR.write(y);
  servoLR.write(x);
  delay(10);
}
