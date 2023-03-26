#include <Stepper.h>
const int stepsPerRevolution = 2000;
// change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


void setup(){
  // set the speed at 60 rpm:
  myStepper.setSpeed(6);

  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT_PULLUP);
  pinMode(A8,OUTPUT);
  Serial.begin(9600);
  digitalWrite(8, HIGH);
}

void loop(){
  int m= analogRead(A5);                         // Soil Moisture Sensor 1 PIN A0
  int n= analogRead(A6);                           // Soil Moisture Sensor 1 PIN A1
  Serial.println(m);
  delay(10);
  Serial.println(n);
  delay(200);  



  if (m>=980)
  {
        
    digitalWrite(A8, LOW);       // Relay ON
    delay(1000);

    // step one revolution in one direction:
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
    delay(500);
    // step one revolution in the other direction:
    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution);
    delay(500);
  }
  else if(m<=970) 
  {
    digitalWrite(A8, HIGH);      // Relay ON
  }

  if (n>=980)
  {      
    digitalWrite(A8, LOW);       // Relay ON
    delay(1000);
  }
  else if(n<=970)
  {
    digitalWrite(A8, HIGH);    // Relay OFF
  }
  else
  {
    digitalWrite(A8, HIGH);   // Relay OFF
  }

}


/* Stepper Motor Control */

/*#include <Stepper.h>
const int stepsPerRevolution = 2000;
// change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
   // set the speed at 60 rpm:
   myStepper.setSpeed(5);
   // initialize the serial port:
   Serial.begin(9600);
}

void loop() {
   // step one revolution in one direction:
   Serial.println("clockwise");
   myStepper.step(stepsPerRevolution);
   delay(500);
   // step one revolution in the other direction:
   Serial.println("counterclockwise");
   myStepper.step(-stepsPerRevolution);
   delay(500);
}*/
