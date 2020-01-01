#include <RTClib.h>

const int PinCLK = 2;
const int PinDT = 3;
const int PinSW = 5;
int sayac = 0;
int durum = 0;
int sondurum = 0;
String isim = "M&C";
RTC_DS1307 rtc;

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
char dayOfTheWeek[7][12]={"Pazar", "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumartesi"};

void setup() {
  rtc.begin();
  rtc.adjust(DateTime(2019, 12, 13, 22, 59, 0));
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
  DateTime now =rtc.now();
  
  durum = digitalRead(PinCLK);
  if (digitalRead(PinSW) == 0)
    {
      sayac = 0;
      Serial.println("Butona basildi");
      Serial.println(sayac);
      Serial.print(now.day(), DEC);
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

DateTime now = rtc.now();
    Serial.println(sayac);
    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(sayac, (sayac / 2));
    display.print(now.year(), DEC);
    display.print("/");
    display.print(now.month(), DEC);
    display.print("/");
    display.print(now.day(), DEC);
    display.display();


  }
