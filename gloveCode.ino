// Pin configuration (ESP32 ADC pins)
const int thumbPin  = 33;
const int indexPin  = 32;
const int middlePin = 35;
const int ringPin   = 34;
const int littlePin = 36;

// Thresholds (adjust after calibration)
int thumbThreshold  = 1000;
int indexThreshold  = 650;
int middleThreshold = 980;
int ringThreshold   = 900;
int littleThreshold = 900;

// ---- Detection functions ----
bool isThumbBent(int value)  { return (value > thumbThreshold);  }
bool isIndexBent(int value)  { return (value > indexThreshold);  }
bool isMiddleBent(int value) { return (value > middleThreshold); }
bool isRingBent(int value)   { return (value > ringThreshold);   }
bool isLittleBent(int value) { return (value > littleThreshold); }

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println("Finger Bend Detection Started...");
}

void loop() {
  // Read all sensor values
  int thumbVal  = analogRead(thumbPin);
  int indexVal  = analogRead(indexPin);
  int middleVal = analogRead(middlePin);
  int ringVal   = analogRead(ringPin);
  int littleVal = analogRead(littlePin);

  // Print all values on one line
  Serial.print("Thumb: ");  Serial.print(thumbVal);
  Serial.print("  Index: ");  Serial.print(indexVal);
  Serial.print("  Middle: "); Serial.print(middleVal);
  Serial.print("  Ring: ");   Serial.print(ringVal);
  Serial.print("  Little: "); Serial.println(littleVal);

  // Check each finger and send message if bent
  if (isThumbBent(thumbVal)) {
    Serial.println("HELP");
  }
  else if (isIndexBent(indexVal)) {
    Serial.println("WATER");
  }
  else if (isMiddleBent(middleVal)) {
    Serial.println("THANK YOU");
  }
  else if (isRingBent(ringVal)) {
    Serial.println("YES");
  }
  else if (isLittleBent(littleVal)) {
    Serial.println("NO");
  }

  Serial.println("---------------------------");
  delay(700); // delay for readability
}
