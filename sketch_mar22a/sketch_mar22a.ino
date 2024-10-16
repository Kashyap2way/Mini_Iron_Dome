const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
float distance;
float angle;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
    angle = (atan(((distance / 2 - 1) / (distance * 0.866 + 1)))*180)/3.14;
  // Prints the distance on the Serial Monitor
  Serial.print("Angle Required & Distance: ");
  Serial.println(angle);
  Serial.println(distance);
}
