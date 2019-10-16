#include <mbed.h>
#include "motor.h"

InterruptIn UB(USER_BUTTON);
DigitalOut led(LED2, false);
PwmOut PWM_FR(PA_6);
DigitalOut PHASE_FR(PC_9);
Motor FR(PWM_FR, PHASE_FR, 100, true);

void test(void){
  led.write(true);
  FR.CW(30);
  wait(3);
  FR.Brake();
  wait(1);
  FR.CCW(40);
  wait(3);
  FR.Brake();
  wait(1);
}
int main(){
  while(true){
    UB.rise(test);
  }
}