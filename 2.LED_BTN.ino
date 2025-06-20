volatile bool ledState = false;
const int ledPin = 8;
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(2, INPUT_PULLUP);  // Подтяжка к +5V

  attachInterrupt(digitalPinToInterrupt(2), buttonPressed, FALLING);
}
 
void loop() {
  digitalWrite(ledPin, ledState);  // Управление светодиодом
}
 
// Обработчик прерывания
void buttonPressed() {
  ledState = !ledState;
}
