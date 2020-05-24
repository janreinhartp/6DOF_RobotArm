// Declaration of Dependancies and Libraries
#include <AccelStepper.h> // Stepper Driver Library
#include <Servo.h> // Servo Library
#include <EEPROMex.h> // EEPROM Library - For Saving values
#include <SoftwareSerial.h>

// Declaration of Pin outs

//Bluetooth Side
SoftwareSerial Bluetooth(0, 1); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)

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

Servo effector;  // create servo object to control a servo

// Declaration of Variables

//Bluetooth Side
String dataIn = "";

//Stepper Value Holder
int currentPosAx1 = 0;
int currentPosAx2 = 0;
int currentPosAx3 = 0;
int currentPosAx4 = 0;
int currentPosAx5 = 0;
int currentPosAx6 = 0;

//Stepper Pos Holder
int PosAx1 = 0;
int PosAx2 = 0;
int PosAx3 = 0;
int PosAx4 = 0;
int PosAx5 = 0;
int PosAx6 = 0;

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

void runAllAxis(){
    axis1.run();
    axis2.run();
    axis3.run();
    axis4.run();
    axis5.run();
    axis6.run();
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
     if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.readString();  // Read the data as string
    
    // If "Waist" slider has changed value - Move Stepper 1 to position
    if (dataIn.startsWith("a1")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "s1120" to "120"
      PosAx1 = dataInS.toInt();  // Convert the string into integer
        axis1.moveTo(PosAx1);
      currentPosAx1 = PosAx1;   // set current position as previous position
    }

    // If "Shoulder" slider has changed value - Move Stepper 2 to position
    if (dataIn.startsWith("a2")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "s1120" to "120"
      PosAx2 = dataInS.toInt();  // Convert the string into integer
        axis2.moveTo(PosAx2);
      currentPosAx2 = PosAx2;   // set current position as previous position
    }

    // If "Elbow" slider has changed value - Move Stepper 1 to position
    if (dataIn.startsWith("a3")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "s1120" to "120"
      PosAx3 = dataInS.toInt();  // Convert the string into integer
        axis3.moveTo(PosAx3);
      currentPosAx3 = PosAx3;   // set current position as previous position
    }
    
    // If "Wrist Rotation" slider has changed value - Move Stepper 1 to position
    if (dataIn.startsWith("a4")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "s1120" to "120"
      PosAx4 = dataInS.toInt();  // Convert the string into integer
        axis4.moveTo(PosAx4);
      currentPosAx4 = PosAx4;   // set current position as previous position
    }

    // If "Wrist Vertical" slider has changed value - Move Stepper 1 to position
    if (dataIn.startsWith("a5")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "s1120" to "120"
      PosAx5 = dataInS.toInt();  // Convert the string into integer
        axis5.moveTo(PosAx5);
      currentPosAx5 = PosAx5;   // set current position as previous position
    }

    // If "Arm Rotation" slider has changed value - Move Stepper 1 to position
    if (dataIn.startsWith("a6")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "s1120" to "120"
      PosAx6 = dataInS.toInt();  // Convert the string into integer
        axis6.moveTo(PosAx6);
      currentPosAx6 = PosAx6;   // set current position as previous position
    }

    // Move CLAW 
    if (dataIn.startsWith("c1")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo6Pos = dataInS.toInt();
      if (servo6PPos > servo6Pos) {
        for ( int j = servo6PPos; j >= servo6Pos; j--) {
          servo06.write(j);
          delay(30);
        }
      }
      if (servo6PPos < servo6Pos) {
        for ( int j = servo6PPos; j <= servo6Pos; j++) {
          servo06.write(j);
          delay(30);
        }
      }
      servo6PPos = servo6Pos; 
    }
    // If button "SAVE" is pressed
    if (dataIn.startsWith("SAVE")) {
      servo01SP[index] = servo1PPos;  // save position into the array
      servo02SP[index] = servo2PPos;
      servo03SP[index] = servo3PPos;
      servo04SP[index] = servo4PPos;
      servo05SP[index] = servo5PPos;
      servo06SP[index] = servo6PPos;
      index++;                        // Increase the array index
    }
    // If button "RUN" is pressed
    if (dataIn.startsWith("RUN")) {
      runservo();  // Automatic mode - run the saved steps 
    }
    // If button "RESET" is pressed
    if ( dataIn == "RESET") {
      memset(servo01SP, 0, sizeof(servo01SP)); // Clear the array data to 0
      memset(servo02SP, 0, sizeof(servo02SP));
      memset(servo03SP, 0, sizeof(servo03SP));
      memset(servo04SP, 0, sizeof(servo04SP));
      memset(servo05SP, 0, sizeof(servo05SP));
      memset(servo06SP, 0, sizeof(servo06SP));
      index = 0;  // Index to 0
    }
  }
}

void runRobot(){
    while (dataIn != "RESET") {   // Run the steps over and over again until "RESET" button is pressed
    for (int i = 0; i <= index - 2; i++) {  // Run through all steps(index)
      if (Bluetooth.available() > 0) {      // Check for incomding data
        dataIn = Bluetooth.readString();
        if ( dataIn == "PAUSE") {           // If button "PAUSE" is pressed
          while (dataIn != "RUN") {         // Wait until "RUN" is pressed again
            if (Bluetooth.available() > 0) {
              dataIn = Bluetooth.readString();
              if ( dataIn == "RESET") {     
                break;
              }
            }
          }
        }
        // If speed slider is changed
        if (dataIn.startsWith("ss")) {
          String dataInS = dataIn.substring(2, dataIn.length());
          speedDelay = dataInS.toInt(); // Change servo speed (delay time)
        }
      }
     }
    }
}