#include <mbed.h>
#include "motor.h"
#include "wheel.h"

InterruptIn UB(USER_BUTTON);

//******* ここからピン指定 ***********//

PwmOut PWM_FR(PA_8); //MD1
PwmOut PWM_FL(PA_0);//MD2
PwmOut PWM_RR(PA_6);//MD3
PwmOut PWM_RL(PB_8);//MD4

DigitalOut PHASE_FR(PC_11);
DigitalOut PHASE_FL(PD_2);
DigitalOut PHASE_RR(PC_9);
DigitalOut PHASE_RL(PB_9);

Motor FR(PWM_FR, PHASE_FR, 100, true);
Motor FL(PWM_FL, PHASE_FL, 100, true);
Motor RR(PWM_RR, PHASE_RR, 100, true);
Motor RL(PWM_RL, PHASE_RL, 100, true);

//******* ここまでピン指定 ***********//

//Wheel move(引数);//ここにオブジェクト定義 wheel.cpp参照
/*例１*/ Wheel move(FR,FL,RR,RL,100);
//ここに何かしら関数を定義する

/* //例１：四輪でベンゼン環の動き実験用
void Benzene(void){
  move.NorthEast(30);
  wait(1);
  move.NorthWest(30);
  wait(1);
  move.West(30);
  wait(1);
  move.SouthWest(30);
  wait(1);
  move.SouthEast(30);
  wait(1);
  move.East(30);
  wait(1);
}
​*/

/* //例２：二輪の実験用
void test(){
  while(1){
FR.CW(30);
RL.CCW(30);
wait(3);
FR.CCW(30);
RL.CW(30);
wait(3);
  }
}
*/

void omni_test(){ //東 西 南 北　　北東 南西 北西 南東   右旋回 左旋回
  while(1)  {

    move.East(40);
    wait(1);
    move.Brake();
    wait(0.5);

    move.West(40);
    wait(1);
    move.Brake();
    wait(0.5);

    move.South(40);
    wait(1);
    move.Brake();
    wait(0.5);

    move.North(40);
    wait(1);
    move.Brake();
    wait(0.5);

    move.NorthEast(40);
    wait(1);
    move.Brake();
    wait(0.5);
    
    move.SouthWest(40);
    wait(1);
    move.Brake();
    wait(0.5);

    move.NorthWest(40);
    wait(1);
    move.Brake();
    wait(0.5);

    move.SouthEast(40);
    wait(1);
    move.Brake();
    wait(0.5);

    move.rotate_right(40);
    wait(1);
    move.Brake();
    wait(0.5);

    move.rotate_left(40);
    wait(1);
    move.Brake();
    wait(0.5);

    }
}

int main(){
  while(1){
    UB.rise(omni_test);
  }
}