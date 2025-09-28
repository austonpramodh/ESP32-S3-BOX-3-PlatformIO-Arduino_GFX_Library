#include <Arduino.h>
#include <Arduino_GFX_Library.h>

// Correct pins for ESP32-S3-BOX-3
#define LCD_BL   47
#define LCD_DC   4
#define LCD_RST  -1
#define LCD_CS   5
#define LCD_SCLK 7
#define LCD_MOSI 6

// Use SPI instead of parallel interface for Box-3
Arduino_DataBus *bus = new Arduino_ESP32SPI(
    LCD_DC, LCD_CS, LCD_SCLK, LCD_MOSI, -1 /* MISO not needed */);

Arduino_GFX *gfx = new Arduino_ILI9342(bus, LCD_RST, 0 /* rotation */, false /* IPS */);

// Configurable FPS
const int FPS = 60;           // Desired frames per second
const int frameDelay = 1000 / FPS;  // Delay per frame in milliseconds

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(LCD_BL, OUTPUT);
  digitalWrite(LCD_BL, HIGH);

  gfx->begin();
  gfx->fillScreen(BLACK);
}

void loop() {
  static uint32_t lastUpdate = 0;
  static uint32_t lastPrint = 0;
  static int x = 50;
  static int y = 50;
  static int dx = 8;  // triangle speed X
  static int dy = 8;  // triangle speed Y
  const int size = 30; // triangle size

  uint32_t now = millis();

  // Update triangle according to FPS
  if (now - lastUpdate >= frameDelay) {
    lastUpdate = now;

    // Clear only old triangle area
    gfx->fillRect(x - size/2 - 1, y - size/2 - 1, size+2, size+2, BLACK);

    // Update position
    x += dx;
    y += dy;

    // Bounce off edges
    if (x - size / 2 < 0 || x + size / 2 > gfx->width()) dx = -dx;
    if (y - size / 2 < 0 || y + size / 2 > gfx->height()) dy = -dy;

    // Draw new triangle
    int x0 = x;
    int y0 = y - size / 2;
    int x1 = x - size / 2;
    int y1 = y + size / 2;
    int x2 = x + size / 2;
    int y2 = y + size / 2;
    gfx->fillTriangle(x0, y0, x1, y1, x2, y2, RED);
  }

  // Print debug every 2 seconds
  if (now - lastPrint > 2000) {
    lastPrint = now;
    Serial.println("Looping...");
  }
}