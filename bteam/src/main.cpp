#include <mbed.h>
#include "motor.h"
#include "wheel.h"
//#include "state.h"

InterruptIn UB(USER_BUTTON);
DigitalOut led(LED2);
Serial pc(USBTX, USBRX); 

//PwmOut PWM_FR(PB_8);
PwmOut PWM_FR(PA_8);
PwmOut PWM_FL(PA_5);
PwmOut PWM_RR(PA_6);
PwmOut PWM_RL(PB_6);

//DigitalOut PHASE_FR(PA_9);
DigitalOut PHASE_FR(PC_11);
DigitalOut PHASE_FL(PD_2);
DigitalOut PHASE_RR(PC_9);
DigitalOut PHASE_RL(PB_9);

Motor FR(PWM_FR, PHASE_FR, 100, true);
Motor FL(PWM_FL, PHASE_FL, 100, true);
Motor RR(PWM_RR, PHASE_RR, 100, true);
Motor RL(PWM_RL, PHASE_RL, 100, true);
Wheel Whe(FR,FL,RR,RL,100);



int main()
{
  while(1)
  {
    pc.printf("1、、\r\n");
    led = 1;
    wait(0.5);
    pc.printf("2、、\r\n");
    led = 0;
    pc.printf("3、、\r\n");
    wait(0.5);
    Whe.Brake();
    pc.printf("4、、\r\n");
    wait(0.5);
    Whe.Brake();
    pc.printf("5、、\r\n");
    wait(0.5);
    pc.printf("6、、\r\n");
    wait(0.5);
    Whe.Brake();
    pc.printf("7、、\r\n");
    wait(0.5);
    Whe.South(80);
    pc.printf("8、、\r\n");
    wait(0.5);
    Whe.Brake();
    pc.printf("9、、\r\n");
    wait(0.5);
    Whe.East(80);
    pc.printf("10、、\r\n");
    wait(0.5);
    Whe.Brake();
    pc.printf("11、、\r\n");
    wait(0.5);
    Whe.West(80);
    pc.printf("12、、\r\n");
    wait(0.5);
    Whe.Brake();
    pc.printf("13、、\r\n");
    wait(0.5);
    Whe.NorthEast(80);
    pc.printf("14、、\r\n");
    wait(0.5);
    Whe.Brake();
    pc.printf("15、、\r\n");
    wait(0.5);
    Whe.SouthWest(80);
    pc.printf("16、、\r\n");
    wait(0.5);
    Whe.Brake();
    pc.printf("17、、\r\n");
    wait(0.5);
    Whe.NorthWest(80);
    pc.printf("18、、\r\n");
    wait(0.5);
    Whe.Brake();
    pc.printf("19、、\r\n");
    wait(0.5);
    Whe.SouthEast(80);
    pc.printf("20、、\r\n");
    wait(0.5);
    }
}