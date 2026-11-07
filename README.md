# ESP32 Health Monitor Starter

This PlatformIO Arduino project is a compiling starting point for an ESP32
sensor/display application. Sensor readings are raw samples; this scaffold does
not calculate heart rate, blood oxygen, or provide medical advice.

## Hardware defaults

| Module | ESP32 connection |
| --- | --- |
| SSD1306 I2C display | SDA GPIO 21, SCL GPIO 22, address `0x3C` |
| MAX30102 | Shared I2C bus: SDA GPIO 21, SCL GPIO 22 |
| MPU6050 | Shared I2C bus: SDA GPIO 21, SCL GPIO 22, address `0x68` |
| DS18B20 | Data GPIO 4, with a 4.7 kOhm pull-up to 3.3 V |
| Capacitive touch input | GPIO 27 (ESP32 touch channel T7) |

Use 3.3 V-compatible modules and connect all grounds together. Configure
different pins or thresholds in `include/config.h` as needed.

## Build and upload

On Windows, run the setup script in PowerShell to install PlatformIO and build:

```powershell
.\setup.ps1
```

If PowerShell blocks the script, run:

```powershell
powershell -ExecutionPolicy Bypass -File .\setup.ps1
```

After setup, build or upload with PlatformIO:

```powershell
python -m platformio run
python -m platformio run --target upload
python -m platformio device monitor
```

On other platforms, install the Python requirement and build:

```text
python -m pip install -r requirements.txt
pio run
pio run --target upload
pio device monitor
```

The display shows uptime, temperature, the raw MAX30102 infrared sample, and
touch state. Initialization and MPU6050 read errors are reported over serial.
The MPU6050 acceleration values are currently sampled but not displayed.

The included `diagram.json` shows the ESP32, display, MPU6050, and DS18B20
connections. Connect a MAX30102 breakout to the same I2C bus; the diagram omits
it so the starter remains usable with the standard Wokwi parts.

## Notes

- The clock reports elapsed uptime, not wall-clock time; no RTC or network time
  source is configured.
- The MAX30102 output is raw sensor data, not a calculated pulse or SpO2 value.
- GPIO 27 touch thresholds vary by board and environment; tune
  `TOUCH_THRESHOLD` for your hardware.
# wyshcare_prototype
