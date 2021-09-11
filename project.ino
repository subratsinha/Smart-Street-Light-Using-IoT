#include<LiquidCrystal.h>
const int rs=0,en=1,d4=2,d5=3,d6=4,d7=5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int object_distance = 0;
int val=0;
int ldr_pin=A0;
int ldr_value;
long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);  
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  return pulseIn(pin, HIGH);
}

void setup()
  
{
  lcd.begin(16,2);
  pinMode(9, INPUT);
  pinMode(13, OUTPUT); 
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(ldr_pin, INPUT);  
}

void loop()
{
  object_distance = 0;
  object_distance = 0.01723 * readUltrasonicDistance(9);
  lcd.setCursor(1,0);
  ldr_value = analogRead(ldr_pin);
  
  
   if (ldr_value <512)
   {
  if (object_distance <50)
  { 
    
      digitalWrite(13, HIGH);  
      delay(1000);
      digitalWrite(13,LOW);
  }
  object_distance = 0.01723 * readUltrasonicDistance(8);

  if (object_distance <50)
  { 
    
      digitalWrite(12, HIGH);  
      delay(1000);
      digitalWrite(12,LOW);
  }
  object_distance = 0.01723 * readUltrasonicDistance(7);

  if (object_distance <50)
  { 
    
      digitalWrite(11, HIGH);  
      delay(1000);
      digitalWrite(11,LOW);
  }
  
  object_distance = 0.01723 * readUltrasonicDistance(6);

  if (object_distance <=50)
  { 
    
      digitalWrite(10, HIGH);  
      delay(1000);
      digitalWrite(10,LOW);
   
  }
 
  if(digitalRead(9))
  {
      while(digitalRead(9));
      val=(!val);
      digitalWrite(9,val);
  }
   }
    else 
  {
    lcd.print(" DAY ");
    lcd.setCursor(0,1); 
    lcd.print("POWERSAVING MODE");
    lcd.setCursor(1,1); 
    delay(60000);
    lcd.clear();
   
    
   
  }
  
       
}
