void setup() {
  pinMode(8, OUTPUT);  // Пин 8 как выход (встроенный светодиод)
}
 
void loop() {
  digitalWrite(8, HIGH);  // Включить
  delay(500);
  digitalWrite(8, LOW);   // Выключить
  delay(500);
}
