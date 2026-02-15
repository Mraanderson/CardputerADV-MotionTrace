#include <M5Unified.h>
#include <M5Cardputer.h>
#include "imu_mode.h"

// TODO: Add SD logging
// TODO: Add CSV writer
// TODO: Add Bluetooth streaming

void startIMUMode() {
    M5.Display.fillScreen(BLACK);
    M5.Display.setCursor(10, 15);
    M5.Display.setTextSize(2);
    M5.Display.println("IMU Mode");

    M5.Display.setTextSize(1);
    M5.Display.setCursor(10, 50);
    M5.Display.println("Reading accelerometer...");
    M5.Display.setCursor(10, 65);
    M5.Display.println("Press Del to exit.");

    float ax, ay, az;
    float gx, gy, gz;
    float temp;

    while (true) {
        M5Cardputer.update();
        if (M5Cardputer.Keyboard.isKeyPressed(KEY_BACKSPACE)) break;

        M5.Imu.getAccel(&ax, &ay, &az);
        M5.Imu.getGyro(&gx, &gy, &gz);
        M5.Imu.getTemp(&temp);

        // Clear the data area before drawing to prevent leftover characters
        M5.Display.fillRect(0, 90, 240, 60, BLACK);

        // Set cursor for each line to ensure proper alignment
        // Using %6.2f provides padding to keep numbers aligned
        M5.Display.setCursor(10, 90);
        M5.Display.printf("AX: %6.2f   GX: %6.2f", ax, gx);
        M5.Display.setCursor(10, 105);
        M5.Display.printf("AY: %6.2f   GY: %6.2f", ay, gy);
        M5.Display.setCursor(10, 120);
        M5.Display.printf("AZ: %6.2f   GZ: %6.2f", az, gz);

        delay(150);
    }
}
