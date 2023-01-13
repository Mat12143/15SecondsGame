#include <LiquidCrystal.h>

//15 secondi Game
//by Mat12143, Tesohh and Riccardo
//ATTENZIONE può creare dipendenza
//versione 1.2

#include <LiquidCrystal.h>    //libreria del Display
LiquidCrystal lcd(12,11,5,4,3,2);   //inizializziamo la libreria

float tempo = 0;    
int pulsante = 0;
float risultato = 0;

void setup() {
  pinMode(13,INPUT); //bottone
  pinMode(10,OUTPUT); //verde
  pinMode(9,OUTPUT); //gialla
  pinMode(8,OUTPUT);//rossa
  lcd.begin(16,2);
}

void loop() {
  digitalWrite(10,LOW);   //luce verde spenta
  digitalWrite(9,LOW);    //luce gialla spenta
  digitalWrite(8,LOW);    //luce rossa spenta
  lcd.print("15 Secondi Game");   //Homepage del gioco
  lcd.setCursor(0,1);
  lcd.print("Premi START");
  delay(100);
  pulsante = digitalRead(13);   //lettura pulsante

  while(pulsante==LOW){
      pulsante = digitalRead(13);   //non fa niente qunado il pulsante non è premuto
  }
  
  lcd.clear();    //puliamo il Display
  
  while(pulsante==HIGH){
    pulsante = digitalRead(13);   //se il pulsante è premuto fai...
  }
  
  lcd.setCursor(1,0);
  lcd.print("Timer partito!");    //...scrivere "Timer Partito!"
  lcd.setCursor(7,1);
  lcd.print(";)");
  //treDueUno();
  tempo=millis();   //millis conta i millisecondi da quando viene chiamata
  
  while(pulsante==LOW){
    pulsante=digitalRead(13);
  }
    risultato=(millis()-tempo)/1000;  
    lcd.clear();
    
    if (risultato <15.2 and risultato > 14.8){   //se il risultato è compreso tra 15.20 e 14.80 accendi la luce verde
      digitalWrite(10,HIGH);
    }
    
    else if (risultato <16.3 and risultato > 13.3){   //se il risultato è compreso tra 16.30 e 13.30 accendi la luce gialla
      digitalWrite(9,HIGH);
    }
    else if (risultato <1){   //Easter Egg: se il risulato è minore di 1...
      digitalWrite(9,HIGH);   //accendi la luce gialla
      digitalWrite(10,HIGH);  //accendi la luce verde
      digitalWrite(8,HIGH);   //accendi la luce rossa
      lcd.clear();
      lcd.print("Easter Egg!!");    //scrivi Easter Egg e asgarra Testmat
      lcd.setCursor(0,1);
      lcd.print("Asgarra Tesmat");
      delay(4000);
      lcd.clear();
    }
    else{
      digitalWrite(8,HIGH);
    }
    lcd.print("Risultato:");
    lcd.setCursor(0,1);
    lcd.print(risultato);
    delay(3000);
    lcd.clear();
    lcd.print("Record:");
    lcd.setCursor(0,1);
    lcd.print("15.02");
    delay(1500);
    lcd.clear();
    lcd.print("di -------");
    delay(1000);
    lcd.clear();
    
  while(pulsante==HIGH){
    pulsante = digitalRead(13);
  }
  delay(1000);
  lcd.clear();
}
