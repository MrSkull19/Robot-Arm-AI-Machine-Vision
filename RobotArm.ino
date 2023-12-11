#include "HUSKYLENS.h"
#include "Servo.h"

HUSKYLENS huskylens;

Servo rotation;
Servo servo1;
Servo servo2;
Servo claw;

int ID0 = 0; //not learned results. Grey result on HUSKYLENS screen
int ID1 = 1; //first learned results. colored result on HUSKYLENS screen
int ID2 = 2; //second learned results. colored result on HUSKYLENS screen

void printResult(HUSKYLENSResult result);

void setup() {

    rotation.attach(3);
    servo1.attach(5);
    servo2.attach(6);
    claw.attach(9);

    Serial.begin(9600);
    Wire.begin();
    while (!huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        delay(100);
    }

    //adding the product name to the designated tag
    huskylens.setCustomName("Apple", 1);
    huskylens.setCustomName("Carrot", 2);
   
    huskylens.writeAlgorithm(ALGORITHM_TAG_RECOGNITION);

    //moving the arm in the default position
    rotation.write(180);
    servo1.write(90);
    servo2.write(90);
    claw.write(90);
}

void loop() {
    if (!huskylens.request())   {Serial.println("Fail to request objects from Huskylens!");}
    else
    { 
        HUSKYLENSResult result = huskylens.read();
        
        if (result.ID== ID1 )
          {Serial.println("aloooo");
          delay(1000);
          rotation.write(90);
          }
         if (result.ID == ID2)
          {Serial.println("qwwwwwwwwwwwe");
          delay(1000);
          rotation.write(180);
          }
    }
}



void stock(){

int apple=3, carrot=5, potato=2;



}