//JUCATOR 1 - albastru
//JUCATOR 2 - rosu
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Wire.h>

int Contrast=75;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

char raspunsJUC2;
int player=0;
char key;
int ok = 0;
int nok = 0;
bool primire = false;
int verif;

int grid[3][3] = {
  {0,0,0},
  {0,0,0},
  {0,0,0},
};

int isWin = 0;

const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {14, 15, 16, 17}; 
byte colPins[COLS] = {18, 19, 10}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

int redPin22= 22 ;
int greenPin24 = 24 ;
int bluePin26 = 26;

int redPin28= 28 ;
int greenPin30 = 30;
int bluePin32 = 32;

int redPin34= 34 ;
int greenPin36 = 36;
int bluePin38 = 38;

int redPin40= 40 ;
int greenPin42 = 42;
int bluePin44 = 44;

int redPin46= 46 ;
int greenPin48 = 48;
int bluePin50 = 50;

int redPin52= 52 ;
int greenPin3 = 3;
int bluePin2 = 2;

int redPin31= 31 ;
int greenPin33 = 33;
int bluePin35 = 35;

int redPin37= 37 ;
int greenPin39 = 39;
int bluePin41 = 41;


int redPin43= 43 ;
int greenPin45 = 45;
int bluePin47 = 47;


