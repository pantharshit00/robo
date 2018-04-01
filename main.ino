// Sensor Pin vars
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  Serial.begin(9600);       // Starts the serial communication
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
  Serial.print("Distance: ");
  Serial.println(distance);
}