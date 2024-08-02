// Sensor pins
#define sensorPower 7
#define sensorPin A0

void setup() {
	pinMode(sensorPower, OUTPUT);
	
	// in ideal state the the no power will be supplied to the sensoe will be zero
	digitalWrite(sensorPower, LOW);
	
	Serial.begin(9600);
}

void loop() {
	Serial.print("Analog output: ");
	Serial.println(readSensor());
	
	delay(1000);
}

//  This function gives the analog value of soil moisture measurement
int readSensor() {
	digitalWrite(sensorPower, HIGH);	// the HIGH keyword turns on the sensor
	delay(10);							// this delay is added in order to stabilize the reading of sensor
	int val = analogRead(sensorPin);	// Read the analog value form sensor
	digitalWrite(sensorPower, LOW);		// Turn the sensor OFF
	return val;							// Return analog moisture value
}