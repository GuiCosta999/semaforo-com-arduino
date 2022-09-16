// C++ code
//


int pinvermelho=10;
int pinamarelo=9;
int pinverde=8;
int pinbut=7;
int pinpedvermelho=3;
int pinpedverde=2;

int fasesemaforo;
int stbut; 
int stantbut;

int timepisc;
 int stpisc;
void setup()
{
  pinMode(pinverde, OUTPUT);
  pinMode(pinamarelo, OUTPUT);
  pinMode(pinvermelho, OUTPUT); 
  pinMode(pinbut, INPUT);
  pinMode(pinpedverde, OUTPUT);
  pinMode(pinpedvermelho, OUTPUT);
  
  fasesemaforo=1;
  
  stantbut= digitalRead(pinbut);
  
  timepisc=0;
  stpisc=1;
  
}

void loop()
{
  stbut = digitalRead(pinbut);
  
  if ((stbut==LOW) && (stantbut==HIGH)) {
    
    if(fasesemaforo<4){
    fasesemaforo =fasesemaforo+1;
    }  
    else {
      fasesemaforo=1;
    }
  }
  stantbut=stbut;
  if (fasesemaforo ==1){
    digitalWrite (pinverde, HIGH);
    digitalWrite (pinamarelo, LOW);
    digitalWrite (pinvermelho, LOW);
    
    digitalWrite (pinpedvermelho, HIGH);
     digitalWrite (pinpedverde, LOW);
  }
  if (fasesemaforo ==2){
    digitalWrite (pinverde, LOW);
    digitalWrite (pinamarelo, HIGH);
    digitalWrite (pinvermelho, LOW);
    
    digitalWrite (pinpedvermelho, HIGH);
     digitalWrite (pinpedverde, LOW);
    
  }
   if (fasesemaforo ==3){
    digitalWrite (pinverde, LOW);
    digitalWrite (pinamarelo, LOW);
    digitalWrite (pinvermelho, HIGH);
     
     digitalWrite (pinpedvermelho, LOW);
     digitalWrite (pinpedverde, HIGH);
   } 
  if (fasesemaforo ==4){
    digitalWrite (pinverde, LOW);
    digitalWrite (pinamarelo, LOW);
    digitalWrite (pinvermelho, HIGH);
    
    timepisc=timepisc+1;
      if(timepisc==400){
      stpisc=!stpisc;
      timepisc=0;
      }
     digitalWrite (pinpedvermelho, stpisc);
     digitalWrite (pinpedverde, LOW);
   }  


	
  delay(1);
}