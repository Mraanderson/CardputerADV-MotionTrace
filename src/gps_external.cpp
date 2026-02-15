#include <M5Unified.h>
#include <M5Cardputer.h>
#include "gps_external.h"

void showExternalGPSInfo() {
    M5.Display.fillScreen(BLACK);
    M5.Display.setCursor(10, 20);
    M5.Display.setTextSize(2);
    M5.Display.println("External GPS");

    M5.Display.setTextSize(1);
    M5.Display.setCursor(10, 60);
    M5.Display.println("Coming Soon");
    M5.Display.println("");
    M5.Display.println("Supported modules:");
    M5.Display.println("- M5Stack GPS Cap");
    M5.Display.println("- NEO-6M / NEO-M8N UART");
    M5.Display.println("");
    M5.Display.println("Press Del to return.");

    while (true) {
        M5Cardputer.update();
        if (M5Cardputer.Keyboard.isKeyPressed(KEY_BACKSPACE)) return;
    }
}
