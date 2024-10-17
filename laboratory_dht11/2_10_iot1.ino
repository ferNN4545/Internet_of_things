/*
  Temperature sensor sketch
  dev: Fernando Yampuesan
  Date: 16-09-2024
*/

#define LED          10
#define MOTOR        9       
#define analogePin   0

int sensorVal = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    pinMode(MOTOR, OUTPUT);  
}

void loop()
{
    float temp = 0;
    sensorVal = analogRead(analogePin);
    Serial.print("sensorVal input: ");
    Serial.println(sensorVal);

    // TMP 36
    temp = (sensorVal * (500.0 / 1023.0) - 50.0);
    Serial.print("temperatura: ");
    Serial.print(temp);
    Serial.print("\xB0");
    Serial.println("C");

    if (temp < 10.0) {
        
        digitalWrite(MOTOR, LOW);   
        digitalWrite(LED, HIGH);    
    } else if (temp >= 25.0) {
        digitalWrite(MOTOR, HIGH);  
        digitalWrite(LED, LOW);     
    } else if (temp >= 10.0 && temp < 25.0) {
        
        digitalWrite(MOTOR, LOW);   
        digitalWrite(LED, LOW);     
    }

    if (temp > 30.0) {
        digitalWrite(LED, HIGH);   
        delay(500);               
        digitalWrite(LED, LOW);    
        delay(500);                
    }

    delay(2000);  
}
