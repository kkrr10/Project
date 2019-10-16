#include "mbed.h"
#include "motor.h"
#include "wheel.h"

InterruptIn UB(USER_BUTTON);

//******* ここからピン指定 ***********//

PwmOut PWM_FR(PB_8);
//PwmOut PWM_FL(ピン名);
//PwmOut PWM_RR(ピン名);
//PwmOut PWM_RL(ピン名);

DigitalOut PHASE_FR(PA_9);
//DigitalOut PHASE_FL(ピン名);
//DigitalOut PHASE_RR(ピン名);
//DigitalOut PHASE_RL(ピン名);

Motor FR(PWM_FR, PHASE_FR, 100, true);
Motor FL(PWM_FL, PHASE_FL, 100, true);
Motor RR(PWM_RR, PHASE_RR, 100, true);
Motor RL(PWM_RL, PHASE_RL, 100, true);

AnalogIn ri(A0);
AnalogIn le(/*ピン名*/);

//Serial pc(USBTX,USBRX,115200); //不使用
//DigitalOut led(LED1);  //不使用

//******* ここまでピン指定 ***********//

Wheel.move(FR,FL,RR,RL,100);

bool go=false;
double vr,vl;  //アナログ値(０～１)の電圧　voltage_right voltage_left
double threshold=/*実験して設定*/; //閾値設定

void GO(){
go=true;
}

void linetrace_simple(double vl,double vr){//単純に線に沿って前進するための関数

if(vl>threshold&&vr>threshold){//緑緑
move.North(40);
wait(0.2);
return;
}

else if(vl<=threshold&&vr>threshold){//白緑
move.NorthWest(40);
wait(0.2);
return;
}

else if(vl>threshold&&vr<=threshold){//緑白
move.NorthEast(40);
wait(0.2);
return;
}

else{//白白(こうなるはずがない!)
move.Brake();
return;//もしこうなったら詰み.....停止
}

}


int main() {
  while(1){
    UB.rise(GO); //ボタンが押されたら下のwhileに入る
    while(go) {
        vr = ri.read(); //0.2sec毎に読み取ることになってる(はず)
        vl = le.read();
      linetrace_simple(vl,vr);
    }
  }
}