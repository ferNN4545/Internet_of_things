const int green = 11;
const int red = 12;
const int orange = 13;


int estadoGreen = LOW;
int estadoRed = LOW;
int estadoOrange = LOW;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(orange, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char option = Serial.read();
    
    switch(option) {
      case '1': 
        controlarLuz(green, HIGH);
        estadoGreen = HIGH;
        break;
      
      case '2':
        toggleLuz(green, estadoGreen);
        break;
      
      case '3':
        controlarLuz(red, HIGH);
        estadoRed = HIGH;
        break;
      
      case '4':
        toggleLuz(red, estadoRed);
        break;
      
      case '5':
        controlarLuz(orange, HIGH);
        estadoOrange = HIGH;
        break;
      
      case '6':
        toggleLuz(orange, estadoOrange);
        break;
      
      case '7':
        controlarTodas(HIGH);
        Serial.println("Luces Prendidas");
        break;
      
      case '8':
        controlarTodas(LOW);
        Serial.println("Luces apagadas");
        break;
      
      case '9':
        parpadeo();
        break;
      
      default:
        Serial.println("Opción no válida");
        break;
    }
  }
}

void toggleLuz(int luz, int &estado) {
  if (estado == LOW) {
    digitalWrite(luz, HIGH);
    estado = HIGH;
    Serial.println(" prendida");
  } else {
    digitalWrite(luz, LOW);
    estado = LOW;
    Serial.println(" apagada");
  }
}

void controlarLuz(int luz, int estado) {
  digitalWrite(luz, estado);
}

void controlarTodas(int estado) {
  digitalWrite(green, estado);
  digitalWrite(red, estado);
  digitalWrite(orange, estado);
}

void parpadeo() {
  for(int i = 0; i < 50; i++) {
    controlarTodas(HIGH);
    delay(500);
    controlarTodas(LOW);
    delay(500);
  }
}

