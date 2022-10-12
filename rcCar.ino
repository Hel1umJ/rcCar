//All motors are off by default. 


#include <SoftwareSerial.h>

//bluetooth pins
int rdx = 3;
int txd = 2;

//serial communication object
SoftwareSerial blueTooth(tdx,txd);

//rMotor pins
//ena
int speedPinA = 4;
//in1; (clockwise)
int dirPin1A = 5;
//in2; (counterClockwise)
int dirPin2A = 6;

//lMotor pins
//enb
int speedPinB = 8;
//in4; (clockwise)
int dirPin1B = 9;
//in5; (counterClockwise)
int dirPin2B = 10;

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

}

//High level motor control. 
void turnRight(){
    //lFront and lBack motors +1
    //rFront and rBack motors -1
}

void turnLeft(){
    //lFront and lBack motors -1
    //rFront and rBack motors +1
}

void forward(){
    //all motors +1
}

void backward(){
    //all motors -1
}


/*
*
*Low level motor control functions. 
*
*/
void lMotorsForward(){
    analogWrite(speedPinA, 255);
}
//turns off all motors on the left. 
void lMotorsStop(){

}

void rMotorsForward(){
    analogWrite(speedPinA, 255);
}

//Turns off all motors on the right.
void rMotorsStop(){

}
