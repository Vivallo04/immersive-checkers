// C++ code
//
#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 4; //Four rows
const byte COLS = 4; //Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'S','0','H','D'}
};

const byte ROWS2 = 4;
const byte COLS2 = 4;
char keys2[ROWS2][COLS2]={
  {'A','B','C','0'},
  {'D','E','F','0'},
  {'G','H','0','0'},
  {'0','0','0','0'},
};



byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad



Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

Keypad keypad2 = Keypad( makeKeymap(keys2), rowPins, colPins, ROWS2, COLS2 );


String character = '';
String number='';
String position = '';

void setup(){
  Serial.begin(9600);

  pinMode(13,OUTPUT);//Activa pin13

  
}

void loop(){
  
  //Serial.println(key);
  //char characterkey= keypad2.getKey();
  char key = keypad.getKey();
  if (key != NO_KEY ){
    //Serial.println(characterkey);
    Serial.println(key);
    
    //v_passcode = v_passcode + key;
    
    if(key==1)
    {
      key ='A';
      //Guardarlo en una variable
       // v_passcode="";
    }

    if(key==2)
    {
      key ='B';
    
       // v_passcode="";
    }
    if(key==3)
    {
      key ='C';
    
       // v_passcode="";
    }
    if(key==4)
    {
      key ='D';
    
       // v_passcode="";
    }
    if(key==5)
    {
      key ='E';
    
       // v_passcode="";
    }
    if(key==6)
    {
      key ='F';
    
       // v_passcode="";
    }
    if(key==7)
    {
      key ='G';
    
       // v_passcode="";
    }
    if(key==8)
    {
      key ='H';
    
       // v_passcode="";
    }
    
  }

/*

    if(key=='D')
    {
      Serial.println("Validate the Password");
      Serial.println(v_passcode);
        
        if (v_passcode=="589D")
        {
          Serial.println("Access Granted");
          digitalWrite(13,HIGH);
          delay(5000); // Espera 500 ms
          digitalWrite(13, LOW); // Apaga fuente pin 13
          delay(500); // Espera 500 ms
        }
        else
        {
          Serial.println("Access Denied");
        }      
    }        
  }
*/






/*void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);//Declaramos el pin 13 como salida


  //Matrix of 4x4 provided by the keypad
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
  

}
*/
