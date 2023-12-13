#include <Thermistor.h> //INCLUSÃO DA BIBLIOTECA

Thermistor temp(0); //VARIÁVEL DO TIPO THERMISTOR, INDICANDO O PINO ANALÓGICO (A2) EM QUE O TERMISTOR ESTÁ CONECTADO
void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  delay(1000); //INTERVALO DE 1 SEGUNDO
}
void loop() {
  int temperature = temp.getTemp(); //VARIÁVEL DO TIPO INTEIRO QUE RECEBE O VALOR DE TEMPERATURA CALCULADO PELA BIBLIOTECA
  Serial.print("temp.:");
  Serial.print(temperature);
  Serial.println("°C");
  delay(1000); //INTERVALO DE 1 SEGUNDO
}
