// Declaration of Dependancies and Libraries
#include <AccelStepper.h> // Stepper Driver Library
#include <Servo.h> // Servo Library
#include <SoftwareSerial.h> //Serial for Bluetooth

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
String orientation = "";
int index = 0;

//Stepper Value Holder
int currentPosAx1 = 0;
int currentPosAx2 = 0;
int currentPosAx3 = 0;
int currentPosAx4 = 0;
int currentPosAx5 = 0;
int currentPosAx6 = 0;

int currentEffectorPos = 0;

//Stepper Pos Holder
int PosAx1 = 0;
int PosAx2 = 0;
int PosAx3 = 0;
int PosAx4 = 0;
int PosAx5 = 0;
int PosAx6 = 0;
int effectorPos = 0;

int axis1SP[50]; // Hold Values of axis1 Run Coordinates (Can hold 50)
int axis2SP[50]; // Hold Values of axis2 Run Coordinates (Can hold 50)
int axis3SP[50]; // Hold Values of axis3 Run Coordinates (Can hold 50)
int axis4SP[50]; // Hold Values of axis4 Run Coordinates (Can hold 50)
int axis5SP[50]; // Hold Values of axis5 Run Coordinates (Can hold 50)
int axis6SP[50]; // Hold Values of axis6 Run Coordinates (Can hold 50)
int effectorSP[50]; // Hold Values of Claw1 Run Coordinates (Can hold 50)

int speedDelay = 20; 

// Declaration of Functions

