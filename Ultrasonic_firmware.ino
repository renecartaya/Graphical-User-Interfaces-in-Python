/* 
 *  Firmware for linear positioning system 
 *  
 *  Ultrasonic distance sensor module
 *  
 *  Author: René A. Cartaya López
 *
 *  Goal: Positioning of linear movement in XYZ positioning systems
 *
 */

#define echoPin 4 // attach pin digital 2 of Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin digital 3 of Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600);   // initialize serial communication at 9600 bits per second:
}

void loop() // the loop routine runs over and over again forever:
{
  digitalWrite(trigPin, LOW); // Clears the trigPin condition
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2; // Calculating the distance considering the speed of sound wave divided by 2 (go and back)

  String dataToSend = String(distance);
  Serial.println(dataToSend);  // print out the value you read:
  delay(300);        // delay in between reads for stability

  // data to be tested in Arduino serial monitor, can not be used at the same time of the Python GUI i.e. for test on Arduino IDE uncomment it and use the below commands, for Python GUI use, keep as it is

 // Serial.print("Distance: ");// Displays the distance on the Serial Monitor
 // Serial.print(distance);
 // Serial.println(" cm");
}
