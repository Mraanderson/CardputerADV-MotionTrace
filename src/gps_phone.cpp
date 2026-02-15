#include <M5Unified.h>
#include <M5Cardputer.h>
#include "gps_phone.h"

void showPhoneGPSInfo() {
    M5.Display.fillScreen(BLACK);
    M5.Display.setCursor(10, 20);
    M5.Display.setTextSize(2);
    M5.Display.println("Phone GPS");

    M5.Display.setTextSize(1);
    M5.Display.setCursor(10, 60);
    M5.Display.println("Coming Soon");
    M5.Display.println("");
    M5.Display.println("Will receive GPS via:");
    M5.Display.println("- Android Bluetooth SPP");
    M5.Display.println("- iPhone/Android BLE");
    M5.Display.println("");
    M5.Display.println("Apps to use:");
    M5.Display.println("- GPS2Bluetooth (Android)");
    M5.Display.println("- BLE GPS Streamer (iOS)");
    M5.Display.println("");
    M5.Display.println("Press Del to return.");

    while (true) {
        M5Cardputer.update();
        if (M5Cardputer.Keyboard.isKeyPressed(KEY_BACKSPACE)) return;
    }
}
