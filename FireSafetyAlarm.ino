#define SMOKE_SENSOR_AO 12  // Analog output connected to GPIO12 (D12)
#define FLAME_SENSOR_AO 14  // Analog output connected to GPIO14 (D14)

#define SMOKE_LIMIT 250     // Set the limit for smoke detection
#define FLAME_THRESHOLD 500 // Set the threshold value for fire detection

#define BEEPER_PIN 13       // Beeper connected to GPIO13 (D13)
#define RELAY_PIN 26        // Relay connected to GPIO26 (D26)

void setup() {
    Serial.begin(115200);  // Start Serial Communication

    pinMode(SMOKE_SENSOR_AO, INPUT);  // Set the AO pin as input for smoke sensor
    pinMode(FLAME_SENSOR_AO, INPUT);  // Set the AO pin as input for flame sensor

    pinMode(BEEPER_PIN, OUTPUT);  // Set the BEEPER pin as output
    pinMode(RELAY_PIN, OUTPUT);   // Set the RELAY pin as output

    digitalWrite(BEEPER_PIN, LOW);  // Make sure the beeper is off at the start
    digitalWrite(RELAY_PIN, LOW);   // Make sure the relay is off at the start
}

void loop() {
    // Read analog values from both sensors
    int smokeSensorValue = analogRead(SMOKE_SENSOR_AO);  // Read smoke sensor value
    int flameSensorValue = analogRead(FLAME_SENSOR_AO);  // Read flame sensor value

    // Print the analog values to Serial Monitor
    Serial.print("Smoke Sensor Value: ");
    Serial.println(smokeSensorValue);
    Serial.print("Flame Sensor Value: ");
    Serial.println(flameSensorValue);

    bool isSmokeDetected = smokeSensorValue > SMOKE_LIMIT; // Check for smoke detection
    bool isFireDetected = flameSensorValue < FLAME_THRESHOLD; // Check for fire detection

    // Check if smoke or fire is detected
    if (isSmokeDetected || isFireDetected) {
        Serial.println("SMOKE or FIRE DETECTED! 🔥");
        digitalWrite(BEEPER_PIN, HIGH);  // Turn ON Beeper
        digitalWrite(RELAY_PIN, HIGH);   // Turn ON Relay
    } else {
        Serial.println("No Smoke or Fire ❌");
        digitalWrite(BEEPER_PIN, LOW);   // Turn OFF Beeper
        digitalWrite(RELAY_PIN, LOW);    // Turn OFF Relay
    }

    delay(500);  // Wait for 500ms before the next reading
}
