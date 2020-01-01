int buton1=2;
void setup()
{
  for (int i = 3; i <= 6; i++)
    pinMode(i, OUTPUT); //Set all pins from 0 to 13 as OUTPUT
    Serial.begin(9600);
    pinMode(LED_BUILTIN,OUTPUT);
    digitalWrite(LED_BUILTIN,LOW);
    pinMode(buton1, INPUT_PULLUP);
    
}
//Aşağıdaki satır, 0'dan 9'a kadar bir SSD'deki rakamlar için tüm ikili sayıları içeren diziyi oluşturma çabalarının ürünüdür :) (ssd =seven segment display)
const int number[13] = {0b0000,0b0001,0b0010,0b0011,
                        0b0100,0b0101,0b0110,0b0111,
                        0b1000,0b1001,0b1010,0b1011,
                        0b1111};

void loop()
{
  
 
  
    for (int tens = 0; tens < 13; tens++)

  {
      
    display_tens(tens);
    delay(1200);
     
  }
     //delay(2000);
}

void display_tens(const int tens)
{
  int pin1, a, ones;     
  //pin1  1.SSD'nin pinleri ile alakalıdır.

  for (pin1 =3, a = 0; pin1 < 7; pin1++, a++)
  {
    digitalWrite(pin1, bitRead(number[tens], a));
     
    
  }
  attachInterrupt(0, effect, LOW);
}
void effect()
{  
  for( int i=0;i<5;i++)
 { display_tens(0);
  delay(100);
  display_tens(12);
  delay(100);
 }
  


}
