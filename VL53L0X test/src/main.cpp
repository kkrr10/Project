#include <mbed.h>
#include "VL53L0X.h"

Serial pc(USBTX, USBRX, 9600); // TX, RX, Baudrate
Timer timer;
I2C i2c(PB_9, PB_8); // SDA, SCL

VL53L0X vlR = VL53L0X(&i2c, &timer);

uint16_t distance_to_object;

int main(void)
{
  vlR.init(true);
  wait(0.1);
  vlR.startContinuous(30); // 30 ms interval
  wait(0.1);
  pc.printf("setup complete\n");

  while (true)
  {
    distance_to_object = vlR.readRangeContinuousMillimeters();
    pc.printf("distance: %d mm\n", distance_to_object);
    wait(1);
  }
}
