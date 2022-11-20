#include <SoftwareSerial.h>

//Default: motors off
//all methods turn motors off after they're done executing.

//bluetooth pins
int rdx = 0;
int txd = 1;
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


/*
 * High level motor control
 * 
 */

/**
 * @brief Turns lMotors forward, rMotors backwards.
*/
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
//turns all left motors on. 
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

//turns all left motors off. 
static void lMotorsStop(){
    analogWrite(speedPinA, 0);
    digitalWrite(dirPin1A,LOW);
    digitalWrite(dirPin2A,LOW);
}
static void rMotorsForward(){
    analogWrite(speedPinB, 255);
    digitalWrite(dirPin1B,LOW); 
    digitalWrite(dirPin2B,HIGH);
}

static void rMotorsReverse(){
    analogWrite(speedPinB, 255);
    digitalWrite(dirPin1B,HIGH);
    digitalWrite(dirPin2B,LOW);
}

//I fucked up the wiring and forwards and backwards are switched,
//so im going to flip high and low up above^
// static void rMotorsForward(){
//     analogWrite(speedPinB, 255);
//     digitalWrite(dirPin1B,HIGH);
//     digitalWrite(dirPin2B,LOW);
// }

// static void rMotorsReverse(){
//     analogWrite(speedPinB, 255);
//     digitalWrite(dirPin1B,LOW);
//     digitalWrite(dirPin2B,HIGH);
// }

//Turns off all motors on the right.
static void rMotorsStop(){
    analogWrite(speedPinB, 0);
    digitalWrite(dirPin1B,LOW);
    digitalWrite(dirPin2B,LOW);
}


/**
 * @brief Waits 1 second. 
 * 
 */
static void wait1(){
    unsigned long currentTime = millis();
    while((millis()-currentTime) < 1000){
        continue;
    }
}

/**
 * @brief Waits 1 second. 
 * 
 * @param currentTime 
 *      the last time check in the program, in miliseconds.
 */
static void wait1(unsigned long currentTime){
    currentTime = millis();
    while((millis()-currentTime) < 1000){
        continue;
    }
}


/*
*Motor testing
*/

static void motorTestLeft(){
   
    lMotorsForward();
    wait1();
    lMotorsStop();

    currentTime = millis();
    lMotorsReverse();
    wait1();
    lMotorsStop();
}

static void motorTestRight(){
    unsigned long currentTime = millis();
    rMotorsForward();
    wait1();
    rMotorsStop();

    currentTime = millis();
    rMotorsReverse();
    wait1();
    rMotorsStop();
}

static void FBRL(){
    unsigned long currentTime = millis();
    forward();
    wait1(currentTime);
    stop();

    backward();
    wait1(currentTime);
    stop();

    turnRight();
    wait1(currentTime);
    stop();

    turnLeft();
    wait1(currentTime);
    stop();
}




void loop(){

    /*
    *Testing
    */

    /*
    *Low level motor testing
    */
    // motorTestLeft();
    // motorTestRight();

    /*
    *High level motor testing
    */
    FBRL();


    /*
    *Actual code
    */
    
}