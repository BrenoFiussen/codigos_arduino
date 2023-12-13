
# include <Servo.h>
// Define nomes para as entradas digitais 11 e 10
const int trigPin = 4;
const int echoPin = 3;

long tempo; // Define tempo com uma variavel longa
int distancia; // Define distancia como uma variavel inteira

Servo Servo; // incluir a porta do servo

void setup() {
  Serial.begin(9600); // define a comunicação serial
  Servo.attach(2); // incluir a porta do servo motor
}

void loop() {
// move o servo e imprime angulo e distancia no serial monitor
  for(int i=15;i<=165;i++){  
  Servo.write(i);
  delay(30);
  distancia = calculoDistancia();
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distancia); 
  Serial.print("."); 
  }
   
  for(int i=165;i>15;i--){  
  Servo.write(i);
  delay(30);
  distancia = calculoDistancia();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distancia);
  Serial.print(".");
  }
}
// Funcionamento do Ultra e calculo da distancia
int calculoDistancia(){
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  tempo = pulseIn(echoPin, HIGH); 
  distancia= tempo*0.034/2;
  return distancia;
}
