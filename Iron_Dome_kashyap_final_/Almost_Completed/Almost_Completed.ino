#include <Servo.h>
Servo My_servo;
Servo My_servo1;
int pos = 0;
int trig=13;
int echo=12;
int ROT;
float min_val=30;
float ultra_distance[181]={0};
  int angle[181]={0};
void setup() {
  My_servo.attach(7,600,2300);
  My_servo1.attach(9);
  My_servo.write(600);
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
 digitalWrite(trig,LOW);
 digitalWrite(echo,LOW);
 Serial.begin(9600);
 pinMode(5,OUTPUT);
 pinMode(4,OUTPUT);
}

void loop()
{
  My_servo.write(15);
  delay(600);
  int j=0;
  int index=-2;// check index value
  
     for (int i=15; i<=165;i+=2)
          {
          My_servo.write(i);
         delay(50);
         angle[j]=i;
         ultra_distance[j]=measure_distance_cm();
         delay(20);
         Serial.print(" the iteration = ");
         Serial.print(i);
         Serial.print(" ultra_distance = ");
         Serial.println(ultra_distance[j]);
         Serial.print("j =");
         Serial.println(j); 
         j+=1;   
         if (i==165){break;} 
         }
       for (j=15;j<=165;j+=1)
       {min_val=max(min_val,ultra_distance[j]);
      
        }
         
   for (j=15;j<=165;j+=1)
       {if (30>ultra_distance[j])
       {
        index=j;
        {break;}
        }else{
          index = 0;}
        }
       
       {ROT = index*2;}     
       Serial.print(" the min value =");
              Serial.println(min_val);
       Serial.print("the index value =");
              Serial.println(index);
       
       

        My_servo.write(angle[index]); 
        delay(1000);  
     while(true)
        {
          float new_val=0;
        
        new_val= measure_distance_cm();
        Serial.print(" new value = ");
        Serial.print(new_val);
        Serial.print(" angle= ");
        Serial.print(angle[index]);
        Serial.print(" Final Rotatary: ");
        Serial.print(ROT);
        delay(1000);
        


        
          if (abs(ultra_distance[index]-new_val)>=2.0)
             {break;
              }}

if (ROT < 25) {
    My_servo1.write(pos += 180);
    delay(500); // Wait for 500 millisecond(s)
    My_servo1.detach();
    delay(10);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(10000);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(100);
    My_servo1.attach(9);
    My_servo1.write(pos -= 180);
    delay(500);
    My_servo1.detach();
    delay(10);
    exit(0); 
  }
  if (ROT >= 25 && ROT < 50) {
    My_servo1.write(pos += 180);
    delay(1000); // Wait for 1000 millisecond(s)
    My_servo1.detach();
    delay(10);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(10000);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(100);
    My_servo1.attach(9);
    My_servo1.write(pos -= 180);
    delay(1000);
    My_servo1.detach();
    delay(10);
    exit(0); 
  }
  if (ROT >= 50 && ROT < 75) {
    My_servo1.write(pos += 180);
    delay(1500); // Wait for 1500 millisecond(s)
    My_servo1.detach();
    delay(10);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(10000);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(100);
    My_servo1.attach(9);
    My_servo1.write(pos -= 180);
    delay(1500);
    My_servo1.detach();
    delay(10);
    exit(0); 
  }
  if (ROT >= 75 && ROT < 100) {
    My_servo1.write(pos += 180);
    delay(2000); // Wait for 2000 millisecond(s)
    My_servo1.detach();
    delay(10);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(10000);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(100);
    My_servo1.attach(9);
    My_servo1.write(pos -= 180);
    delay(2000);
    My_servo1.detach();
    delay(10);
    exit(0); 
  }
  if (ROT >= 100 && ROT < 125) {
    My_servo1.write(pos += 180);
    delay(2500); // Wait for 2500 millisecond(s)
    My_servo1.detach();
    delay(10);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(10000);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(100);
    My_servo1.attach(9);
    My_servo1.write(pos -= 180);
    delay(2500);
    My_servo1.detach();
    delay(10);
    exit(0); 
  }
  if (ROT >= 125 && ROT < 150) {
    My_servo1.write(pos += 180);
    delay(3000); // Wait for 3000 millisecond(s)
    My_servo1.detach();
    delay(10);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(10000);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(100);
    My_servo1.attach(9);
    My_servo1.write(pos -= 180);
    delay(3000);
    My_servo1.detach();
    delay(10);
    exit(0); 
  }
  if (ROT >= 150 && ROT <= 175) {
    My_servo1.write(pos += 180);
    delay(3500); // Wait for 3500 millisecond(s)
    My_servo1.detach();
    delay(10);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(10000);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(100);
    My_servo1.attach(9);
    My_servo1.write(pos -= 180);
    delay(3500);
    My_servo1.detach();
    delay(10);
    exit(0); 
  }

}
float measure_distance_cm()
{
  float distance =0;
  long time_value=0;
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  time_value=pulseIn(echo,HIGH);
  distance=.033*time_value/2;
  return distance;}  
