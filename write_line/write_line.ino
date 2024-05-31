
 
byte buttonState = 0;
void setup() {

  Serial.begin(9600);

  for (size_t i = 2; i < 13; i++) {
    pinMode(i, INPUT_PULLUP);
  }
}
String data = "";
void loop() {
  data = "";
  for (size_t i = 2; i < 13; i++) {
    buttonState = !digitalRead(i);
    data += String(buttonState) + String("|")   ;
    
  }
  delay(100);
  Serial.println(data );
   
}
