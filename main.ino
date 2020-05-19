// Declaration of Dependancies and Libraries
#include <AccelStepper.h> // Stepper Driver Library
#include <Servo.h> // Servo Library
#include <EEPROMex.h> // EEPROM Library - For Saving values


// Declaration of Pin outs

//Stepper Side
AccelStepper axis1(AccelStepper::FULL2WIRE, 40, 41); // Create stepper axis1
AccelStepper axis2(AccelStepper::FULL2WIRE, 42, 43); // Create stepper axis2
AccelStepper axis3(AccelStepper::FULL2WIRE, 44, 45); // Create stepper axis3
AccelStepper axis4(AccelStepper::FULL2WIRE, 46, 47); // Create stepper axis4
AccelStepper axis5(AccelStepper::FULL2WIRE, 48, 49); // Create stepper axis5
AccelStepper axis6(AccelStepper::FULL2WIRE, 50, 51); // Create stepper axis6

//Limit Switch Side
int limitAx1 = 39;
int limitAx2 = 38;
int limitAx3 = 37;
int limitAx4 = 36;
int limitAx5 = 35;
int limitAx6 = 34;

int limitAx1Val = 1;
int limitAx2Val = 1;
int limitAx3Val = 1;
int limitAx4Val = 1;
int limitAx5Val = 1;
int limitAx6Val = 1;

//Stepper Value Holder
int currentPosAx1 = 0;
int currentPosAx2 = 0;
int currentPosAx3 = 0;
int currentPosAx4 = 0;
int currentPosAx5 = 0;
int currentPosAx6 = 0;

Servo effector;  // create servo object to control a servo

// Declaration of Variables

// Declaration of Functions

void autoHoming()
{
    //Axis 1 Homing
    for (int i = 0; i < 360; i++)
    {
        //Read Current Position
        currentPosAx1 = axis1.currentPosition();
        //Run Stepper
        axis1.run();
        axis1.moveTo(currentPosAx1 - 1);

        //Run Until Limit Switch is Hit by the Stepper
        limitAx1Val = digitalRead(limitAx1);
        
        if(limitAx1Val == 0){
            i = 0;
            axis1.stop(); //Stop Running
            axis1.setCurrentPosition(0); //Reset the position to zero
            break;
        }
    }
     //Axis 2 Homing
    for (int i = 0; i < 360; i++)
    {
        //Read Current Position
        currentPosAx2 = axis2.currentPosition();
        //Run Stepper
        axis2.run();
        axis2.moveTo(currentPosAx2 - 1);

        //Run Until Limit Switch is Hit by the Stepper
        limitAx2Val = digitalRead(limitAx2);
        
        if(limitAx2Val == 0){
            i = 0;
            axis2.stop(); //Stop Running
            axis2.setCurrentPosition(0); //Reset the position to zero
            break;
        }
    }
        //Axis 3 Homing
    for (int i = 0; i < 360; i++)
    {
        //Read Current Position
        currentPosAx3 = axis3.currentPosition();
        //Run Stepper
        axis3.run();
        axis3.moveTo(currentPosAx3 - 1);

        //Run Until Limit Switch is Hit by the Stepper
        limitAx3Val = digitalRead(limitAx3);
        
        if(limitAx3Val == 0){
            i = 0;
            axis3.stop(); //Stop Running
            axis3.setCurrentPosition(0); //Reset the position to zero
            break;
        }
    }

     //Axis 4 Homing
    for (int i = 0; i < 360; i++)
    {
        //Read Current Position
        currentPosAx4 = axis4.currentPosition();
        //Run Stepper
        axis4.run();
        axis4.moveTo(currentPosAx4 - 1);

        //Run Until Limit Switch is Hit by the Stepper
        limitAx4Val = digitalRead(limitAx4);
        
        if(limitAx4Val == 0){
            i = 0;
            axis4.stop(); //Stop Running
            axis4.setCurrentPosition(0); //Reset the position to zero
            break;
        }
    }
    
     //Axis 5 Homing
    for (int i = 0; i < 360; i++)
    {
        //Read Current Position
        currentPosAx5 = axis5.currentPosition();
        //Run Stepper
        axis5.run();
        axis5.moveTo(currentPosAx5 - 1);

        //Run Until Limit Switch is Hit by the Stepper
        limitAx5Val = digitalRead(limitAx5);
        
        if(limitAx5Val == 0){
            i = 0;
            axis5.stop(); //Stop Running
            axis5.setCurrentPosition(0); //Reset the position to zero
            break;
        }
    }

     //Axis 6 Homing
    for (int i = 0; i < 360; i++)
    {
        //Read Current Position
        currentPosAx6 = axis6.currentPosition();
        //Run Stepper
        axis6.run();
        axis6.moveTo(currentPosAx6 - 1);

        //Run Until Limit Switch is Hit by the Stepper
        limitAx6Val = digitalRead(limitAx6);
        
        if(limitAx6Val == 0){
            i = 0;
            axis6.stop(); //Stop Running
            axis6.setCurrentPosition(0); //Reset the position to zero
            break;
        }
    }
    
}

void moveAxis1(){

}
void setup()
{
    //Attach Stepper 1 - Axis1
    axis1.setMaxSpeed(300.0);
    axis1.setAcceleration(100.0);

    //Attach Stepper 2 - Axis2
    axis2.setMaxSpeed(300.0);
    axis2.setAcceleration(100.0);

    //Attach Stepper 3 - Axis3
    axis3.setMaxSpeed(300.0);
    axis3.setAcceleration(100.0);

    //Attach Stepper 4 - Axis4
    axis4.setMaxSpeed(300.0);
    axis4.setAcceleration(100.0);

    //Attach Stepper 5 - Axis5
    axis5.setMaxSpeed(300.0);
    axis5.setAcceleration(100.0);

    //Attach Stepper 6 - Axis6
    axis6.setMaxSpeed(300.0);
    axis6.setAcceleration(100.0);

    //Attach Servo
    effector.attach(52);

    //Limit Switch
    pinMode(limitAx1, INPUT_PULLUP);
    pinMode(limitAx2, INPUT_PULLUP);
    pinMode(limitAx3, INPUT_PULLUP);
    pinMode(limitAx4, INPUT_PULLUP);
    pinMode(limitAx5, INPUT_PULLUP);
    pinMode(limitAx6, INPUT_PULLUP);

}

void loop()
{
    
}