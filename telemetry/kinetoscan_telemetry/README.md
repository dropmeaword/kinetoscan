## Kinetoscan' telemetry

The Kinetoscan's telemetry module pumps data via Serial at a data rate of 115200 bps.

The telemetry module offers two kinds of measurements: IMU, for angular motion. And GPS for geographical location.

Lines corresponding to IMU measurements contain the following information:
IMU, Yaw, Pitch, Roll (e.g. IMU,58.58,-17.18,16.71)

Lines corresponding to GPS data contain the following information:
GPS,fix, fixquality, satellites, latitude, longitude, latitude degrees, longitude degrees, altitude

(e.g. GPS,1,2,8,5222.9282N,451.1759E,52.3821,4.8529,4)
