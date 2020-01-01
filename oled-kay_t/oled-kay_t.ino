const int PinCLK = 2;
const int PinDT = 3;
const int PinSW = 6;
int sayac = 0;
int durum = 0;
int sondurum = 0;
String isim = "M&C";
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup() {
  Serial.begin(9600);
  pinMode(PinCLK, INPUT);
  pinMode(PinSW, INPUT);
  pinMode(PinDT, INPUT);
  // pinMode(PinSW, INPUT);
  sondurum = digitalRead(PinCLK);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
}

void loop() {
  durum = digitalRead(PinCLK);
  if (digitalRead(PinSW) == 0)
    {
      sayac = 0;
      Serial.println("Butona basildi");
      Serial.println(sayac);
      Oledok();
    }

 else if (durum != sondurum)
  { 
    
    if (digitalRead(PinDT) != durum)
    {
      sayac++;
    }
    else
    {
      sayac--;
    }
    
    Oledok();
    

  }
  sondurum = durum;
  //RotaryRead();

}

  void Oledok() {

Serial.println(sayac);
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(sayac, (sayac / 2));
    display.println(isim);
    display.display();


  }
