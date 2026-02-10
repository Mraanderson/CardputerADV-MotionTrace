# MotionTrace ADV  
A modular motion‑tracking and data‑logging project for the **M5Stack Cardputer ADV**, built using **PlatformIO** and **M5Unified**.  
This project focuses on **IMU‑based motion capture**, with a clean upgrade path for **phone‑based GPS** and **external GPS modules**.

The goal is to create a polished, extensible tool that works immediately out‑of‑the‑box while leaving well‑documented hooks for future expansion.

---

## ✨ Features (Current)

### ✔ ADV Mode (IMU‑Only)
Fully functional mode using the Cardputer ADV’s onboard IMU:
- Real‑time accelerometer and gyroscope readings  
- On‑screen live data  
- Modular structure for adding:  
  - SD card logging  
  - CSV export  
  - Bluetooth IMU streaming  
  - 3D motion trace generation  
  - Acceleration heatmaps  
- Clean, responsive UI  

### ✔ Menu System
A complete navigation framework:
- Splash screen  
- Main menu  
- ADV Mode  
- Info/About section  
- Placeholder pages for GPS modes  

### ✔ Clear Upgrade Path
The codebase includes **commented placeholders** for:
- Phone GPS (Bluetooth SPP / BLE)  
- External GPS modules (M5Stack GPS Cap, NEO‑6M, NEO‑M8N)  

These are informational only—no dormant or broken code.

---

## 🚧 Features (Planned)

### 📱 Phone GPS Mode
Will allow the Cardputer to receive GPS data from a smartphone via:
- Android Bluetooth SPP (NMEA sentences)  
- iPhone/Android BLE custom service  

### 📡 External GPS Mode
Support for hardware GPS modules:
- M5Stack GPS Cap  
- Generic UART GPS receivers  

### 🗺️ GPS‑Enhanced Logging
Once GPS is added:
- True speed  
- True distance  
- Altitude above sea level  
- 3D world‑anchored path  
- Colour‑coded speed/acceleration maps  

---

## 📁 Project Structure

```
MotionTraceADV/
│
├── platformio.ini
├── src/
│   ├── main.cpp
│   ├── menu.cpp
│   ├── menu.h
│   ├── imu_mode.cpp
│   ├── imu_mode.h
│   ├── gps_phone.cpp        // placeholder
│   ├── gps_phone.h
│   ├── gps_external.cpp     // placeholder
│   ├── gps_external.h
│   ├── info.cpp
│   ├── info.h
│
└── data/
    └── log_template.csv
```

---

## 🧭 Roadmap

- [ ] Add SD card logging  
- [ ] Add CSV writer  
- [ ] Add Bluetooth IMU streaming  
- [ ] Build PC‑side 3D visualiser  
- [ ] Implement Phone GPS mode  
- [ ] Implement External GPS mode  
- [ ] Add settings menu  
- [ ] Add saved session browser  

---

## 📜 License
MIT License

---

## 🤝 Contributions
Pull requests are welcome.  
Please keep code modular and maintain the project’s clean upgrade‑path philosophy.
