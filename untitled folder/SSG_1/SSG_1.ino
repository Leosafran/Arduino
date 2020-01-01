int Buton= 12;
int vssin=13;
int butondurum;
int sayac=0;

void setup() {
  pinMode (Buton, INPUT);
  pinMode(vssin, OUTPUT);
  
  Serial.begin(9600);
  for (int ssgpin =2; ssgpin<=9; ssgpin++)
  {
  pinMode (ssgpin, OUTPUT);
  }
  digitalWrite(vssin, HIGH);
}
const int number[11] = {0b01111111, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000};
void loop(){
  butondurum=digitalRead(Buton);
if (butondurum== HIGH){
 delay(10);
 for(sayac;sayac<=11;sayac++)
 Serial.println(sayac);
 while(butondurum == HIGH){ 
     butondurum = digitalRead(Buton);
     
 }
 
} 
 /*
 for (int tens = 0; tens < 10; tens++)

  {
    display_tens(0);
    delay(500);
  }
*/

}
void display_tens(const int tens)
{
  int pin1, a, ones;     
  //pin1 is just used to deal with pins of the 1st SSD which desplays the tens digit

  for (pin1 = 2, a = 0; pin1 <= 9; pin1++, a++)
  {
    digitalWrite(pin1, bitRead(number[tens], a));
  }
  
}
