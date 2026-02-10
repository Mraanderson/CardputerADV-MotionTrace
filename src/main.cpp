#include <M5Unified.h>
#include "menu.h"

void setup() {
    auto cfg = M5.config();
    M5.begin(cfg);

    // Splash screen
    M5.Display.fillScreen(BLACK);
    M5.Display.setTextColor(WHITE);
    M5.Display.setTextSize(2);
    M5.Display.setCursor(20, 40);
    M5.Display.println("MotionTrace ADV");
    M5.Display.setTextSize(1);
    M5.Display.setCursor(20, 80);
    M5.Display.println("v0.1 - IMU Mode Ready");
    delay(2000);

    showMainMenu();
}

void loop() {
    // Menu system handles its own loops
}