void autoHoming()
{
    //Axis 1 Homing
    for (int i = 0; i < 360; i++)
    {
        //Read Current Position
        currentPosAx1 = axis1.currentPosition();
        //Run Stepper
        
        axis1.moveTo(currentPosAx1 - 1);
        axis1.run();
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
        
        axis2.moveTo(currentPosAx2 - 1);
        axis2.run();
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
        
        axis3.moveTo(currentPosAx3 - 1);
        axis3.run();
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
        
        axis4.moveTo(currentPosAx4 - 1);
        axis4.run();
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
        
        axis5.moveTo(currentPosAx5 - 1);
        axis5.run();
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
        
        axis6.moveTo(currentPosAx6 - 1);
        axis6.run();
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

void checkOrientation(){
  while (orientation == "" )
  {
    if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.readString();  // Read the data as string
    if (dataIn = "wP") // check for wall orientation
    {
      orientation = "wallO";
    }
    else if (dataIn = "cP") // check for ceiling orientation
    {
      orientation = "ceilingO";
    }
    else //else stand orientation
    {
      orientation = "standO";
    }
    
    }
  }
}

void runToHomeOrientation(){
    if (orientation == "wallO")
    {
      axis1.runToNewPosition(180); //Insert Values from 0-360 eg: axis1.runToNewPosition(180);
      axis2.runToNewPosition(98); //Insert Values from 0-197 eg: axis1.runToNewPosition(180);
      axis3.runToNewPosition(90); //Insert Values from 0-180 eg: axis1.runToNewPosition(180);
      axis4.runToNewPosition(180); //Insert Values from 0-360 eg: axis1.runToNewPosition(180);
      axis5.runToNewPosition(107); //Insert Values from 0-215 eg: axis1.runToNewPosition(180);
      axis6.runToNewPosition(180); //Insert Values from 0-360 eg: axis1.runToNewPosition(180);
    }
    else if (orientation == "ceilingO")
    {
      axis1.runToNewPosition(180); //Insert Values from 0-360 eg: axis1.runToNewPosition(180);
      axis2.runToNewPosition(98); //Insert Values from 0-197 eg: axis1.runToNewPosition(180);
      axis3.runToNewPosition(90); //Insert Values from 0-180 eg: axis1.runToNewPosition(180);
      axis4.runToNewPosition(180); //Insert Values from 0-360 eg: axis1.runToNewPosition(180);
      axis5.runToNewPosition(107); //Insert Values from 0-215 eg: axis1.runToNewPosition(180);
      axis6.runToNewPosition(180); //Insert Values from 0-360 eg: axis1.runToNewPosition(180);
    }
    else
    {
      axis1.runToNewPosition(180); //Insert Values from 0-360 eg: axis1.runToNewPosition(180);
      axis2.runToNewPosition(98); //Insert Values from 0-197 eg: axis1.runToNewPosition(180);
      axis3.runToNewPosition(90); //Insert Values from 0-180 eg: axis1.runToNewPosition(180);
      axis4.runToNewPosition(180); //Insert Values from 0-360 eg: axis1.runToNewPosition(180);
      axis5.runToNewPosition(107); //Insert Values from 0-215 eg: axis1.runToNewPosition(180);
      axis6.runToNewPosition(180); //Insert Values from 0-360 eg: axis1.runToNewPosition(180);
    }
}
void setup()
{
    //Attach Stepper 1 - Axis1
    axis1.setMaxSpeed(300.0); // Set Speed of the stepper
    axis1.setAcceleration(100.0); // Set setAcceleration of the stepper

    //Attach Stepper 2 - Axis2
    axis2.setMaxSpeed(300.0); // Set Speed of the stepper
    axis2.setAcceleration(100.0); // Set setAcceleration of the stepper

    //Attach Stepper 3 - Axis3
    axis3.setMaxSpeed(300.0); // Set Speed of the stepper
    axis3.setAcceleration(100.0); // Set setAcceleration of the stepper

    //Attach Stepper 4 - Axis4
    axis4.setMaxSpeed(300.0); // Set Speed of the stepper
    axis4.setAcceleration(100.0); // Set setAcceleration of the stepper

    //Attach Stepper 5 - Axis5
    axis5.setMaxSpeed(300.0); // Set Speed of the stepper
    axis5.setAcceleration(100.0); // Set setAcceleration of the stepper

    //Attach Stepper 6 - Axis6
    axis6.setMaxSpeed(300.0); // Set Speed of the stepper
    axis6.setAcceleration(100.0); // Set setAcceleration of the stepper

    //Attach Servo
    effector.attach(52); // Attach Servo motor for claw

    //Limit Switch
    pinMode(limitAx1, INPUT_PULLUP); // Attach Homing Points
    pinMode(limitAx2, INPUT_PULLUP); // Attach Homing Points
    pinMode(limitAx3, INPUT_PULLUP); // Attach Homing Points
    pinMode(limitAx4, INPUT_PULLUP); // Attach Homing Points
    pinMode(limitAx5, INPUT_PULLUP); // Attach Homing Points
    pinMode(limitAx6, INPUT_PULLUP); // Attach Homing Points

    checkOrientation(); // Check Orientation from Bluetooth Device
    autoHoming(); // Determine 0 Coordinates on the axis
    runToHomeOrientation(); // Move to Home Position
}

void loop()
{
     if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.readString();  // Read the data as string
    
    // If "Waist" slider has changed value - Move Stepper 1 to position
    if (dataIn.startsWith("A1")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "A1120" to "120"
      PosAx1 = dataInS.toInt();  // Convert the string into integer
        axis1.runToNewPosition(PosAx1);
      currentPosAx1 = PosAx1;   // set current position as previous position
    }

    // If "Shoulder" slider has changed value - Move Stepper 2 to position
    if (dataIn.startsWith("A2")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "A2120" to "120"
      PosAx2 = dataInS.toInt();  // Convert the string into integer
        axis2.runToNewPosition(PosAx2);
      currentPosAx2 = PosAx2;   // set current position as previous position
    }

    // If "Elbow" slider has changed value - Move Stepper 3 to position
    if (dataIn.startsWith("A3")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "A3120" to "120"
      PosAx3 = dataInS.toInt();  // Convert the string into integer
        axis3.runToNewPosition(PosAx3);
      currentPosAx3 = PosAx3;   // set current position as previous position
    }
    
    // If "Wrist Rotation" slider has changed value - Move Stepper 4 to position
    if (dataIn.startsWith("A4")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "A4120" to "120"
      PosAx4 = dataInS.toInt();  // Convert the string into integer
        axis4.runToNewPosition(PosAx4);
      currentPosAx4 = PosAx4;   // set current position as previous position
    }

    // If "Wrist Vertical" slider has changed value - Move Stepper 5 to position
    if (dataIn.startsWith("A5")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "A5120" to "120"
      PosAx5 = dataInS.toInt();  // Convert the string into integer
        axis5.runToNewPosition(PosAx5);
      currentPosAx5 = PosAx5;   // set current position as previous position
    }

    // If "Arm Rotation" slider has changed value - Move Stepper 6 to position
    if (dataIn.startsWith("A6")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "A6120" to "120"
      PosAx6 = dataInS.toInt();  // Convert the string into integer
        axis6.runToNewPosition(PosAx6);
      currentPosAx6 = PosAx6;   // set current position as previous position
    }

    // Move CLAW 
    if (dataIn.startsWith("C1")) {
      String dataInS = dataIn.substring(2, dataIn.length()); // Extract only the number. E.g. from "C1120" to "120"
      effectorPos = dataInS.toInt();// Convert the string into integer
      if (currentEffectorPos > effectorPos) {
        for ( int j = currentEffectorPos; j >= effectorPos; j--) {
          effector.write(j);
          delay(30);
        }
      }
      if (currentEffectorPos < effectorPos) {
        for ( int j = currentEffectorPos; j <= effectorPos; j++) {
          effector.write(j);
          delay(30);
        }
      }
      currentEffectorPos = effectorPos; // set current position as previous position
    }
    // If button "SAVE" is pressed
    if (dataIn.startsWith("SAVE")) {
      axis1SP[index] = currentPosAx1;  // save position into the array
      axis2SP[index] = currentPosAx2;
      axis3SP[index] = currentPosAx3;
      axis4SP[index] = currentPosAx4;
      axis5SP[index] = currentPosAx5;
      axis6SP[index] = currentPosAx6;
      effectorSP[index] = effectorPos;
      index++;                        // Increase the array index
    }
    // If button "RUN" is pressed
    if (dataIn.startsWith("RUN")) {
      runRobot();  // Automatic mode - run the saved steps 
    }
    // If button "RESET" is pressed
    if ( dataIn == "RESET") {
      memset(axis1SP, 0, sizeof(axis1SP)); // Clear the array data to 0
      memset(axis2SP, 0, sizeof(axis2SP));
      memset(axis3SP, 0, sizeof(axis3SP));
      memset(axis4SP, 0, sizeof(axis4SP));
      memset(axis5SP, 0, sizeof(axis5SP));
      memset(axis6SP, 0, sizeof(axis6SP));
      memset(effectorSP, 0, sizeof(effectorSP));
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

      if (axis1SP[i] > axis1SP[i + 1]) {
          axis1.runToNewPosition(axis1SP[i]);  // Run Axis 1 it uses blocking Functions runToNewPosition: It moves to place before commiting to other commands
      }

      if (axis2SP[i] > axis2SP[i + 1]) {
          axis2.runToNewPosition(axis2SP[i]); // Run Axis 2 it uses blocking Functions runToNewPosition: It moves to place before commiting to other commands
      }

      if (axis3SP[i] > axis3SP[i + 1]) {
          axis3.runToNewPosition(axis3SP[i]); // Run Axis 3 it uses blocking Functions runToNewPosition: It moves to place before commiting to other commands
      }

      if (axis4SP[i] > axis4SP[i + 1]) {
          axis4.runToNewPosition(axis4SP[i]); // Run Axis 4 it uses blocking Functions runToNewPosition: It moves to place before commiting to other commands
      }

      if (axis5SP[i] > axis5SP[i + 1]) {
          axis5.runToNewPosition(axis5SP[i]); // Run Axis 5 it uses blocking Functions runToNewPosition: It moves to place before commiting to other commands
      }

      if (axis6SP[i] > axis6SP[i + 1]) {
          axis6.runToNewPosition(axis6SP[i]); // Run Axis 6 it uses blocking Functions runToNewPosition: It moves to place before commiting to other commands
      }

      // Claw 6
      if (effectorSP[i] == effectorSP[i + 1]) {
      }
      if (effectorSP[i] > effectorSP[i + 1]) {
        for ( int j = effectorSP[i]; j >= effectorSP[i + 1]; j--) {
          effector.write(j);
          delay(speedDelay);
        }
      }
      if (effectorSP[i] < effectorSP[i + 1]) {
        for ( int j = effectorSP[i]; j <= effectorSP[i + 1]; j++) {
           effector.write(j);
          delay(speedDelay);
        }
      }
      }
     }
    }
}