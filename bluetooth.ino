#define max_char 12
char message[max_char];    
char r_char;               
byte index = 0;            

int redPin = 11;     
int greenPin = 10;   
int bluePin = 9;     

int redValue = 255;     
int greenValue = 255;   
int blueValue = 255;    

String redTempValue;     
String greenTempValue;   
String blueTempValue;     

int flag = 0;
char currentColor;  

void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  while(Serial.available() > 0){
    flag = 0;
   
    if(index < (max_char-1)){         
      r_char = Serial.read();      
      message[index] = r_char;     
      if(r_char=='R'){
         currentColor = 'R';
         redTempValue = "";
      }
      else if(r_char=='G'){
         currentColor = 'G';
         greenTempValue = "";
      }
      else if(r_char=='B'){
         currentColor = 'B';
         blueTempValue = "";
      }
      if(currentColor == 'R' && r_char!='R'){
         redTempValue += r_char;
      }
      else if(currentColor == 'G' && r_char!='G'){
         greenTempValue += r_char;
      }
      else if(currentColor == 'B' && r_char!='B'){
         blueTempValue += r_char;
      }
      index++;                     
      message[index] = '\0';     
   }
   
 }
 
 if(flag == 0){
   analogWrite(redPin, 255-redTempValue.toInt());
   analogWrite(greenPin, 255-greenTempValue.toInt());
   analogWrite(bluePin, 255-blueTempValue.toInt());
   /*Serial.print('R');
   Serial.println(redTempValue);
   Serial.print('G');
   Serial.println(greenTempValue);
   Serial.print('B');
   Serial.println(blueTempValue);
   Serial.print("MESSAGE ");*/
   Serial.println(message);
   flag=1;
       for(i=0; i<12; i++){
      message[i] = '\0';
    } 
   
    index=0;  
 }

}
