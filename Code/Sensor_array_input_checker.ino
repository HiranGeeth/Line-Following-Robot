// Define the number of sensors
const int NUM_SENSORS = 5;

void setup() {
    // Initialize Serial Monitor
    Serial.begin(9600);
    pinMode(10,OUTPUT);
    pinMode(13,OUTPUT);
    digitalWrite(10, HIGH);
    digitalWrite(13, HIGH);
    
    //Testing LEDS
    pinMode(4,OUTPUT);
    pinMode(6,OUTPUT);
    
    //Brake LED
    pinMode(12,OUTPUT);
    digitalWrite(12,HIGH);

    //Left LED
    digitalWrite(4, HIGH);
    //Right LED
    digitalWrite(6, HIGH);
}

void loop() {
    // Read sensor values and display them
    for (int i = 0; i < NUM_SENSORS; i++) {
        // Read sensor value
        int sensorValue = analogRead(A0 + i);

        // Display sensor value
        Serial.print("Sensor ");
        Serial.print(i + 1);
        Serial.print(" value: ");
        Serial.println(sensorValue);
    }

    // Delay before next iteration
    delay(1000);
}
