// IMPORTANT DEAL WITH PIN NO CORRECTLY

// Sensor Pin vars
// Sensor code is for HR-04 I am assuming this is the correct model
const int trigPin = 9;
const int echoPin = 10;

//L293D
//Motor A
const int motorPin1 = 5; // Pin 14 of L293
const int motorPin2 = 6; // Pin 10 of L293
//Motor B
const int motorPin3 = 10; // Pin  7 of L293
const int motorPin4 = 9;  // Pin  2 of L293

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  //Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2; // Speed sound I am taking as 340 m/s Kartikeya give ino
  if (distance > 30)
  {
    startMotorClockwise();
  }
  else if (distance < 10)
  {
    startMotorsAntiClockwise();
  }
  else
  {
    stopMotors();
  }
  Serial.print("Distance: ");
  Serial.println(distance);
}

void startMotorClockwise()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void startMotorsAntiClockwise()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

void stopMotors()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}