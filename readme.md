# ESP32-S3-Box-3 Boilerplate

## Overview

This is a boilerplate setup for the **ESP32-S3-Box-3** development kit, designed to work seamlessly with **PlatformIO**.  

Key features:  
- Custom **ESP32-S3-Box-3 board definition** for PlatformIO

This boilerplate allows you to start developing quickly without manually configuring pins or peripherals.

---

## Getting Started

### PlatformIO

1. **Install PlatformIO**: [https://platformio.org/install](https://platformio.org/install)  
2. **Create a new project**:
   - Select the **ESP32-S3-Box-3** custom board.
   - Choose **Arduino** or **ESP-IDF** as the framework.
3. Copy `partitions.csv`, `include/*`, `boards/*` and `platformio.ini` to your project directory.
4. **Build and upload** your code to the ESP32-S3-Box-3.

---

## Example

```cpp
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32-S3-Box-3 Boilerplate!");
}

void loop() {
  // Your code here
}
```

#### Notes

* Compatible with Arduino sketches or ESP-IDF projects.
* Designed for rapid development with minimal setup.
* Referenced from [liusida/ESP32-S3-Box-3-with-Platformio-Arduino-ESPIDF](https://github.com/liusida/ESP32-S3-Box-3-with-Platformio-Arduino-ESPIDF)
* moononournation/GFX Library for Arduino@1.6.1 has a bug which doesnt allow PIO to compile for esp32. Editing line 58 and 59 on file `.pio/libdeps/esp32s3box3/GFX Library for Arduino/src/databus/Arduino_ESP32RGBPanel.h` like below works as suggested in [github comment](https://github.com/moononournation/Arduino_GFX/issues/711#issuecomment-3210016026)
    ```cpp
    #if (!defined(ESP_ARDUINO_VERSION_MAJOR)) || (ESP_ARDUINO_VERSION_MAJOR < 3)
    // #if (!defined(ESP_ARDUINO_VERSION_MAJOR)) || (ESP_ARDUINO_VERSION_MAJOR >5)
    ```