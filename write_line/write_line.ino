
String BUFFER_RETURN = "";

byte buttonState = 0;
 

void setup() {

  Serial.begin(9600);

  for (size_t i = 0; i < 13; i++) {
    pinMode(i, INPUT_PULLUP);
  }
}
 
void loop() {
  BUFFER_RETURN = "";
  for (size_t i = 2; i < 13; i++) {
    buttonState = digitalRead(i);

    Serial.print(  String(i) + ":" + (buttonState == LOW ? "true" : "false") );
  }
  
  delay(10);
}
