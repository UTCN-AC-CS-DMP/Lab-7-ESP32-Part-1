#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128  // Lățime afișor OLED, în pixeli
#define SCREEN_HEIGHT 32  // Înălțime afișor OLED, în pixeli

// Declararea afișorului SSD1306, conectat la pinii I2C (SDA, SCL)
// Pinii sunt definiți de biblioteca Wire.
// La Arduino UNO: A4(SDA), A5(SCL)
// La Arduino MEGA: 20(SDA), 21(SCL)
// La ESP 32: 21 (SDA), 22 (SCL)
#define OLED_RESET -1

// Numărul pinului de reset (-1 dacă se folosește pinul reset al plăcii)
#define SCREEN_ADDRESS 0x3C

// Adresa I2C pentru afișorul OLED, 0x3D pentru 128x64, 0x3C pentru 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_WIDTH 128
#define LOGO_HEIGHT 32
// 'logo_utcn', 128x32px
static const unsigned char PROGMEM logo_bmp[] = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f,
  0x80, 0x00, 0x7f, 0x00, 0x00, 0xfe, 0x00, 0x01, 0xfc, 0x00, 0x03, 0xff,
  0xff, 0xfe, 0x07, 0xff, 0xfc, 0x0f, 0xff, 0xf8, 0x1f, 0xff, 0xf0, 0x3f,
  0xff, 0xe0, 0x7f, 0xff, 0xff, 0xc2, 0x04, 0x3f, 0x84, 0x08, 0x7f, 0x08,
  0x10, 0xfe, 0x10, 0x21, 0xfc, 0x20, 0x43, 0xff, 0xff, 0xc2, 0x04, 0x3f,
  0x84, 0x08, 0x7f, 0x08, 0x10, 0xfe, 0x10, 0x21, 0xfc, 0x20, 0x43, 0xff,
  0xff, 0xc2, 0x04, 0x3f, 0x84, 0x08, 0x7f, 0x08, 0x10, 0xfe, 0x10, 0x21,
  0xfc, 0x20, 0x43, 0xff, 0xff, 0xc2, 0x04, 0x3f, 0x84, 0x08, 0x7f, 0x08,
  0x10, 0xfe, 0x10, 0x21, 0xfc, 0x20, 0x43, 0xff, 0xff, 0xc2, 0x04, 0x3f,
  0x84, 0x08, 0x7f, 0x08, 0x10, 0xfe, 0x10, 0x21, 0xfc, 0x20, 0x43, 0xff,
  0xff, 0xe2, 0x04, 0x7f, 0xc4, 0x08, 0xff, 0x88, 0x11, 0xff, 0x10, 0x23,
  0xfe, 0x20, 0x47, 0xff, 0xff, 0xe2, 0x04, 0x7f, 0xc4, 0x08, 0xff, 0x88,
  0x11, 0xff, 0x10, 0x23, 0xfe, 0x20, 0x47, 0xff, 0xff, 0xf2, 0x04, 0xff,
  0xe4, 0x09, 0xff, 0xc8, 0x13, 0xff, 0x90, 0x27, 0xff, 0x20, 0x4f, 0xff,
  0xff, 0xfa, 0x05, 0xff, 0xf4, 0x0b, 0xff, 0xe8, 0x17, 0xff, 0xd0, 0x2f,
  0xff, 0xa0, 0x5f, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xfc, 0x0f, 0xff, 0xf8,
  0x1f, 0xff, 0xf0, 0x3f, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xf1,
  0xff, 0xf8, 0x00, 0x7f, 0xff, 0xc0, 0xff, 0xff, 0x0f, 0x0f, 0xff, 0xff,
  0xff, 0xff, 0xe1, 0xf1, 0xff, 0xf8, 0x00, 0x7f, 0xff, 0x00, 0x7f, 0xff,
  0x07, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xf1, 0xff, 0xff, 0x87, 0xff,
  0xfe, 0x1e, 0x7f, 0xff, 0x07, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xf1,
  0xff, 0xff, 0x87, 0xff, 0xfe, 0x3f, 0x7f, 0xff, 0x03, 0x0f, 0xff, 0xff,
  0xff, 0xff, 0xe1, 0xf1, 0xff, 0xff, 0x87, 0xff, 0xfc, 0x3f, 0xff, 0xff,
  0x01, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xf1, 0xff, 0xff, 0x87, 0xff,
  0xfc, 0x7f, 0xff, 0xff, 0x11, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xf1,
  0xff, 0xff, 0x87, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0x10, 0x0f, 0xff, 0xff,
  0xff, 0xff, 0xe1, 0xf1, 0xff, 0xff, 0x87, 0xff, 0xfc, 0x7f, 0xff, 0xff,
  0x18, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xf1, 0xff, 0xff, 0x87, 0xff,
  0xfc, 0x3f, 0xff, 0xff, 0x1c, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xf1,
  0xff, 0xff, 0x87, 0xff, 0xfc, 0x3f, 0x7f, 0xff, 0x1c, 0x0f, 0xff, 0xff,
  0xff, 0xff, 0xf0, 0xe1, 0xff, 0xff, 0x87, 0xff, 0xfe, 0x1e, 0x7f, 0xff,
  0x1e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x03, 0xff, 0xff, 0x87, 0xff,
  0xff, 0x00, 0x7f, 0xff, 0x1e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f,
  0xff, 0xff, 0x87, 0xff, 0xff, 0xc0, 0xff, 0xff, 0x1f, 0x0f, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

void setup() {
  Serial.begin(9600);
  // SSD1306_SWITCHCAPVCC = generare tensiune pentru afișaj din tensiunea internă de 3.3V
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Nu continua, blochează programul aici
  }
  
  // Șterge afișaj
  display.clearDisplay();
  
  // Desenează logo demo
  testDrawUTCNLogo();
  
  // Scrie șiruri de caractere pe rânduri diferite
  writeTextSSD1306("First line", 0, 1, true);
  writeTextSSD1306("Another string below", 8, 1, false);
  // Întărziere 3 secunde
  delay(3000);
  // Text cu dimensiune mai mare, se trece automat la linia următoare
  writeTextSSD1306("Auto line break", 0, 2, true);
  delay(3000);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.write("Waiting");
}

int c = 0;
void loop() {
  display.write(".");
  display.display();
  delay(1000);
  c++;
  if (c > 13) {
    display.clearDisplay();
    display.setCursor(0, 0);
    c = 0;
  }
}

void writeTextSSD1306(const String &message, const uint8_t rowNum, const uint8_t textSize,
                      const bool clearDisp) {
  if (clearDisp) {
    display.clearDisplay();
  }
  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);  // Desenează text alb
  // Specifică poziția mesajului
  display.setCursor(0, rowNum);
  // Folosește fontul complet pentru 256 caractere 'Code Page 437'
  display.cp437(true);
  display.write(message.c_str());
  display.display();
}

void testDrawUTCNLogo(void) {
  display.clearDisplay();
  display.drawBitmap(0, 0, logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, WHITE);
  display.display();
  delay(3000);
}
