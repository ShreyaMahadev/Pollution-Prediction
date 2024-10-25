
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int buzzer=7;
int a,b,c;
int n=0;
int count=0;
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("AIR POLLUTION");
  lcd.setCursor(0, 1);
  lcd.print(" CONTROL MODEL");
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,LOW);
//  Serial.println("HI..");
  delay(2000);
  // put your setup code here, to run once:
}

void loop() 
{
  SENSOR_CO();
  SENSOR_CO2();
//  SENSOR_HC();
//  RESULT();
//  if (n==1)
//  {
////    Serial.println("IGNITION ON");
//        lcd.clear();
//  lcd.print("IGNITION ON ");
//  lcd.setCursor(0, 0);
//  digitalWrite(valve,HIGH);
//  delay(1000); 
//  n=0;
//  
//      }
    }
void SENSOR_CO()
{

  int sens1=analogRead(A0);
  Serial.print("CA:");
  Serial.println(sens1);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CO2 VALUE:");
  lcd.setCursor(10, 0);
  lcd.print(sens1);  
  delay(1000);
  if (sens1>350)
  {
    lcd.clear();
      lcd.setCursor(0, 0);
  lcd.print("CO2 VALUE IS ");
  lcd.setCursor(6, 1);
  lcd.print("MORE");
  lcd.setCursor(0, 0);
  digitalWrite(buzzer,HIGH);
  delay(1000);
    }
    else
    {
    lcd.clear();
      lcd.setCursor(0, 0);
  lcd.print("CO2 VALUE IS ");

    lcd.setCursor(5, 1);
  lcd.print("NORMAL");
  delay(1000);
  digitalWrite(buzzer,LOW);   
  n=1; 
  a=0;  
      }
}
void SENSOR_CO2()
{ 
   int sens2=analogRead(A1);
  Serial.print("CO:");
  Serial.println(sens2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CO2 VALUE:");
  lcd.setCursor(10, 0);
  lcd.print(sens2);  
  delay(1000);
  if (sens2>180)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("CO VALUE IS ");
    lcd.setCursor(5, 1);
  lcd.print("MORE");
  digitalWrite(buzzer,HIGH);   
  delay(1000); 
  b=1;
    }
    else
    {
    lcd.clear();
  lcd.print("CO VALUE IS ");
    lcd.setCursor(5, 1);
  lcd.print("NORMAL");
  digitalWrite(buzzer,LOW);   
  delay(1000);  
  
  n=1;   
  b=0; 
      
      }
}

