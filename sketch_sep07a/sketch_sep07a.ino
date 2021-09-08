#define LDR1_anal A0
#define LDR2_anal A1
const int LDR_Minimum=500;
int buzzer = 12;
int led = 13;
bool LDR1=LOW;
bool LDR2=LOW;

int PeopleNum=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(LDR1_anal)<LDR_Minimum && analogRead(LDR2_anal)>LDR_Minimum && LDR1==LOW && LDR2==LOW)
    LDR1=HIGH;
  if(analogRead(LDR1_anal)>LDR_Minimum && analogRead(LDR2_anal)<LDR_Minimum && LDR1==HIGH && LDR2==LOW)
   {
      while(analogRead(LDR2_anal)<LDR_Minimum)
      { } 
       PeopleNum++;
       Serial.println("People are in room now: " + (String)PeopleNum);
       LDR1=LOW;
       LDR2=LOW;
      
   }
  
  if(analogRead(LDR1_anal)>LDR_Minimum && analogRead(LDR2_anal)<LDR_Minimum && LDR1==LOW && LDR2==LOW)
    LDR2=HIGH;

  if(analogRead(LDR1_anal)<LDR_Minimum && analogRead(LDR2_anal)>LDR_Minimum && LDR1==LOW && LDR2==HIGH)
   {
      while(analogRead(LDR1_anal)<LDR_Minimum)
      { }
      PeopleNum=PeopleNum>0?PeopleNum-1:0;
      Serial.println("People are in room now: " + (String)PeopleNum);
      LDR2=LOW;
      LDR1=LOW;
  }
  if ( PeopleNum >= 5)
  {
digitalWrite(buzzer, HIGH);
    delay(10);
    digitalWrite(buzzer, LOW);
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
  }
}
