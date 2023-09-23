const int sensorPin = 8;  // Pin donde está conectado el sensor de vibración
const int ledPin = 9;    // Pin donde está conectado el LED

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(sensorPin); // Lee el valor del sensor (1 o 0)

  if (sensorValue == HIGH) {
    Serial.println("Golpe detectado!"); // Muestra un mensaje en el monitor serial
    digitalWrite(ledPin, HIGH);         // Enciende el LED
    delay(1000);                         // Espera 1 segundo
    digitalWrite(ledPin, LOW);          // Apaga el LED
  }
}
