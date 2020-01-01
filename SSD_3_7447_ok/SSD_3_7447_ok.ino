void setup()
{
  for (int i = 2; i <= 5; i++)
    pinMode(i, OUTPUT); //Set all pins from 0 to 13 as OUTPUT
    Serial.begin(9600);
}
//Aşağıdaki satır, 0'dan 9'a kadar bir SSD'deki rakamlar için tüm ikili sayıları içeren diziyi oluşturma çabalarının ürünüdür :) (ssd =seven segment display)
const int number[13] = {0b1111,0b0000,0b0001,0b0010,
                        0b0011,0b0100,0b0101,0b0110,
                        0b0111,0b1000,0b1001,0b1010,
                        0b1011};

void loop()
{
  for (int tens = 0; tens < 13; tens++)

  {
    display_tens(tens);
  }
}

void display_tens(const int tens)
{
  int pin1, a, ones;     
  //pin1  1.SSD'nin pinleri ile alakalıdır.

  for (pin1 =2, a = 0; pin1 < 6; pin1++, a++)
  {
    digitalWrite(pin1, bitRead(number[tens], a));
    
    
    
  }
  delay(800);
}
