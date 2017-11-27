#include "SBUS.h"
#include <Servo.h>
Servo s1,s2,s3,s4,s5,s6,s7,s8;
long L1,L2,L3,L4,L5,L6,L7,L8;
SBUS sbus(Serial2);// Serial in port

void setup()
{
  sbus.begin();
  Serial.begin(115200);
  pinMode(PC13, OUTPUT);//LED
  digitalWrite(PC13, LOW); //Pull Down LED
 
}

void loop()
{
  delay(2);
  printSBUSStatus();
  /* 
   PB1=1
   PB0=2
   PA7=3
   PA6=4
   PA3=5; RX1
   PA2=6; TX1
   PA1=7
   PA0=8
   */
  s1.attach(PB1);// S1 = Channel_1; PB1 = Pinout_1
  s2.attach(PB0);
  s3.attach(PA7);
  s4.attach(PA6);
  s5.attach(PA3);
  s6.attach(PA2);
  s7.attach(PA1);
  s8.attach(PA0);
  setServo();
  //Serial.println(sbus.getLostFrames());
  //Serial.println(sbus.getLostFrames());
}

void printSBUSStatus()
{ 
  sbus.process();
  //Serial.print("\n 1:");
  L1 = long(sbus.getNormalizedChannel(1));//Refer to SBUS.cpp
  //Serial.println(L1);
  //Serial.print(" 2:");
  L2 = long(sbus.getNormalizedChannel(2));
  // Serial.print(L2);
  //Serial.print(" 3:");
  L3 = long(sbus.getNormalizedChannel(3));
  //Serial.print(L3);
  //Serial.print(" 4:");
  L4 = long(sbus.getNormalizedChannel(4));
  //Serial.print(L4);
  L5 = long(sbus.getNormalizedChannel(5));//Refer to SBUS.cpp
  //Serial.println(L5);
  //Serial.print(" 5:");
  L6 = long(sbus.getNormalizedChannel(6));
  //Serial.print(L6);
  //Serial.print(" 6:");
  L7 = long(sbus.getNormalizedChannel(7));
  //Serial.print(L7);
  //Serial.print(" 7:");
  L8 = long(sbus.getNormalizedChannel(8));
  //Serial.print(L8);
  /*
  Serial.print("Ch9  ");
  Serial.println(sbus.getNormalizedChannel(9));
  Serial.print("Ch10 ");
  Serial.println(sbus.getNormalizedChannel(10));
  Serial.print("Ch11 ");
  Serial.println(sbus.getNormalizedChannel(11));
  Serial.print("Ch12 ");
  Serial.println(sbus.getNormalizedChannel(12));
  Serial.print("Ch13 ");
  Serial.println(sbus.getNormalizedChannel(13));
  Serial.print("Ch14 ");
  Serial.println(sbus.getNormalizedChannel(14));
  Serial.print("Ch15 ");
  Serial.println(sbus.getNormalizedChannel(15));
  Serial.print("Ch16 ");
  Serial.println(sbus.getNormalizedChannel(16));
  Serial.println();
  Serial.print("Failsafe: ");
  if (sbus.getFailsafeStatus() == SBUS_FAILSAFE_ACTIVE) {
    Serial.println("Active");
  }
  if (sbus.getFailsafeStatus() == SBUS_FAILSAFE_INACTIVE) {
    Serial.println("Not Active");
  }

  Serial.print("Data loss on connection: ");
  Serial.print(sbus.getFrameLoss());
  Serial.println("%");

  Serial.print("Frames: ");
  Serial.print(sbus.getGoodFrames());
  Serial.print(" / ");
  Serial.print(sbus.getLostFrames());
  Serial.print(" / ");
  Serial.println(sbus.getDecoderErrorFrames());

  Serial.print("Time diff: ");
  Serial.println((long)(millis() - sbus.getLastTime()));*/
}

void setServo()
{
  s1.write(map(L1, 989, 2012, 25, 120));//Servo 1 is connected to Long 1. Lowest is 989; Highest is 2012; Start/Stop positions
  s2.write(map(L2, 989, 2012, 25, 120));
  s3.write(map(L3, 989, 2012, 25, 120));
  s4.write(map(L4, 989, 2012, 25, 120));
  s5.write(map(L5, 989, 2012, 25, 120));
  s6.write(map(L6, 989, 2012, 25, 120));
  s7.write(map(L7, 989, 2012, 25, 120));
  s8.write(map(L8, 989, 2012, 25, 120));
}

