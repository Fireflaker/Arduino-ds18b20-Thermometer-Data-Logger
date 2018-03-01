#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

#include <LiquidCrystal.h>

#include "DHT.h"
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float temp1 = 88;
float temp2 = 88;
float h = 66;
float t = 66;

int val0 = 0;
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;

long count = 0;
int displayVal = -10;


//#define TEMP_9_BIT  0x1F //  9 bit
//#define TEMP_10_BIT 0x3F // 10 bit
//#define TEMP_11_BIT 0x5F // 11 bit
#define TEMP_12_BIT 0x7F // 12 bit

void setup(void)
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // start serial port
  Serial.begin(115200);
  Serial.println("Dallas Temperature IC Control Library Demo");
  dht.begin();
  // Start up the library
  sensors.begin();
  lcd.clear();

}


void loop(void)
{

  val0 = analogRead(A0);
  val1 = analogRead(A1);
  val2 = analogRead(A2);
  val3 = analogRead(A3);
  val4 = analogRead(A4);
  val5 = analogRead(A5);
  
h = dht.readHumidity();
f = dht.readTemperature() == Celcius;


  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //  Serial.println("DONE");

  temp1 = sensors.getTempCByIndex(0);
  temp2 = sensors.getTempCByIndex(1);
  // Why "byIndex"?
  // You can have more than one IC on the same bus.
  // 0 refers to the first IC on the wire



  Serial.print(count);
  Serial.print("  No.1 Temp: ");
  Serial.print(temp1);
  Serial.print("  No.2 Temp: ");
  Serial.print(temp2);
  Serial.print("  v0: ");
  Serial.print(val0);
  Serial.print("  v1: ");
  Serial.print(val1);
  Serial.print("  v2: ");
  Serial.print(val2);
  Serial.print("  v3: ");
  Serial.print(val3);
  Serial.print("  v4: ");
  Serial.print(val4);
  Serial.print("  v5: ");
  Serial.println(val5);



  // set the cursor to column 0, line 0
  // (note: line 1 is the second row, since counting begins with 0):
  if (count % 20 == 0)
  {
    lcd.clear();
  }

  lcd.setCursor(0, 0);
  lcd.print("A:");
  lcd.print(temp1);

  lcd.setCursor(8, 0);
  lcd.print("B:");
  lcd.print(temp2);

  lcd.setCursor(0, 1);
  lcd.print(count);

  count++;
  displayVal++;

  if (displayVal > 5) {
    displayVal = 0;
  }

  //Serial.println(displayVal);

//  lcd.setCursor(7, 1);
//  lcd.print("Val");
  lcd.setCursor(7, 1);
  lcd.print(displayVal);
  lcd.print(":");



  if (displayVal == 0) {
    lcd.print(val0);
  }
  if (displayVal == 1) {
    lcd.print(val1);
  }
  if (displayVal == 2) {
    lcd.print(val2);
  }
  if (displayVal == 3) {
    lcd.print(val3);
  }
  if (displayVal == 4) {
    lcd.print(val4);
  }
  if (displayVal == 5) {
    lcd.print(val5);
  }

  if (isnan(h) || isnan(f)) {
    lcd.print("ERROR");
    return;
  }

  lcd.setCursor(7, 1);
  lcd.print(f);
  lcd.setCursor(7,1);
  lcd.print(h);  

}





