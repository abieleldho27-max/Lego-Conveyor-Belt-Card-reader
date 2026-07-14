

#define photoPin A0
#define readLedPin 2
#define prize1LedPin 7
#define prize2LedPin 12
#define button 4


String code;
int codelength = 17;
int PINS[] = {8, 9, 10, 11};
bool clockwise = true;
bool reading;
int i;
int del = 2;
void setup()
{
pinMode(photoPin, INPUT);
pinMode(readLedPin, OUTPUT);
pinMode(prize1LedPin, OUTPUT);
pinMode(prize2LedPin, OUTPUT);
pinMode(button, INPUT_PULLUP);
for (i = 0; i < 4; i++)
  {
    pinMode(PINS[i], OUTPUT);
    digitalWrite(PINS[i], LOW);
  }
Serial.begin(115200);
}
void loop() 
{
  if(digitalRead(button) == LOW)
  {
    reading = true;
  }
  else
  {
    reading = false;
  }
 if(reading == true)
  {
    for(int j = 0; j < 20; j++)
    {
  cycleMotor();
  cycleMotor();
  cycleMotor();
  cycleMotor();
  cycleMotor();
  cycleMotor();
    }
 if (code.substring(0, 12) == "001100001100" )
 {
  digitalWrite(prize1LedPin, HIGH);
  Serial.println("code correct");
  delay(2000);
 }
 else if (code.substring(0, 12) == "001111001111")
 {
  digitalWrite(prize2LedPin, HIGH);
  Serial.println("code correct");
  delay(2000);
 }
 else
 {
  digitalWrite(prize1LedPin, LOW);
  digitalWrite(prize2LedPin, LOW);
 }
 float photoread = (analogRead(photoPin));
 Serial.println(photoread);
 if (photoread < 400)
 {
  digitalWrite(readLedPin, HIGH);
   if (code.length() > codelength)
 {
  code = "1";
 }
 else
 {
  code += "1";
 }
 }
 else
 {
  digitalWrite(readLedPin, LOW);
     if (code.length() >= codelength)
 {
  code = "0";
 }
 else
 {
  code += "0";
 }
 }
Serial.println(code);

delay(150);
}
else
{
  code = "";
}
}
void cycleMotor()
{
  if (clockwise)
  {
  digitalWrite(PINS[i], HIGH);
  delay(del);
  digitalWrite(PINS[i], LOW);

  i += 1;
    if (i > 3)
    {
    i=0;
    }
  }
  else
  {
  digitalWrite(PINS[i], HIGH);
  delay(del);
  digitalWrite(PINS[i], LOW);

  i -= 1;
    if (i < 0)
    {
    i = 3;
    }
  }
}