void setup() {
  Serial.begin(9600);
  

  analogWrite(12,Contrast);
  lcd.begin(16, 2);

  pinMode(redPin22, OUTPUT);
  pinMode(greenPin24, OUTPUT);
  pinMode(bluePin26, OUTPUT);

  pinMode(redPin28, OUTPUT);
  pinMode(greenPin30, OUTPUT);
  pinMode(bluePin32, OUTPUT);

  pinMode(redPin34, OUTPUT);
  pinMode(greenPin36, OUTPUT);
  pinMode(bluePin38, OUTPUT);

  pinMode(redPin40, OUTPUT);
  pinMode(greenPin42, OUTPUT);
  pinMode(bluePin44, OUTPUT);

  pinMode(redPin46, OUTPUT);
  pinMode(greenPin48, OUTPUT);
  pinMode(bluePin50, OUTPUT);

  pinMode(redPin52, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(bluePin32, OUTPUT);

  pinMode(redPin31, OUTPUT);
  pinMode(greenPin33, OUTPUT);
  pinMode(bluePin35, OUTPUT);

  pinMode(redPin37, OUTPUT);
  pinMode(greenPin39, OUTPUT);
  pinMode(bluePin41, OUTPUT);

  pinMode(redPin43, OUTPUT);
  pinMode(greenPin45, OUTPUT);
  pinMode(bluePin47, OUTPUT);

  
  //9 - adresa JUCATORULUI 1
  Wire.begin(9); //Se porneste I2C master, adresa 9
  Wire.onReceive(citireSecondPlayer); 

}

void loop() {

  FirstPlayer();
  afisMatrice();
  verif_castig();
  castig();
}

//functia pentru LED-urile RGB
void setColor(int red,int green, int blue,int redValue, int greenValue, int blueValue) {
  analogWrite(red, redValue);
  analogWrite(green, greenValue);
  analogWrite(blue, blueValue);

}

//Functia de PLAYER1 : Se aprind LED-urile in functie de butonul
//apasat pe KEYPAD(yellow).
//In matrice, 1 ii corespunde lui PLAYER1, iar 2 lui PLAYER2.
void FirstPlayer()
{
  if( primire == false)
  { key = customKeypad.getKey();
   Serial.println("aici");
   nok = 0;
   if(key == '1' && grid[0][0] == 0  )
    { 
     
      grid[0][0] = 1;
      verif = 2;
      
   }

     if(key == '2'&& grid[0][1] == 0 )
   {
       
      grid[0][1] = 1;
      verif = 2;
     
   }
   if(key == '3'&& grid[0][2] == 0 ) 
    {
        
        grid[0][2] = 1;
        verif = 2;
       
     }

    if(key == '4'&& grid[1][0] == 0 )
    {
     
      grid[1][0] = 1;
      verif = 2;
      
    }

    if(key == '5'&& grid[1][1] == 0  )
    {
        
       grid[1][1] = 1;
       verif = 2;
    
   }

     if(key == '6'&& grid[1][2] == 0)
    {
      
      grid[1][2] = 1;
      verif = 2;
     
   }

     if(key == '7'&& grid[2][0] == 0 )
    {
      
      grid[2][0] = 1;
      verif = 2;
   
    }
    
    if(key == '8'&& grid[2][1] == 0  )
    {
      
      grid[2][1] = 1;
      verif = 2;
    
   }

   if(key == '9'&& grid[2][2] == 0  )
    {
     
      grid[2][2] = 1;
      verif = 2;
    
    }

  }

   if( primire == false  && verif == 2)
    {
    if( grid[0][0] == 1 )
    {
      setColor(redPin34,greenPin36, bluePin38,255, 255, 0);  // yellow
      Serial.println("yellow");
     }

    if( grid[1][0] == 1   )
    {
      setColor(redPin22,greenPin24, bluePin26,255, 255, 0);  // yellow
      Serial.println("yellow");
     }
     
    if( grid[2][0] == 1   )
    {
      setColor(redPin28,greenPin30, bluePin32,255, 255, 0);  // yellow
      Serial.println("yellow");
    }
 
    if( grid[0][1] == 1   )
    {
      setColor(redPin40,greenPin42, bluePin44,255, 255, 0);  // yellow
      Serial.println("yellow");
    }
     
    if( grid[1][1] == 1   )
    {
      setColor(redPin46,greenPin48, bluePin50,255, 255, 0);  // yellow
      Serial.println("yellow");
    }
     
    if( grid[2][1] == 1  )
    {
      setColor(redPin52,greenPin3, bluePin2,255, 255, 0);  // yellow
      Serial.println("yellow");
    }

    if( grid[0][2] == 1   )
    {
      setColor(redPin43,greenPin45, bluePin47,255, 255, 0);  // yellow
      Serial.println("yellow");
      
     }
     
    if( grid[1][2] == 1   )
    {
      setColor(redPin31,greenPin33, bluePin35,255, 255, 0);  // yellow
      Serial.println("yellow");
      
    }
     
    if( grid[2][2] == 1  )
    {
      setColor(redPin37,greenPin39, bluePin41,255, 255, 0);  // yellow
      Serial.println("yellow");}
    }
    
  if(  verif == 2 && isWin == 0 )
  {
    lcd.setCursor(0, 0);
    lcd.print("R:J2");
    Serial.println("JUCATOR 1: Am pus! E randul tau!");
   
  }
  
}

    
//Se primeste informatia pe I2C : alegerea lui PLAYER2(red).
void citireSecondPlayer(int bytes)
{
   
     String response = "";
     
     while (Wire.available()) {
         verif = 3;
         char raspunsJUC2 = Wire.read();
         response += raspunsJUC2;
         Serial.println("S-a primit alegerea lui JUCATOR 2!");
       } 

     primire = true;

      
     Serial.println("Alegerea lui JUCATOR 2 este : "+response);

     if(response == "1" && grid[0][0] == 0)
       { grid[0][0] = 2;
         nok = 1;
        Serial.println("S-a apasat butonul 1!");
         }

     if(response == "2"&& grid[0][1] == 0 )
        {grid[0][1] = 2;
         nok = 1;
        Serial.println("S-a apasat butonul 2");
       }

     if(response == "3"&& grid[0][2] == 0 )
       { grid[0][2] = 2;
         nok = 1;
        Serial.println("S-a apasat butonul 3");
       }
     if(response == "4"&& grid[1][0] == 0 )
        {grid[1][0] = 2;
         nok = 1;
        Serial.println("S-a apasat butonul 4");
       }
     if(response == "5" && grid[1][1] == 0 )
        {grid[1][1] = 2;
         nok = 1;
        Serial.println("S-a apasat butonul 5");
        }
        
     if(response == "6" && grid[1][2] == 0 )
        {grid[1][2] = 2;
         nok = 1;
         Serial.println("S-a apasat butonul 6");
       }
     if(response == "7" && grid[2][0] == 0 )
        {grid[2][0] = 2;
         nok = 1;
         Serial.println("S-a apasat butonul 7");
       }
        
     if(response == "8" && grid[2][1] == 0 )
        {grid[2][1] = 2;
         nok = 1;
         Serial.println("S-a apasat butonul 8");
        }
     if(response == "9" && grid[2][2] == 0 )
        {grid[2][2] = 2;
         nok = 1;
         Serial.println("S-a apasat butonul 9");
       }
        
    if(primire == true && nok == 1)
    {if( grid[0][0] == 2  )
    {
      setColor(redPin34,greenPin36, bluePin38,255, 0, 0);  // red
      Serial.println("red");
      ok = 1;   
     
    }

    if( grid[1][0] == 2 )
    {
      setColor(redPin22,greenPin24, bluePin26,255, 0, 0);// red
      Serial.println("red");
      ok = 1;
      
     }
     
    if( grid[2][0] == 2  )
    {
      setColor(redPin28,greenPin30, bluePin32,255, 0, 0);  // red
     Serial.println("red");
     ok = 1;
    
     
    }
 
    if( grid[0][1] == 2  )
    {
      setColor(redPin40,greenPin42, bluePin44,255, 0, 0);  // red
     Serial.println("red");
      ok = 1;
     
    }
    
    if( grid[1][1] == 2  )
    {
      setColor(redPin46,greenPin48, bluePin50,255, 0, 0);  // red
     Serial.println("red");
      ok = 1;
      
      
    }
    
    if( grid[2][1] == 2 )
    {
      setColor(redPin52,greenPin3, bluePin2,255, 0, 0);  // red
     Serial.println("red");
      ok = 1;
   
    }

    if( grid[0][2] == 2 )
    {
      setColor(redPin43,greenPin45, bluePin47,255, 0, 0);  // red
     Serial.println("red");
      ok = 1;
      
     
     }
     
    if( grid[1][2] == 2 )
    {
      setColor(redPin31,greenPin33, bluePin35,255, 0, 0);  // red
      Serial.println("red");
      ok = 1;
 
      
     }
    
    if( grid[2][2] == 2 )
    {
      setColor(redPin37,greenPin39, bluePin41,255, 0, 0);  // red
     Serial.println("red");
      ok = 1;
    
      
    }

    }

   if( ok == 1 && isWin == 0 )
   {
    lcd.setCursor(0, 0);
    lcd.print("R:J1");
    primire = false;
    ok = 0;
   }
    
}

//O functie care imi afiseaza matricea( am facut-o pentru 
//a testa daca fiecare buton/buton de pe keypad corespunde
//unui anumit PLAYER.
void afisMatrice()
{
  Serial.println("Matricea este:");
  Serial.print(grid[0][0]);
  Serial.print(" ");
  Serial.print(grid[0][1]);
  Serial.print(" ");
  Serial.println(grid[0][2]);

  Serial.print(grid[1][0]);
  Serial.print(" ");
  Serial.print(grid[1][1]);
  Serial.print(" ");
  Serial.println(grid[1][2]);

  Serial.print(grid[2][0]);
  Serial.print(" ");
  Serial.print(grid[2][1]);
  Serial.print(" ");
  Serial.println(grid[2][2]);
  Serial.println("Final matrice");
}

//Daca avem un castigator, se va afisa pe LCD "W:" urmat de "J2" daca a castigat jucatorul 2
// sau "J1" daca a castigat PLAYER1.
void castig()
{
     if(isWin ==  1)
      {lcd.setCursor(0, 1);
      if( player == 2)
            lcd.print("W:J2");
      if( player == 1)
             lcd.print("W:J1");}
      
}

//Daca exista o linie/coloana/diagonala cu aceeasi culoare, avem un castigator.
void verif_castig()
{
  //linie
 
  if( grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]
  
      && grid[0][0]!=0 && grid[0][1]!=0 && grid[0][2]!=0)
   {
    
     
      if(grid[0][0] == 2)
        player = 2;

      if(grid[0][0] == 1)
        player = 1;

      isWin = 1;
       

   }
 
 
  if( grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] 
      && grid[1][0]!=0 && grid[1][1]!=0 && grid[1][2]!=0)
   {
  
      
      if(grid[1][0] == 2)
        player = 2;
    
      if(grid[1][0] == 1)
        player = 1;

       isWin = 1;
        
  
   }

   if( grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]
        && grid[2][0]!=0 && grid[2][1]!=0 && grid[2][2]!=0)
   {
     
      
      if(grid[2][0] == 2)
     
          player = 2;
      if(grid[2][0] == 1)
        player = 1;

        isWin = 1;

   }

  //coloana
   if( grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] 
      && grid[0][0]!=0 && grid[1][0]!=0 && grid[2][0]!=0)
   {
     
      
      if(grid[2][0] == 2)
          player = 2;

      if(grid[2][0] == 1)
        player = 1;

         isWin = 1;
   }

  if( grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]
      && grid[0][1]!=0 && grid[1][1]!=0 && grid[2][1]!=0)
   {
     
      
      if(grid[2][1] == 2)
    
        player = 2;
      if(grid[2][1] == 1)
        player = 1;
       isWin = 1;
        
   }

   if( grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]
        && grid[0][2]!=0 && grid[1][2]!=0 && grid[2][2]!=0)
   {
     
      
      if(grid[0][2] == 2)
        player = 2;
    
      if(grid[0][2] == 1)
         player = 1;

         isWin = 1;

   }

   //diagonala

   if( grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]
        && grid[0][0]!=0 && grid[1][1]!=0 && grid[2][2]!=0)
   {
     
      
      if(grid[1][1] == 2)
 
        player = 2;
      if(grid[1][1] == 1)
        player = 1;

        isWin = 1;
 
   }

  if( grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]
      && grid[0][2]!=0 && grid[1][1]!=0 && grid[2][0]!=0)
   {
      
      
      if(grid[2][0] == 2)
        player = 2;
  
      if(grid[2][0] == 1)
        player = 1;

        isWin = 1;
       
   }


  
}
