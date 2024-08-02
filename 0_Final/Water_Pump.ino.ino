// Constants
const int moistureSensorPin = A0;  // Pin for soil moisture sensor
const int motorPin = 9;            // Pin for DC motor control

// Thresholds
const int moistureThreshold = 100 ; // Adjust this value according to your soil moisture sensor readings
void setup() {
  Serial.begin(9600);M
  pinMode(moistureSensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Read the moisture level from the sensor
  int moistureLevel = analogRead(moistureSensorPin);
  // Print the moisture level to the serial monitor
  Serial.print("Moisture level: ");
  Serial.println(moistureLevel);

  // Check if the moisture level is below the threshold
  if (moistureLevel < moistureThreshold) {
    // Start the motor
    digitalWrite(motorPin, HIGH);
    Serial.println("Watering the plant...");
  } else {
    // Stop the motor
    Serial.println("Moisture level is sufficient.");
    digitalWrite(motorPin, LOW);
  }

  // Delay before next reading
  delay(1000);  // Adjust this delay based on your requirements
}
