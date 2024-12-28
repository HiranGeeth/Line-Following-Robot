// Left Motor Ctrl pins
int leftmotorctrl1=2;
int leftmotorctrl2=9;

// Right Motor Ctrl pins
int rightmotorctrl1=7;
int rightmotorctrl2=8;

// EN(Enable) pins R,L order
int rightmotoren=3;
int leftmotoren=5;

// Define the number of sensors
const int NUM_SENSORS = 6;

// Define the threshold value for black white identification
const int THRESHOLD = 690
; // Adjust this value as needed

//Set maximum speed
int maxSpeed = 150;
//Set motor base speed pwm
int motorBaseSpeed = 100;

//Function end delay
int Fdelay = 5;

//Set speeds of the two motors and the speedadjust
int LMotorSpeed=0;
int RMotorSpeed=0;
int speedAdjust=0;

//Define variables for PID control
float P, I, D;
float error=0;
float previousError=0;
float Kp=0.0008;
float Kd=0.5;
float Ki=0.0008;

// Create an array to store sensor readings
int sensorValues[NUM_SENSORS];
// Create an array of IR weights
int sensorWeights[6]={-20,-10,-5,5,10,20};

//Declare the 6 types of input arrays Black=1,White=0
int forwardArray1[6]={0,0,1,1,1,0};
int forwardArray2[6]={0,1,1,1,0,0};
int forwardArray3[6]={0,0,1,1,0,0};
int forwardArray4[6]={0,0,0,1,1,0};
int forwardArray5[6]={0,1,1,0,0,0};
int forwardArray6[6]={0,1,1,1,1,0};
int leftArray1[6]   ={1,0,0,0,0,0};
int leftArray2[6]   ={1,1,0,0,0,0};
int leftArray3[6]   ={1,1,1,0,0,0};
int leftArray4[6]   ={1,1,1,1,0,0};
int leftArray5[6]   ={1,1,1,1,1,0};
int leftArray6[6]   ={0,1,0,0,0,0};
int rightArray1[6]  ={0,0,0,0,0,1};
int rightArray2[6]  ={0,0,0,0,1,1};
int rightArray3[6]  ={0,0,0,1,1,1};
int rightArray4[6]  ={0,0,1,1,1,1};
int rightArray5[6]  ={0,1,1,1,1,1};
int rightArray6[6]  ={0,0,0,0,1,0};
int stopArray[6]    ={1,1,1,1,1,1};
int reverseArray[6] ={0,0,0,0,0,0};

