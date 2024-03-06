const int dc1=2;  
const int dc2=3;
const int dc3=4;
const int dc4=5;

const int ir1=8;
const int ir2=9;
const int ir3=10;

const int rly1=6;
const int rly2=7;
char x=0;
int flag=0;


void setup() {
  // put your setup code here, to run once:
 pinMode(dc1,OUTPUT);
  pinMode(dc2,OUTPUT);
  pinMode(dc3,OUTPUT);    
  pinMode(dc4,OUTPUT);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);    
  pinMode(rly1,OUTPUT);  
  pinMode(rly2,OUTPUT);    
  Serial.begin(9600);
  digitalWrite(dc1,LOW);
  digitalWrite(dc2,LOW);
  digitalWrite(dc3,LOW);  
  digitalWrite(dc4,LOW);
  digitalWrite(rly1,LOW);  
  digitalWrite(rly2,LOW);
  Serial.write("WELCOME\n");    
    digitalWrite(dc1,HIGH);  
    digitalWrite(dc2,LOW);    
    digitalWrite(dc3,HIGH);  
    digitalWrite(dc4,LOW);  
    flag=1;  
}
  // put your main code here, to run repeatedly:
void loop()
{
  home:
  if(flag==1)
  {
  if((digitalRead(ir1)==HIGH)&&(digitalRead(ir2)==LOW)&&(digitalRead(ir3)==HIGH))
  {
  digitalWrite(dc1,LOW);
  digitalWrite(dc2,LOW);
  digitalWrite(dc3,LOW);  
  digitalWrite(dc4,LOW);    
  Serial.write("MIDDLE IR \n");    
  delay(500);
    digitalWrite(dc1,LOW);  
    digitalWrite(dc2,HIGH);    
    digitalWrite(dc3,LOW);  
    digitalWrite(dc4,HIGH);
  Serial.write("BACK \n");  
  delay(3000);
    digitalWrite(dc1,LOW);  
    digitalWrite(dc2,HIGH);    
    digitalWrite(dc3,HIGH);  
    digitalWrite(dc4,LOW);
   Serial.write("right \n");  
  delay(5000);    
     digitalWrite(dc1,HIGH);  
    digitalWrite(dc2,LOW);    
    digitalWrite(dc3,HIGH);  
    digitalWrite(dc4,LOW);        
  }
  if((digitalRead(ir1)==LOW)&&(digitalRead(ir2)==HIGH)&&(digitalRead(ir3)==HIGH))
  {
    digitalWrite(dc1,HIGH);  
    digitalWrite(dc2,LOW);    
    digitalWrite(dc3,LOW);  
    digitalWrite(dc4,HIGH);
    Serial.write("left \n");  
    delay(5000);  
     digitalWrite(dc1,HIGH);  
    digitalWrite(dc2,LOW);    
    digitalWrite(dc3,HIGH);  
    digitalWrite(dc4,LOW);            
  }
  if((digitalRead(ir1)==HIGH)&&(digitalRead(ir2)==HIGH)&&(digitalRead(ir3)==LOW))
  {
    digitalWrite(dc1,LOW);  
    digitalWrite(dc2,HIGH);    
    digitalWrite(dc3,HIGH);  
    digitalWrite(dc4,LOW);
    Serial.write("right \n");
    delay(5000);
    digitalWrite(dc1,HIGH);  
    digitalWrite(dc2,LOW);    
    digitalWrite(dc3,HIGH);  
    digitalWrite(dc4,LOW);            
  }  
  }
   if(Serial.available()>0)  
  {
    x = Serial.read();      
    if(x == 'F')            
    {
    digitalWrite(dc1,HIGH);  
    digitalWrite(dc2,LOW);    
    digitalWrite(dc3,HIGH);  
    digitalWrite(dc4,LOW);  
    flag=1;
    goto home;
    }
    if(x == 'B')            
    {
    digitalWrite(dc1,LOW);  
    digitalWrite(dc2,HIGH);    
    digitalWrite(dc3,LOW);  
    digitalWrite(dc4,HIGH);
    flag=1;    
    goto home;
    }
    if(x == 'R')            
    {
    digitalWrite(dc1,LOW);  
    digitalWrite(dc2,HIGH);    
    digitalWrite(dc3,HIGH);  
    digitalWrite(dc4,LOW);
    flag=1;    
    goto home;
    }
    if(x == 'L')            
    {
    digitalWrite(dc1,HIGH);  
    digitalWrite(dc2,LOW);    
    digitalWrite(dc3,LOW);  
    digitalWrite(dc4,HIGH);
    flag=1;    
    goto home;
    }
    if(x == 'S')            
    {
    digitalWrite(dc1,LOW);  
    digitalWrite(dc2,LOW);    
    digitalWrite(dc3,LOW);  
    digitalWrite(dc4,LOW);
    flag=0;
    goto home;
    }
    if(x == 'D')            
    {
    digitalWrite(rly1,HIGH);  
    goto home;
    }  
    if(x == 'O')            
    {
    digitalWrite(rly1,LOW);  
    goto home;
    }    
    if(x == 'P')            
    {
    digitalWrite(rly2,HIGH);  
    goto home;
    }  
    if(x == 'X')            
    {
    digitalWrite(rly2,LOW);  
    goto home;
    }    
  }  

}