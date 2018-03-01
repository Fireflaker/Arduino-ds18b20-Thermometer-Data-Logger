
int val0 = 0;
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;
int val6 = 0;
int val7 = 0;
int val8 = 0;
int val9 = 0;
int val10 = 0;
int val11 = 0;

#define FASTADC 1

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

int led = 13;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by

void setup(void)
{
pinMode(led, OUTPUT);
  Serial.begin(2000000);
 int start ;
 int i ;
 
#if FASTADC
 // set prescale to 16
 sbi(ADCSRA,ADPS2) ;
 cbi(ADCSRA,ADPS1) ;
 cbi(ADCSRA,ADPS0) ;
#endif

 Serial.begin(2000000) ;
 Serial.print("ADCTEST: ") ;
 start = millis() ;
 for (i = 0 ; i < 10000 ; i++)
analogRead(A0);

 Serial.print(millis() - start) ;
 Serial.println(" msec (10,000 calls)") ;



}


void loop(void)
{
  
analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  val0 = analogRead(A0);
  val1 = analogRead(A1);
  val2 = analogRead(A2);
  val3 = analogRead(A3);
  val4 = analogRead(A4);
  val5 = analogRead(A5);
  val6 = analogRead(A6);
  val7 = analogRead(A7);
  val8 = analogRead(A8);
  val9 = analogRead(A9);
  val10 = analogRead(A10);
  val11 = analogRead(A11);



  Serial.print(val0);
  Serial.print(",");
  Serial.print(val1);
  Serial.print(",");
  Serial.print(val2);
  Serial.print(",");
  Serial.print(val3);
  Serial.print(",");
  Serial.print(val4);
  Serial.print(",");
  Serial.print(val5);
  Serial.print(",");
  Serial.print(val6);
  Serial.print(",");
  Serial.print(val7);
  Serial.print(",");
  Serial.print(val8);
  Serial.print(",");
  Serial.print(val9);
  Serial.print(",");
  Serial.print(val10);
  Serial.print(",");
  Serial.println(val11);



}





