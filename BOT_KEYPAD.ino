#include <Key.h>
#include <Keypad.h>

const byte row=4;
const byte column=4;
char key[row][column]={{'1', '2', '3','U'}, 
                       {'4', '5', '6', 'D'}, 
                       {'7', '8', '9', 'R'}, 
                       {'*', '0', 'S', 'L'}};
byte rowPins[row]={2, 3, 4, 5};
byte colPins[column]={0,0 ,11,6};
Keypad keypad=Keypad(makeKeymap(key), rowPins, colPins, row, column);

#define motorpin1 7
#define motorpin2 8
#define motorpin3 9
#define motorpin4 10

void setup() {
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  char state=keypad.getKey();

  while(Serial.available()){
    char c=Serial.read();
    if(c=='#')
    {break;}
    state+=c;
  }
  Serial.println(state);
    if(state=='D')
  
  { digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
    digitalWrite(motorpin3, HIGH);
    digitalWrite(motorpin4, LOW);
   }
  if(state=='S')
  { digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
    digitalWrite(motorpin3, LOW);
    digitalWrite(motorpin4, LOW);
   }

  if(state=='U')
  { digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
    digitalWrite(motorpin3, LOW);
    digitalWrite(motorpin4, HIGH);
   }
  
  if(state=='L')
  { digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
    digitalWrite(motorpin3, LOW);
    digitalWrite(motorpin4, HIGH);
   }
  if(state=='R')
  {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
    digitalWrite(motorpin3, LOW);
    digitalWrite(motorpin4, LOW);
   }
   
  // put your main code here, to run repeatedly:

    }
