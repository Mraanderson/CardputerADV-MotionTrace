#include <M5Unified.h>
#include "imu_mode.h"

// TODO: Add SD logging
// TODO: Add CSV writer
// TODO: Add Bluetooth streaming

void startIMUMode() {
    M5.Display.fillScreen(BLACK);
    M5.Display.setCursor(10, 20);
    M5.Display.setTextSize(2);
    M5.Display.println("IMU Mode");

    M5.Display.setTextSize(1);
    M5.Display.setCursor(10, 60);
    M5.Display.println("Reading accelerometer...");
    M5.Display.println("Press B to exit.");

    sensors_event_t acc, gyro, temp;

    while (true) {
        M5.update();
        if (M5.BtnB.wasPressed()) break;

        M5.Imu.getEvent(&acc, &gyro, &temp);

        M5.Display.setCursor(10, 120);
        M5.Display.fillRect(0, 110, 240, 80, BLACK);
        M5.Display.printf("AX: %.2f\n", acc.acceleration.x);
        M5.Display.printf("AY: %.2f\n", acc.acceleration.y);
        M5.Display.printf("AZ: %.2f\n", acc.acceleration.z);

        delay(50);
    }
}
