/*
 * Automated Fertilization System: Adaptive NPK Dispenser
 * Author: Alexis Cohen
 */

const int ValveN = 3; 
const int ValveP = 5; 
const int ValveK = 6; 

// Calibrated flow rate (ml/sec) - Update this after testing
const float flowrate = 1.0; 

void setup() { 
  pinMode(ValveN, OUTPUT); 
  pinMode(ValveP, OUTPUT); 
  pinMode(ValveK, OUTPUT); 
  
  Serial.begin(9600); 
  while (!Serial); 
  Serial.println("--- NPK Automated Dispenser Initialized ---");
  Serial.println("Enter NPK Ratio (Format: X-Y-Z):"); 
} 

void loop() { 
  if (Serial.available()) { 
    String input = Serial.readStringUntil('\n'); 
    input.trim(); 

    int dash1 = input.indexOf('-'); 
    int dash2 = input.lastIndexOf('-'); 

    if (dash1 == -1 || dash2 == -1) {
      Serial.println("Invalid Format. Use X-Y-Z");
      return;
    }

    int N = input.substring(0, dash1).toInt(); 
    int P = input.substring(dash1 + 1, dash2).toInt(); 
    int K = input.substring(dash2 + 1).toInt(); 

    Serial.println("Enter total target volume (ml):"); 
    while (!Serial.available()); 
    int volume = Serial.readStringUntil('\n').toInt(); 

    // Calculate pulse time in milliseconds
    int timeN = (int)(((float)N / 100.0) * volume / flowrate * 1000.0); 
    int timeP = (int)(((float)P / 100.0) * volume / flowrate * 1000.0); 
    int timeK = (int)(((float)K / 100.0) * volume / flowrate * 1000.0); 

    Serial.println("Dispensing Nutrients...");
    
    dispense(ValveN, timeN, "Nitrogen");
    dispense(ValveP, timeP, "Phosphorus");
    dispense(ValveK, timeK, "Potassium");

    float NPKvolume = ((float)(N + P + K) / 100.0) * volume; 
    float WaterVol = volume - NPKvolume; 

    Serial.println("Dispensing complete."); 
    Serial.print("Required Dilution: Add "); 
    Serial.print(WaterVol, 2); 
    Serial.println(" mL of Water to the container."); 
    Serial.println("\nEnter new ratio (X-Y-Z):");
  } 
} 

void dispense(int pin, int duration, String label) {
  if (duration > 0) {
    digitalWrite(pin, HIGH); 
    delay(duration); 
    digitalWrite(pin, LOW); 
  }
}
