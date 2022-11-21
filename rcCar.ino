#include <SoftwareSerial.h>

//Default: motors off
//all methods turn motors off after they're done executing.

//bluetooth pins (on module)
int rx = 1; //rx on module = tx on arduino
int tx = 0; //tx on module = rx on arduino
//serial communication object
SoftwareSerial blueTooth(rx,tx);

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

//declare pinmodes, initialize values. Setup: "the constructor of an arduino" 
//(it has the same functionality save for actually creating and returning an 
//object referece).
void setup(){
    //setup serial and softwareSerial to 9600 bps.
    Serial.begin(9600);
    blueTooth.begin(9600);
    //Motor pins setup
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
    //I fucked up the wiring and forwards and backwards are switched,
    //so im going to flip high and low up above^
    //analogWrite(speedPinB, 255);
    //digitalWrite(dirPin1B,HIGH);
    //digitalWrite(dirPin2B,LOW);
}
static void rMotorsReverse(){
    analogWrite(speedPinB, 255);
    digitalWrite(dirPin1B,HIGH);
    digitalWrite(dirPin2B,LOW);
    //I fucked up the wiring and forwards and backwards are switched,
    //so im going to flip high and low up above^
    //analogWrite(speedPinB, 255);
    //digitalWrite(dirPin1B,LOW);
    //digitalWrite(dirPin2B,HIGH);
}
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
*Serial Communication
*/
static void doAction(SoftwareSerial s){
    //0: stopped
    //1: forward
    //2: reverse
    //3: right
    //4: left
    int state = 0; 

    state = s.read();
    while(!state == 0){
        if(state == 1){
            //forward
        }else if(state = 2){
            //reverse
        }else if(state = 3){
            //right
        }else{
            //left
        }
        //If statement that checks if the action has changed (if the steram has anything else in it), and updates state accordingly. 
        int stateNext = s.read();
        if(!(stateNext == state)){

        }
    }
    
}


/*
*Motor testing
*/
static void motorTestLeft(){
    unsigned long currentTime = millis();
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

    reverse();
    wait1(currentTime);
    stop();

    turnRight();
    wait1(currentTime);
    stop();

    turnLeft();
    wait1(currentTime);
    stop();
}

/*
*Serial Communication testing
*/
static void testBlueToothIO(SoftwareSerial s){
    if(s.available()>0){
        char next = s.read();
        Serial.print(next);
    }else{
        Serial.println("Nothing in Stream");
        wait1();
        wait1();
    }
    
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
    //FBRL();

    /*
    *BlueTooth testing
    */
    // Serial.println("Hi");
    // wait1();

    testBlueToothIO(blueTooth);
    /*
    *Actual code
    */
    
     
}