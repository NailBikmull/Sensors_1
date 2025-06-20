void setup() {
  Serial.begin(9600);
  
    pinMode(9, OUTPUT);  // Пин 9 - выход светодиода
    pinMode(A0, INPUT); // Аналоговый выход  А0 - Потенциометр
}
 
void loop() {
  int val = analogRead(A0);  // Чтение с A0 (0-1023)

  val = printValues(val);
  delay(100);
  analogWrite(9, val);
}

// Функция отображения в консоли
int printValues(int val) {
  Serial.print("Potentiometer value: ");  
  Serial.print(val);    
  Serial.print("  |  ");
  Serial.print(" Normalized: ");       
  val = val / 4; // Нормализация
  Serial.print(val);
  Serial.println();
  return val;
}