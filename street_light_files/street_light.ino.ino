// Automatic Street Light System
// Components: Arduino UNO, LDR, Resistor, LED/Relay

int LDR_Pin = A0;      // LDR connected to Analog pin A0
int LED_Pin = 9;       // LED or Relay connected to Digital pin 9
int threshold = 500;   // Adjust this value based on your LDR readings

void setup() {
  pinMode(LED_Pin, OUTPUT);
  Serial.begin(9600);  // For debugging LDR values
}

void loop() {
  int ldrValue = analogRead(LDR_Pin);  // Read LDR value
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue < threshold) {
    // If it's dark → turn ON street light
    digitalWrite(LED_Pin, HIGH);
  } else {
    // If it's bright → turn OFF street light
    digitalWrite(LED_Pin, LOW);
  }

  delay(500);  // Small delay for stability
}