//Function to compare the sensorValues array with the forwardarray 1
bool checkForward1(int sensorValues[],int forwardArray1[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=forwardArray1[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the forwardarray 2
bool checkForward2(int sensorValues[],int forwardArray2[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=forwardArray2[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the forwardarray 3
bool checkForward3(int sensorValues[],int forwardArray3[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=forwardArray3[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the forwardarray 4
bool checkForward4(int sensorValues[],int forwardArray4[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=forwardArray4[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the forwardarray 5
bool checkForward5(int sensorValues[],int forwardArray5[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=forwardArray5[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the forwardarray 5
bool checkForward6(int sensorValues[],int forwardArray6[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=forwardArray6[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array1 to go left
bool checkLeft1(int sensorValues[],int leftArray1[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=leftArray1[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array2 to go left
bool checkLeft2(int sensorValues[],int leftArray2[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=leftArray2[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array 3 to go left
bool checkLeft3(int sensorValues[],int leftArray3[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=leftArray3[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array 4 to go left
bool checkLeft4(int sensorValues[],int leftArray4[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=leftArray4[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array 5 to go left
bool checkLeft5(int sensorValues[],int leftArray5[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=leftArray5[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array 5 to go left
bool checkLeft6(int sensorValues[],int leftArray6[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=leftArray6[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array1 to go right
bool checkRight1(int sensorValues[],int rightArray1[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=rightArray1[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array2 to go right
bool checkRight2(int sensorValues[],int rightArray2[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=rightArray2[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array 3 to go right
bool checkRight3(int sensorValues[],int rightArray3[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=rightArray3[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array 4 to go right
bool checkRight4(int sensorValues[],int rightArray4[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=rightArray4[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array 4 to go right
bool checkRight5(int sensorValues[],int rightArray5[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=rightArray5[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array 4 to go right
bool checkRight6(int sensorValues[],int rightArray6[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=rightArray6[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array to go stop
bool checkstop(int sensorValues[],int stopArray[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=stopArray[j])
      return false;
  return true;
}

//Function to compare the sensorValues array with the array to reverse
bool checkReverse(int sensorValues[],int stopArray[]){
  for (int j=0; j<6; j++)
  //Linearly compare elements
    if (sensorValues[j]!=reverseArray[j])
      return false;
  return true;
}


//Function for PID control
void PID_control() {

  error=0;
  for (int i=0; i<6;i++)
  {
    error += sensorWeights[i]*sensorValues[i];
  }
  P=error;
  I=I+error;
  D=error-previousError;
  
  previousError=error;
  
  speedAdjust = (Kp*P +Ki*I +Kd*D);

  LMotorSpeed = motorBaseSpeed - speedAdjust;
  RMotorSpeed = motorBaseSpeed + speedAdjust;

    if(LMotorSpeed<0)
  {
    LMotorSpeed=0;
  }
  if(RMotorSpeed<0)
  {
    RMotorSpeed=0;
  }
  if (LMotorSpeed > maxSpeed)
  {
    LMotorSpeed = maxSpeed;
  }
  if (RMotorSpeed > maxSpeed)
  {
    RMotorSpeed = maxSpeed;
  }
}

//Function to go straight
void goForward(){
  analogWrite(leftmotoren,LMotorSpeed);
  digitalWrite(leftmotorctrl1, HIGH);
  digitalWrite(leftmotorctrl2, LOW);
  analogWrite(rightmotoren,RMotorSpeed);
  digitalWrite(rightmotorctrl1, HIGH);
  digitalWrite(rightmotorctrl2, LOW);
  delay(Fdelay);
}

// Function to turn left
void turnLeft1(){
  digitalWrite(4, HIGH);
  digitalWrite(leftmotoren, LOW);
  analogWrite(rightmotoren,RMotorSpeed);
  digitalWrite(rightmotorctrl1, HIGH);
  digitalWrite(rightmotorctrl2, LOW);
  delay(Fdelay);
  digitalWrite(4, LOW);
  if (checkstop(sensorValues,stopArray))
      //Call function to stop
      {turnLeft2();}
}

//Function to turn left sharply
void turnLeft2 (){
  digitalWrite(4, HIGH);
  analogWrite(leftmotoren, LMotorSpeed);
  digitalWrite(leftmotorctrl1,LOW);
  digitalWrite(leftmotorctrl2,HIGH);
  analogWrite(rightmotoren,RMotorSpeed);
  digitalWrite(rightmotorctrl1, HIGH);
  digitalWrite(rightmotorctrl2, LOW);
  delay(Fdelay);
  digitalWrite(4, LOW);
  if (checkstop(sensorValues,stopArray))
      //Call function to stop
      {turnLeft2();}
}

// Function to turn right 
void turnRight1(){
  digitalWrite(6, HIGH);
  digitalWrite(rightmotoren, LOW);
  analogWrite(leftmotoren,LMotorSpeed);
  digitalWrite(leftmotorctrl1, HIGH);
  digitalWrite(leftmotorctrl2, LOW);
  delay(Fdelay);
  digitalWrite(6, LOW);
  if (checkstop(sensorValues,stopArray))
      //Call function to stop
      {turnRight2();}
}

// Function to turn right sharply
void turnRight2(){
  digitalWrite(6, HIGH);
  analogWrite(rightmotoren,RMotorSpeed);
  digitalWrite(rightmotorctrl1,LOW);
  digitalWrite(rightmotorctrl2,HIGH);
  analogWrite(leftmotoren,LMotorSpeed);
  digitalWrite(leftmotorctrl1, HIGH);
  digitalWrite(leftmotorctrl2, LOW);
  delay(Fdelay);
  digitalWrite(6, LOW);
  if (checkstop(sensorValues,stopArray))
      //Call function to turn
      {turnRight2();}
}

// Function to stop
void stopRobot(){
  digitalWrite(12, HIGH);
  digitalWrite(rightmotoren, LOW);
  digitalWrite(leftmotoren, LOW);
  delay(Fdelay);
  digitalWrite(12, LOW);
}

void goReverse(){
  digitalWrite(12, HIGH);
  analogWrite(leftmotoren,LMotorSpeed);
  digitalWrite(leftmotorctrl1, LOW);
  digitalWrite(leftmotorctrl2, HIGH);
  analogWrite(rightmotoren,RMotorSpeed);
  digitalWrite(rightmotorctrl1, LOW);
  digitalWrite(rightmotorctrl2, HIGH);
  delay(Fdelay);
  digitalWrite(12, LOW);
}

void setup() {
  // Set pin modes
  pinMode(leftmotorctrl1, OUTPUT);
  pinMode(leftmotorctrl2, OUTPUT);
  pinMode(rightmotorctrl1, OUTPUT);
  pinMode(rightmotorctrl2, OUTPUT);
  pinMode(rightmotoren, OUTPUT);
  pinMode(leftmotoren, OUTPUT);

 //Power up Sensor array 
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);

//Left LED
pinMode(4,OUTPUT);

//Right LED
pinMode(6,OUTPUT);

//Break LED
pinMode(12,OUTPUT);

//Enable pins active
digitalWrite(3, HIGH);
digitalWrite(5, HIGH);

}


//Convert the sensorValues array into an array with 0 and 1
//black = 1
void loop(){
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensorValues[i] = analogRead(A0 + i);
    }
    for (int i = 0; i < NUM_SENSORS; i++) {
        if (sensorValues[i] >= THRESHOLD) {
            sensorValues[i]=1;
        }
        else {
            sensorValues[i]=0;
        }
    }  
    //function call for PID control
    PID_control();
    //function call for comparing arrays
    if (checkForward1(sensorValues,forwardArray1))
      //Call function to goforward
      { goForward();}
    if (checkForward2(sensorValues,forwardArray2))
      //Call function to goforward
      { goForward();}
    if (checkForward3(sensorValues,forwardArray3))
      //Call function to goforward
      { goForward();}
    if (checkForward4(sensorValues,forwardArray4))
      //Call function to goforward
      { goForward();}
    if (checkForward5(sensorValues,forwardArray5))
      //Call function to goforward
      { goForward();}
    if (checkForward6(sensorValues,forwardArray6))
      //Call function to goforward
      { goForward();}
    if (checkLeft1(sensorValues,leftArray1))
     //Call function to turn left
      {turnLeft1();}
    if (checkLeft2(sensorValues,leftArray2))
      //Call function to turn left
      {turnLeft2();}
    if (checkLeft3(sensorValues,leftArray3))
      //Call function to turn left
      {turnLeft2();}
    if (checkLeft4(sensorValues,leftArray4))
      //Call function to turn left
      {turnLeft2();}
    if (checkLeft5(sensorValues,leftArray5))
      //Call function to turn left
      {turnLeft2();}
    if (checkLeft6(sensorValues,leftArray6))
      //Call function to turn left
      {turnLeft2();}
    if (checkRight1(sensorValues,rightArray1))
      //Call function to turn right
      {turnRight1();}
    if (checkRight2(sensorValues,rightArray2))
      //Call function to turn right
      {turnRight2();}
    if (checkRight3(sensorValues,rightArray3))
      //Call function to turn right
      {turnRight2();}
    if (checkRight4(sensorValues,rightArray4))
      //Call function to turn right
      {turnRight2();}
    if (checkRight5(sensorValues,rightArray5))
      //Call function to turn right
      {turnRight2();}
    if (checkRight6(sensorValues,rightArray6))
      //Call function to turn right
      {turnRight2();}
    if (checkstop(sensorValues,stopArray))
      //Call function to stop
      {stopRobot();}
    if (checkReverse(sensorValues,reverseArray))
      //Call function to reverse
      {goReverse();}

}