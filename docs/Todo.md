# TODO — MotionTrace ADV  
A structured roadmap for development of the Cardputer ADV motion‑tracking system.

---

# ✅ Phase 0 — Project Setup (Current)
**Status:** In progress  
**Goal:** Establish a clean, modular foundation.

### Tasks
- [x] Create GitHub repository  
- [x] Add README.md  
- [x] Add initial PlatformIO project  
- [x] Add splash screen  
- [x] Add main menu with 4 options  
- [x] Add placeholder pages for Phone GPS + External GPS  
- [x] Add Info/About page  
- [ ] Split code into modular `.cpp` and `.h` files  
- [ ] Add TODO.md (this file)

---

# 🚀 Phase 1 — IMU‑Only Mode (Core Functionality)
**Goal:** Make ADV Mode fully functional and useful without GPS.

### IMU Reading & Display
- [x] Basic IMU read loop  
- [ ] Add orientation (gyro integration or quaternion)  
- [ ] Add acceleration magnitude calculation  
- [ ] Add peak acceleration tracking  
- [ ] Add vibration intensity metric  

### UI Enhancements
- [ ] Add live graph (simple bar or line graph)  
- [ ] Add session timer  
- [ ] Add “IMU Status” indicator (OK / Error)  

### SD Card Logging
- [ ] Detect SD card presence  
- [ ] Create log file per session  
- [ ] Write CSV header  
- [ ] Log IMU data at fixed rate (e.g., 50–100 Hz)  
- [ ] Add session metadata file (notes, date, duration)  
- [ ] Add error handling for SD write failures  

### Bluetooth (Optional for Phase 1)
- [ ] Add BLE service for IMU streaming  
- [ ] Add simple PC viewer script (Python)  

---

# 🧭 Phase 2 — Settings & System Features
**Goal:** Make the device feel polished and configurable.

### Settings Menu
- [ ] Brightness control  
- [ ] Screen timeout  
- [ ] Sound on/off  
- [ ] Units (metric/imperial)  
- [ ] IMU logging rate (Hz)  
- [ ] Bluetooth on/off  

### Saved Sessions Browser
- [ ] List CSV files on SD  
- [ ] Show metadata (date, duration, size)  
- [ ] Delete session  
- [ ] Mark as favourite  

### Info/Help Pages
- [ ] Add button guide  
- [ ] Add “How to export logs”  
- [ ] Add “How to use PC visualiser”  

---

# 📱 Phase 3 — Phone GPS Mode (Bluetooth GPS)
**Goal:** Add real GPS data without buying hardware.

### Bluetooth SPP (Android)
- [ ] Implement SPP client  
- [ ] Parse NMEA sentences  
- [ ] Extract lat/lon/alt/speed  
- [ ] Sync timestamps with IMU data  
- [ ] Add GPS status indicator (fix/no fix)  

### Bluetooth BLE (iPhone/Android)
- [ ] Implement BLE client  
- [ ] Parse JSON or binary GPS packets  
- [ ] Add BLE reconnection logic  

### UI
- [ ] Replace “Coming Soon” with real submenu  
- [ ] Add GPS signal page  
- [ ] Add GPS + IMU combined session mode  

### Logging
- [ ] Add GPS fields to CSV  
- [ ] Add GPS quality + satellites  

---

# 📡 Phase 4 — External GPS Mode (Hardware GPS)
**Goal:** Support M5Stack GPS Cap or UART GPS modules.

### Hardware Integration
- [ ] Detect GPS Cap  
- [ ] UART GPS reader (NEO‑6M / NEO‑M8N)  
- [ ] Parse NMEA  
- [ ] Handle 1–10 Hz update rates  

### UI
- [ ] Replace “Coming Soon” with real submenu  
- [ ] Add satellite count + fix quality  
- [ ] Add GPS signal strength graph  

### Logging
- [ ] Add hardware GPS fields to CSV  
- [ ] Add GPS timestamp sync  

---

# 🗺️ Phase 5 — Visualisation Tools (PC Side)
**Goal:** Turn logs into beautiful 3D motion maps.

### Python Visualiser
- [ ] Load CSV logs  
- [ ] Plot IMU‑only 3D relative motion trace  
- [ ] Colour by acceleration magnitude  
- [ ] Add interactive rotation/zoom  
- [ ] Add altitude plane (z=0)  
- [ ] Add GPS‑based 3D world path  
- [ ] Colour by speed  
- [ ] Add impact markers  

### Export Options
- [ ] Export PNG  
- [ ] Export 3D model (OBJ/GLTF optional)  

---

# 🧪 Phase 6 — Advanced Features (Optional)
**Goal:** Push the project into “wow” territory.

### Sensor Fusion
- [ ] Combine IMU + GPS for smoother path  
- [ ] Kalman filter or complementary filter  

### Air‑Mouse Mode
- [ ] Add HID mouse emulation  
- [ ] Add sensitivity settings  

### Motion Events
- [ ] Jump detection  
- [ ] Crash/impact detection  
- [ ] Shake patterns  
- [ ] Gesture recognition  

---

# 🧼 Phase 7 — Polish & Release
**Goal:** Make the project feel like a finished product.

### Documentation
- [ ] Full user guide  
- [ ] Developer guide  
- [ ] Wiring diagrams (for external GPS)  
- [ ] Phone app setup instructions  

### GitHub
- [ ] Add screenshots  
- [ ] Add demo videos  
- [ ] Add releases page  
- [ ] Add issue templates  

---

# 🏁 Long‑Term Ideas (Future)
- Cloud sync  
- Web‑based visualiser  
- Multi‑device motion capture  
- Real‑time GPS + IMU streaming to PC  
- Companion mobile app  
