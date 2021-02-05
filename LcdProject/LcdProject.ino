

int waterval = 0;
int waterPin = A1;

int tempPin = A0;
int tempIn;
double temp;

#include<LiquidCrystal.h>
LiquidCrystal lcd(1,2,4,5,6,7);

char title[31] = {'H','a','l','l','o',' ','m','i','j','n',' ','n','a','a','m',' ','i','s',' ','K','o','e','n',' ','S','a','m','p','e','r','s'};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() { 

  tempIn = analogRead(tempPin);
  waterval = analogRead(waterPin);
  
  temp = (double)tempIn / 1024;
  temp = temp * 5;
  temp = temp - 0.5;
  temp = temp * 100;

  lcd.print("W:");
  lcd.print(waterval);
  lcd.setCursor(0,1);
  lcd.print("Water lvl:");

  if(waterval <= 100){
    lcd.print("EMPTY");
  }
  else if(waterval > 100 && waterval <= 300){
    lcd.print("LOW");
  }
  else if(waterval > 300 && waterval <= 330){
    lcd.print("MEDIUM");
  }
  else if(waterval > 330){
    lcd.print("HIGH");
  }
  
  delay(100);
  lcd.clear();
}
