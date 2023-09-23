////////MIS VARIABLES//////
int numRandom;
String miPregunta;
String sbueno = "¡Claro que sí!";
String smalo = "¡Ni de broma!";
const int ledRojo = 9;   // Respuesta mala
const int ledVerde = 10;  // Respuesta buena

///////MI SETUP/////////
void setup() {
  Serial.begin(9600);

  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  if (Serial) {
    Serial.println("Hola,hazme una pregunta.");
  }
}

void loop() {
  if (Serial.available() > 0) {
    miPregunta = Serial.readStringUntil('\n');  //'\n', '\t', '\r', nueva línea, tabulador (el que está encima de las mayúsculas que sirve para hacer sangría) o enter

    Serial.print("Tu pregunta es: ");
    Serial.println(miPregunta);

    delay(100); //para que ver la pregunta un momento antes de la respuesta.

    int numRandom = random(0, 2);  // Genera un número aleatorio entre 1 y 2

    if (numRandom == 0) {
      Serial.println(sbueno);
      digitalWrite(ledVerde, HIGH); //enciende el LED verde
      delay (1000);
      digitalWrite(ledRojo, LOW);    // Apaga el LED rojo
      delay(1000);
      digitalWrite(ledVerde, LOW);  // Apaga el LED verde
    } if (numRandom == 1) {
      Serial.println(smalo);
      digitalWrite(ledRojo, HIGH);  // Enciende el LED rojo
      digitalWrite(ledVerde, LOW);  // Apaga el LED verde
      delay(1000);
      digitalWrite(ledRojo, LOW);  // Apaga el LED rojo
    }
  }
}
