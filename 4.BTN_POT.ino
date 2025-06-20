const int ledPin = 9; // Светодиоид
const int potPin = A0; // Потенциометр
const int buttonPin = 2; // Кнопка

bool ledState = false;
bool lastButtonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  int reading = digitalRead(buttonPin); // Чтение состояния кнопки

    if (reading == 1 && lastButtonState == 0) {
      ledState = !ledState;  // переключение состояния
      Serial.print("Светодиод: ");
      Serial.println(ledState ? "ВКЛ" : "ВЫКЛ");
    }

  lastButtonState = reading; // Сохраняем предыдущее состояние

  int potValue = analogRead(potPin);  // Считываем значение потенциометра (0–1023)
  int brightness = potValue / 4;      // Нормализация
  
  // Управляем светодиодом
  if (ledState) {
    analogWrite(ledPin, brightness); // Включен с определённым значением яркост
  } else {
    analogWrite(ledPin, 0);  // Полностью выключен
  }

  delay(100);
}
