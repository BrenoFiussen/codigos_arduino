#include <Thermistor.h> //INCLUSÃO DA BIBLIOTECA
#include <LiquidCrystal_I2C.h> // INCLUSÃO DA BIBLIOTECA

Thermistor temp(2); //VARIÁVEL DO TIPO THERMISTOR, INDICANDO O PINO ANALÓGICO (A2) EM QUE O TERMISTOR ESTÁ CONECTADO
LiquidCrystal_I2C lcd_1(0x27,16,2); // DEFINE PORTA DO DISPLAY
void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL

  /////////////////////////////////////////////////////////////
                    //SETUP DISPLAY://
  /////////////////////////////////////////////////////////////
    lcd_1.init();
    lcd_1.backlight();
    lcd_1.setCursor(1,0);
    lcd_1.print("SEJA BEM VIND@");
    lcd_1.setCursor(3, 1);
    lcd_1.print("CIEFI-FURG");

  delay(1000); //INTERVALO DE 1 SEGUNDO
}
void loop() {
  int temperature = temp.getTemp(); //VARIÁVEL DO TIPO INTEIRO QUE RECEBE O VALOR DE TEMPERATURA CALCULADO PELA BIBLIOTECA
  lcd_1.init();
  lcd_1.backlight();
  lcd_1.setCursor(0,0);
  lcd_1.print("Temp.:");//IMPRIME O TEXTO NO MONITOR SERIAL
  lcd_1.setCursor(7,0);
  lcd_1.print(temperature); //IMPRIME NO MONITOR SERIAL A TEMPERATURA MEDIDA
  lcd_1.setCursor(9,0);
  lcd_1.print("*C"); //IMPRIME O TEXTO NO MONITOR SERIAL
  delay(1000); //INTERVALO DE 1 SEGUNDO
}
