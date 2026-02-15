#include <M5Unified.h>
#include <M5Cardputer.h>
#include <cmath> // For sqrt and atan2
#include "imu_mode.h"

// TODO: Add SD logging
// TODO: Add CSV writer
// TODO: Add Bluetooth streaming

void startIMUMode() {
    M5.Display.fillScreen(BLACK);

    // --- Draw Static UI Elements Once ---
    M5.Display.setTextSize(1);
    M5.Display.setTextColor(WHITE);
    M5.Display.setCursor(10, 10); M5.Display.print("Roll:");
    M5.Display.setCursor(10, 45); M5.Display.print("Pitch:");
    M5.Display.drawFastHLine(0, 80, 240, DARKGREY); // Separator
    M5.Display.setCursor(10, 88); M5.Display.print("G-Force:");
    M5.Display.setCursor(120, 88); M5.Display.print("Peak:");
    M5.Display.setCursor(10, 108); M5.Display.print("Time:");
    M5.Display.setTextColor(DARKGREY);
    M5.Display.setCursor(120, 108); M5.Display.print("(R to Reset)");

    float ax, ay, az;
    float gx, gy, gz;
    float temp;

    // --- Orientation Variables ---
    float roll = 0.0f, pitch = 0.0f;

    // --- UI Enhancement Variables ---
    unsigned long startTime = millis();
    unsigned long lastUpdateTime = 0;
    const int updateInterval = 100; // ms, update screen ~10 times per second

    float peakMag = 0.0f;
    
    // Helper function for drawing a graphical bar for an angle
    auto drawAngleBar = [](int y, float angle, uint16_t color) {
        const int bar_x = 90;
        const int bar_max_w = 140;
        const int center_x = bar_x + bar_max_w / 2;

        // Clamp angle to prevent drawing outside the bar area
        if (angle < -90) angle = -90;
        if (angle > 90) angle = 90;

        // Map angle from -90 to +90 to a position
        int indicator_pos = map((long)angle, -90, 90, bar_x, bar_x + bar_max_w);

        M5.Display.fillRect(bar_x - 2, y, bar_max_w + 6, 14, BLACK); // Clear wider area to catch indicator edges
        M5.Display.drawRect(bar_x, y + 2, bar_max_w, 10, DARKGREY); // Draw the bar background
        M5.Display.drawFastVLine(center_x, y + 2, 10, WHITE);      // Draw the center line
        M5.Display.fillRect(indicator_pos - 1, y, 3, 14, color);   // Draw the indicator
    };

    while (true) {
        M5Cardputer.update();
        if (M5Cardputer.Keyboard.isKeyPressed(KEY_BACKSPACE)) break;

        // Reset peak magnitude when 'r' is pressed
        if (M5Cardputer.Keyboard.isKeyPressed('r')) {
            peakMag = 0.0f;
        }

        // --- Non-blocking timed update for a responsive UI ---
        if (millis() - lastUpdateTime > updateInterval) {
            float dt = (millis() - lastUpdateTime) / 1000.0f;
            lastUpdateTime = millis();

            M5.Imu.getAccel(&ax, &ay, &az);
            M5.Imu.getGyro(&gx, &gy, &gz); // Gyro data is now essential

            // --- Sensor Fusion (Complementary Filter) ---
            // Calculate angles from accelerometer (stable but noisy)
            float pitch_acc = atan2(-ax, sqrt(ay * ay + az * az)) * 180.0 / M_PI;
            float roll_acc = atan2(ay, az) * 180.0 / M_PI;

            // Integrate gyroscope data (responsive but drifts)
            // Note: The sign and which gyro axis (gx, gy) corresponds to pitch/roll 
            // might need to be swapped depending on the IMU's physical orientation.
            // These values (0.98/0.02) are a common starting point.
            const float alpha = 0.98;
            pitch = alpha * (pitch + gx * dt) + (1.0 - alpha) * pitch_acc;
            roll  = alpha * (roll  + gy * dt) + (1.0 - alpha) * roll_acc;

            // --- UI Data Calculations ---
            float magnitude = sqrt(ax * ax + ay * ay + az * az);
            if (magnitude > peakMag) {
                peakMag = magnitude;
            }
            unsigned long elapsedTime = millis() - startTime;
            int minutes = (elapsedTime / 1000) / 60;
            int seconds = (elapsedTime / 1000) % 60;

            // --- Drawing Dynamic Data ---

            // --- Roll ---
            M5.Display.fillRect(50, 10, 40, 10, BLACK); // Clear old number
            M5.Display.setTextColor(RED);
            M5.Display.setCursor(50, 10);
            M5.Display.printf("%6.1f", roll);
            drawAngleBar(25, roll, RED);

            // --- Pitch ---
            M5.Display.fillRect(50, 45, 40, 10, BLACK); // Clear old number
            M5.Display.setTextColor(BLUE);
            M5.Display.setCursor(50, 45);
            M5.Display.printf("%6.1f", pitch);
            drawAngleBar(60, pitch, BLUE);

            // --- Summary ---
            M5.Display.setTextColor(WHITE);
            M5.Display.fillRect(70, 88, 45, 10, BLACK); M5.Display.setCursor(70, 88); M5.Display.printf("%4.2fG", magnitude);
            M5.Display.fillRect(160, 88, 45, 10, BLACK); M5.Display.setCursor(160, 88); M5.Display.printf("%4.2fG", peakMag);
            M5.Display.fillRect(50, 108, 60, 10, BLACK); M5.Display.setCursor(50, 108); M5.Display.printf("%02d:%02d", minutes, seconds);
        }
    }
}
