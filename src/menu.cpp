#include <M5Unified.h>
#include <M5Cardputer.h>
#include "menu.h"
#include "imu_mode.h"
#include "gps_phone.h"
#include "gps_external.h"
#include "info.h"

static int menuIndex = 0;

const char* menuItems[] = {
    "ADV Mode (IMU Only)",
    "Phone GPS (Coming Soon)",
    "GPS Cap / External (Coming Soon)",
    "Info",
};

const int menuCount = sizeof(menuItems) / sizeof(menuItems[0]);

void drawMenu() {
    M5.Display.fillScreen(BLACK);
    M5.Display.setTextSize(1);

    for (int i = 0; i < menuCount; i++) {
        if (i == menuIndex) {
            M5.Display.setTextColor(YELLOW);
        } else {
            M5.Display.setTextColor(WHITE);
        }
        M5.Display.setCursor(20, 40 + i * 20);
        M5.Display.println(menuItems[i]);
    }
}

void showMainMenu() {
    drawMenu();

    while (true) {
        M5Cardputer.update();

        if (M5Cardputer.Keyboard.isChange() && M5Cardputer.Keyboard.isPressed()) {
            if (M5Cardputer.Keyboard.isKeyPressed(';')) { // Up Arrow
                menuIndex--;
                if (menuIndex < 0) menuIndex = menuCount - 1;
                drawMenu();
            }

            if (M5Cardputer.Keyboard.isKeyPressed('.')) { // Down Arrow
                menuIndex++;
                if (menuIndex >= menuCount) menuIndex = 0;
                drawMenu();
            }

            if (M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER)) {
                switch (menuIndex) {
                    case 0:
                        startIMUMode();
                        break;
                    case 1:
                        showPhoneGPSInfo();
                        break;
                    case 2:
                        showExternalGPSInfo();
                        break;
                    case 3:
                        showInfoMenu();
                        break;
                }
                drawMenu();
            }
        }
    }
}
