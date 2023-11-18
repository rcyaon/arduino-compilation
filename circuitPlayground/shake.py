import time
from adafruit_circuitplayground import cp

# Adjust the sensitivity based on your requirements
sensitivity = 10.0

while True:
    # Read accelerometer values
    x, y, z = cp.acceleration

    # Check if a shake is detected
    if abs(x) > sensitivity or abs(y) > sensitivity or abs(z) > sensitivity:
        # Trigger vibration (you may need to adjust the duration)
        cp.pixels.fill((255, 0, 0))  # Turn on the NeoPixels to red
        cp.pixels.show()
        cp.start_tone(1000)  # Start vibration
        time.sleep(0.5)  # Vibration duration
        cp.stop_tone()  # Stop vibration
        cp.pixels.fill((0, 0, 0))  # Turn off the NeoPixels
        cp.pixels.show()

    time.sleep(0.1)  # Adjust the delay based on your requirements


