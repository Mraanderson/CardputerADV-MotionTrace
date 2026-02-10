#include <M5Unified.h>
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
    M5.Display.setTextSize(2);

    for (int i = 0; i < menuCount; i++) {
        if (i == menuIndex) {
            M5.Display.setTextColor(YELLOW);
        } else {
            M5.Display.setTextColor(WHITE);
        }
        M5.Display.setCursor(20, 40 + i * 30);
        M5.Display.println(menuItems[i]);
    }
}

void showMainMenu() {
    drawMenu();

    while (true) {
        M5.update();

        if (M5.BtnA.wasPressed()) {
            menuIndex--;
            if (menuIndex < 0) menuIndex = menuCount - 1;
            drawMenu();
        }

        if (M5.BtnC.wasPressed()) {
            menuIndex++;
            if (menuIndex >= menuCount) menuIndex = 0;
            drawMenu();
        }

        if (M5.BtnB.wasPressed()) {
            switch (menuIndex) {
                case 0:
                    startIMUMode();
                    break;

                case 1:
                    // Placeholder: Phone GPS mode
                    // TODO: Implement Bluetooth GPS receiver
                    showPhoneGPSInfo();
                    break;

                case 2:
                    // Placeholder: External GPS mode
                    // TODO: Implement UART GPS reader
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
