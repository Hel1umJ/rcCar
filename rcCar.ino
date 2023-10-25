#include <SoftwareSerial.h>

//Default: motors off

//bluetooth pins
int rdx = 3;
int txd = 2;
//serial communication object
SoftwareSerial blueTooth(rdx,txd);

//rMotor pins
//ena
int speedPinA = 2;
//in1; (clockwise)
int dirPin1A = 3;
//in2; (counterClockwise)
int dirPin2A = 4;

//lMotor pins
//enb
int speedPinB = 5;
//in4; (clockwise)
int dirPin1B = 6;
//in5; (counterClockwise)
int dirPin2B = 7;

//declare pinmodes, initialize values. Setup: "the constructor of an arduino" (it has the same functionality save for actually creating and returning an object referece).
void setup(){
    pinMode(speedPinA, OUTPUT);
    pinMode(dirPin1A, OUTPUT);
    pinMode(dirPin2A, OUTPUT);

    pinMode(speedPinB, OUTPUT);
    pinMode(dirPin1B, OUTPUT);
    pinMode(dirPin2B, OUTPUT);
}

void loop(){


    /*
    *Testing
    */
    //Testing time variable
    int currentTimeGlobal = millis();
    //rMotors F + B + S, lMotors F + B + S
    //PASSED
    // motorTestLeft();
    // motorTestRight();
    // currentTimeGlobal = millis();
    // while(millis()-currentTimeGlobal < 1000){
    //     continue;
    // }
    
    //Forward, stop, turn right, turn left, backwards.
    forward();
    currentTimeGlobal = millis();
    while(millis()-currentTimeGlobal < 1000){
        continue;
    }
    stop();
    currentTimeGlobal = millis();
    while(millis()-currentTimeGlobal < 1000){
        continue;
    }
    turnRight();
    currentTimeGlobal = millis();
    while(millis()-currentTimeGlobal < 1000){
        continue;
    }
    turnLeft();
    currentTimeGlobal = millis();
    while(millis()-currentTimeGlobal < 1000){
        continue;
    }
    reverse();
    currentTimeGlobal = millis();
    while(millis()-currentTimeGlobal < 1000){
        continue;
    }
    stop();

}

//High level motor control. 
static void turnRight(){
    lMotorsForward();
    rMotorsReverse();
}
static void turnLeft(){
    lMotorsReverse();
    rMotorsForward();
}

static void forward(){
    rMotorsForward();
    lMotorsForward();
}

static void reverse(){
    rMotorsReverse();
    lMotorsReverse();
}

static void stop(){
    rMotorsStop();
    lMotorsStop();
}


/*
*
*Low level motor control functions. 
*
*/
//turns on all motors on left.
static void lMotorsForward(){
    analogWrite(speedPinA, 255);
    digitalWrite(dirPin1A,HIGH);
    digitalWrite(dirPin2A,LOW);
}

static void lMotorsReverse(){
    analogWrite(speedPinA, 255);
    digitalWrite(dirPin1A,LOW);
    digitalWrite(dirPin2A,HIGH);
}

//turns off all motors on left. 
static void lMotorsStop(){
    analogWrite(speedPinA, 0);
    digitalWrite(dirPin1A,LOW);
    digitalWrite(dirPin2A,LOW);
}
 
static void rMotorsForward(){
    analogWrite(speedPinB, 255);
    digitalWrite(dirPin1B,HIGH);
    digitalWrite(dirPin2B,LOW);
}

static void rMotorsReverse(){
    analogWrite(speedPinB, 255);
    digitalWrite(dirPin1B,LOW);
    digitalWrite(dirPin2B,HIGH);
}

//Turns off all motors on the right.
static void rMotorsStop(){
    analogWrite(speedPinB, 0);
    digitalWrite(dirPin1B,LOW);
    digitalWrite(dirPin2B,LOW);
}



/*
*Motor testing
*/

static void motorTestLeft(){
    unsigned long currentTime = millis();
    lMotorsForward();
    while((millis()-currentTime) < 1000){
        continue;
    }
    currentTime = millis();
    lMotorsReverse();
    while(millis()-currentTime < 1000){
        continue;
    }
    lMotorsStop();
}

static void motorTestRight(){
    unsigned long currentTime = millis();
    rMotorsForward();
    while((millis()-currentTime) < 1001){
        continue;
    }

    currentTime = millis();
    rMotorsReverse();
    while(millis()-currentTime < 1001){
        continue;
    }
    rMotorsStop();
}

