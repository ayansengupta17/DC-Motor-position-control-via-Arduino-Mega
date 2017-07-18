
//int ledPin = 9;    // LED connected to digital pin 9
//int pwm=127;
int Actual,Last, Error=0, SetPt;
float kP=3;
float kI=0.2;
float kD=0;
float Drive=0;
float ScaleFactor=1;
int potValue;
float Angle;
float StartingPos,i=0; 
void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Milisec,Setpoint,Angle,err, drive");
  
  
}

void printData();
void pid();
void StartingPosCal();

void loop() {
    potValue = analogRead(A5);
    Angle = potValue * (339.0 / 1023.0);
    StartingPosCal();

  printData();
   pid();
   
    
   // analogWrite(10, Drive);
  //  digitalWrite(12, LOW);
    
    
 
  }

void printData()
{
    Serial.print("DATA,TIME,");
    Serial.print(millis());Serial.print(",");
   // Serial.print("Stpt= ");
    Serial.print(abs(SetPt-StartingPos));Serial.print(",");
   // Serial.print(", Angle= ");
    Serial.print(abs(Angle-StartingPos));Serial.print(",");
  //  Serial.print(", E= ");
    Serial.print(Error);Serial.print(",");
  //  Serial.print(", Dr= ");
    Serial.println(Drive);
  //  Serial.print(", StPos= ");
   // Serial.println(StartingPos);*/
}

void pid()
{
      int IntThresh=0;
      float P, I, D;
      int Integral=0;
      Actual=Angle;
      SetPt=StartingPos+180;
      if(SetPt>360)
      {
        SetPt=SetPt-360;
      }
      Error = SetPt - Actual;
      if (Error < 0){
        Error = Error + 360;
        
      }
      if (Error > 180){
       Error = Error -360; 
      }
     /* if (abs(Error) < 3){
        Error =0;    
      }*/ 
      if (Error <20){          // prevent integral 'windup' 
         Integral = Integral + Error;       // accumulate the error integral 
      } 
      else { 
         Integral=0;                         // zero it if out of bounds    
      }    
      P = (Error)*kP;                         // calc proportional term 
      I = Integral*kI;                      // integral term 
      D = (Last-Actual)*kD;                 // derivative term 
      Drive = P + I + D;                    // Total drive = P+I+D 
      Drive = Drive*ScaleFactor;    
      
      if (Drive < 0){
        Drive = Drive -50;
       if (abs(Drive)>255) { 
         Drive=255; 
      } 
         analogWrite(9, abs(Drive));        
         digitalWrite (11,LOW);           
      } 
      if (Drive >0){
        Drive = Drive +50;
        if (abs(Drive)>255) { 
         Drive=255; 
      } 
         analogWrite(11, Drive); 
         digitalWrite (9,LOW); 
      } 

      
       if(Drive == 0 || millis() > 2000){
        digitalWrite(9, LOW); 
        digitalWrite (11,LOW);
      }
      
      
      //analogWrite (Motor,Drive);            // send PWM command to motor board 
      Last = Actual;                        // save current value for next time 
}

void StartingPosCal()
{
  while(i!=1)
  {
    StartingPos=Angle;
    i++;
  }
}

