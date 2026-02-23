// include the library code:
#include <LiquidCrystal.h> //allow the use for a lcd screen
#define soilWet 350 //set the lower threshold for how wet the soil is
#define soilDry 520 //set the upper threshold for how wet the soil is
#define noSun 150 //detect whether or not there is sun

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int SensorPin = A1; //read the soil sensor from Analog 1

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600); 

  //pinMode(8, OUTPUT); Set DP8 as output (Water pump for relay)
}

void loop() {

  // Turn on the display:
  lcd.display();
  delay(500);

  float sensorValue = 0; //set the initial soil sensor value to 0
  
  for (int i = 0; i <= 100; i++) //read the value sent from the soil sensor over time and assign the value to sensorValue
  { 
    sensorValue = sensorValue + analogRead(SensorPin); 
    delay(1); 
  } 
  sensorValue = sensorValue/100.0; 
   
  int value = analogRead(A0); //read the light value from the photoresistor

  //output the soil sensor value and the light sensor so the user can see the values
  lcd.print("Moisture: " + String(sensorValue)); 
  lcd.setCursor(0,1);
  lcd.print("Light: " + String(value));   
  
  delay(5000);

  
  //if the soil is not wet enough this code will display that the plant needs water
  if(sensorValue < soilWet)
  {
    lcd.clear();
    lcd.print("Soil is too Wet!");
    delay(2000);

    //if there is not enough light then the user will be notified on the lcd
    if(value < noSun)
    {
      lcd.clear();
      lcd.print("You need sun");
      delay(2000);
    }
  }

  //if the soil is too dry then the user will be notified on the lcd from this code
  if(sensorValue > soilDry)
  {
    lcd.clear();
    lcd.print("Soil is too Dry!");
    lcd.setCursor(0,1);
    lcd.print("Water the soil");
    delay(2000);
    
    /* If the soil is dry, activate the relay which activates the water pump so that
     *  the soil can be watered (below)
     *  
     *  digitalWrite(8,HIGH);
     *  delay(10000);
     *  digitalWrite(8,LOW);
     *  
     */

    //if there is not enough light then the user will be notified on the lcd
    if(value < noSun)
    {
      lcd.clear();
      lcd.print("You need sun");
      delay(2000);
    }
    
  }
  //if there is not enough light then the user will be notified on the lcd
  if(value < noSun)
    {
      lcd.clear();
      lcd.print("You need sun");
      delay(2000);
    }

   //clear the lcd so that new values can be displayed
   lcd.clear();

}
 
 
