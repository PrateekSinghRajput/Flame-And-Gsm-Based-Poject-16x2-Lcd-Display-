//Prateek
//www.prateek.in

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
const int redLed = 7;
 int greenLed = 8;
const int buzzer = 5;

const int flame = 9;
int Flame = LOW;

 
void setup() {
  
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(flame, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);
  lcd.begin(16,2);
}
 
void loop() {
  lcd.setCursor(0, 0);
   lcd.print("WelCome To");
   lcd.setCursor(0, 1);
   lcd.print("JustDoElectronics");
   delay(2000);
   lcd.clear();
   lcd.setCursor(4, 1);
   lcd.print("PIR low");
   
  Flame = digitalRead(flame);
  if (Flame== HIGH)
  {
    lcd.setCursor(4, 1);
    lcd.print("PIR High");

     Serial.println("ATD+919975617490;");
     delay(400);
     Serial.println("AT+CMGF=1");                    
     delay(400);                                     
     Serial.println("AT+CMGS=\"+918830584864\"\r");  
     Serial.println("Movement Alert");                     
     Serial.println((char)26);
     
    digitalWrite(redLed, HIGH);
    delay(5000);
    digitalWrite(buzzer, HIGH);
    delay(5000);
    digitalWrite(greenLed, LOW);
  }
  
  delay(500);
  lcd.clear();
}
