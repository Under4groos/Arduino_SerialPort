

byte buttonState = 0;
char buf[10];
void setup() {
   
  Serial.begin(9600);

  for (size_t i = 0; i < 13; i++)
  {
    pinMode(i, INPUT_PULLUP);
  }
  
}

void loop() {
  for (size_t i = 0; i < 13; i++)
  {
    buttonState = digitalRead(i) ;

    sprintf(buf, "%d:%d", i , buttonState == LOW );
    Serial.println(  buf );
  

    
  }
  
  delay(1);
}
