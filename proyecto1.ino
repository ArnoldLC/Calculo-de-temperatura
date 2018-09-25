#include <LiquidCrystal.h>

//Instanciamos LiquidCrystal:
LiquidCrystal lcd(1 ,2, 4, 5, 6, 7);

//Entrada analógica LM35:
const int sensor = 0;

//Variables de LM35:
long milivolts;
long temperature;

//Símbolo grados
byte grado[8] = {
  0b00001100,     // Los definimos como binarios 0bxxxxxxx
  0b00010010,
  0b00010010,
  0b00001100,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
};

//Salida analógica de Motor:
const int motor = 9;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.createChar(1,grado);
  pinMode(motor, OUTPUT);
  //lcd.cursor();
}

void loop() {
  milivolts = (analogRead(sensor) * 5000L) / 1023;
  temperature = milivolts/10;

  //analogWrite(motor, analogRead(sensor)/4);
  //digitalWrite(motor, HIGH);
  lcd.setCursor(14,0);
  //lcd.leftToRight();
  lcd.rightToLeft();
  lcd.print("ARUTA REPMET");
  lcd.setCursor(0, 1);
  lcd.leftToRight();
  lcd.print("AMBI ENTE: ");
  lcd.print(temperature);
  lcd.write(1);
  lcd.print("C"); 

  
  //lcd.setCursor(14, 0);
  delay(500);
  lcd.clear();
  
}
