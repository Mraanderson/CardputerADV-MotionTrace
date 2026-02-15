#include <M5Unified.h>
#include <M5Cardputer.h>
#include "info.h"

void showInfoMenu() {
    M5.Display.fillScreen(BLACK);
    M5.Display.setCursor(10, 20);
    M5.Display.setTextSize(2);
    M5.Display.println("Info");

    M5.Display.setTextSize(1);
    M5.Display.setCursor(10, 60);
    M5.Display.println("MotionTrace ADV");
    M5.Display.println("");
    M5.Display.println(" IMU Mode: Ready");
    M5.Display.println(" Phone GPS: Coming Soon");
    M5.Display.println(" External GPS: Coming Soon");
    M5.Display.println("");
    M5.Display.println(" v0.1");
    M5.Display.println(" Press Del to return.");

    while (true) {
        M5Cardputer.update();
        if (M5Cardputer.Keyboard.isKeyPressed(KEY_BACKSPACE)) return;
    }
}
