void setup() {
  delay(8000); 
  Serial.begin(115200);
  delay(2000);
  Serial.println("COMPLETE ESP32 PIN TESTER");
  Serial.println("==============================");
}


int allPins[] = {5, 18, 19, 23};
int pinCount = sizeof(allPins) / sizeof(allPins[0]);

void loop() {
  Serial.println("\n📌 PIN STATES - Connect to GND to test:");
  Serial.println("======================================");
  
  int workingPins = 0;
  int brokenPins = 0;
  
  for(int i = 0; i < pinCount; i++) {
    int pin = allPins[i];
    
    // Skip pins that might cause issues
    if(pin == 0 || pin == 45 || pin == 46) {
      Serial.printf("Pin %2d: ⚠️  STRAPPING (Skip)\n", pin);
      continue;
    }
    
    pinMode(pin, INPUT_PULLUP);
    delay(1);
    int state = digitalRead(pin);
    
    Serial.printf("Pin %2d: ", pin);
    
    if(state == HIGH) {
      Serial.println("🔵 HIGH (touch to GND)");
    } else {
      Serial.println("🔴 LOW (working!)");
      workingPins++;
    }
  }
  
  Serial.println("======================================");
  Serial.printf("🎯 SUMMARY: %d working pins detected\n", workingPins);
  Serial.println("💡 INSTRUCTIONS:");
  Serial.println("   1. Connect each 🔵 pin to GND");
  Serial.println("   2. If it changes to 🔴 LOW = WORKING");
  Serial.println("   3. If no change = BROKEN");
  Serial.println("   4. Test one pin at a time");
  Serial.println("\nRefreshing in 5 seconds...");
  
  delay(5000);
}
