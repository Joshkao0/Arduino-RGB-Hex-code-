#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int potPin = A0;

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  int val = analogRead(potPin);

  // Hue 0–360
  float hue = map(val, 0, 1023, 0, 360);

  int r, g, b;
  hsvToRgb(hue, 1.0, 1.0, r, g, b);

  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);

  // HEX berechnen
  char hex[8];
  sprintf(hex, "#%02X%02X%02X", r, g, b);

  // OLED anzeigen
  display.clearDisplay();
  display.setCursor(0, 0);

  display.print("RGB Mixer");
  display.setCursor(0, 15);
  display.print("R: "); display.println(r);
  display.print("G: "); display.println(g);
  display.print("B: "); display.println(b);

  display.setCursor(0, 45);
  display.print(hex);

  display.display();

  delay(50);
}

// HSV → RGB Umrechnung
void hsvToRgb(float h, float s, float v, int &r, int &g, int &b) {
  float c = v * s;
  float x = c * (1 - abs(fmod(h / 60.0, 2) - 1));
  float m = v - c;

  float rp, gp, bp;

  if (h < 60)      { rp = c; gp = x; bp = 0; }
  else if (h <120) { rp = x; gp = c; bp = 0; }
  else if (h <180) { rp = 0; gp = c; bp = x; }
  else if (h <240) { rp = 0; gp = x; bp = c; }
  else if (h <300) { rp = x; gp = 0; bp = c; }
  else             { rp = c; gp = 0; bp = x; }

  r = (rp + m) * 255;
  g = (gp + m) * 255;
  b = (bp + m) * 255;
}