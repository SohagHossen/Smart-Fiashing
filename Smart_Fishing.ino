# include "LiquidCrystal.h"         // include a library in a program

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;  //Adjust the pin connections based on my circuit
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float temp;   //Assing the temporary variable
int wvalue=0;   // Value for storing water level
int wlavel=A1;  // Pin assing the variable



void setup() {
  Serial.begin(9600);   //passes the value 9600 to the speed parameter
  analogReference(INTERNAL);//a built-in reference
  lcd.begin (16,5);          //sets the dimensions of the LCD                        
  lcd.setCursor(0, 0);    // row and column position
  lcd.print(" MADE BY SHUHAG  ");   //Prints text to the LCD   
  lcd.setCursor(0, 1);// row and column position
  delay(200);   //Pauses the program for the amount of time
  lcd.clear();   //Clears the LCD screen                                        
}
void loop() {
  temp = analogRead(A0);       //temp = temp * 0.48828125;  //temp=temp*(5.0/1023.0)*100;
  temp=temp*1100/(1024*10);
  lcd.print("Temp: ");
  lcd.print(temp);  //Print the value in lcd screen
  lcd.println("*C");
  lcd.setCursor(0, 2);
  int priv=digitalRead(0);
    lcd.print("PRI:");
    if (priv == LOW){       // sensor pass the value low then print not detected
      lcd.println("Not Detected");
     
    }
    else if (priv == HIGH){     // sensor pass the value high then print  detected
      lcd.println("Detected");
      
    }
    
     lcd.setCursor(0, 3);   //position lcd screen

  
    wvalue=analogRead(wlavel);   
    //sensor pass the value  analog pic  and store the value in variable
    lcd.print("Water:");
    lcd.print(wvalue);        //print the value in lcd screen
   
   
     if (wvalue<=100){ lcd.print("Empty"); } 
     //when value lessthen or egual to 100 then print Empty
     if (wvalue>100 && wvalue<=500){ lcd.print(" Low "); }
     //when value lessthen or egual to 500 and gatterthen 100  then print low
     if (wvalue>500 && wvalue<=1000){ lcd.print(" Medium "); } 
     //when value lessthen or egual to 1000 and gatterthen 500  then print Medium
     if (wvalue>1000){ lcd.print(" High "); }
     //when value gatterthen 1000  then print HIGH
    
  
  
   delay(1000);
  lcd.clear();   
                                         
}
