#include <SR04.h>
#include <LiquidCrystal.h>

#define BLUE 3
#define GREEN 5
#define RED 6
// specify sensor pins
int trig_pin = 12;
int echo_pin = 11;

// setup sensor object
SR04 sensor = SR04(echo_pin, trig_pin);
long distance;

//buzzerpin
int buzzerPin = 10;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 9, 8, 7, 4, 2);

void setup() {
  // put your setup code here, to run once:
  //rgb pins
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  //open serial communications w monitor
  Serial.begin(9600);
  delay(1000);

  //buzzer
  pinMode(buzzerPin, OUTPUT);


}

int redValue;
int greenValue;
int blueValue; 

void loop() {
  // put your main code here, to run repeatedly:
  
  #define delayTime 10

  distance = sensor.Distance();
  Serial.println(distance);
  
  // Print distance to the LCD.
  lcd.print("Distance: ");
  lcd.print(distance);

  if (distance > 50 && distance <= 400){
    redValue = 255;
    greenValue = 153;
    blueValue = 0;

    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
  }

    if (distance <= 50 && distance > 10){
    redValue = 0;
    greenValue = 255;
    blueValue = 255;

    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
  }

    if (distance <= 10){
    redValue = 255;
    greenValue = 0;
    blueValue = 255;

    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);

    //buzzer
    digitalWrite(buzzerPin, HIGH);
  }

  
  delay(500);
  digitalWrite(buzzerPin, LOW);
  lcd.clear();

  
  
}
