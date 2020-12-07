// Pin number for the red led
const int redLedPin = 2;   // PD2
// Pin number for the green led
const int greenLedPin = 3; // PD3
// Delay between analog reads
const int delayMs = 100;

void setup() {
  // Use serial for debugging reasons
  Serial.begin(9600);

  // Set pin modes for digital pins
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // Read value from the analog pin
  int sensorValue = analogRead(A0);
  // Convert analog value to voltage
  float voltage = sensorValue * (5.0 / 1024.0);

  // Print some debug information
  Serial.print("sensorValue = ");
  Serial.print(sensorValue);
  Serial.print(" (");
  Serial.print(voltage);
  Serial.println(")");

  delay(delayMs);

  // If voltage is over 1, turn off red led and turn on green led
  if (voltage > 1) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  } else {
    // else turn on red led and turn off green led
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  }
}
