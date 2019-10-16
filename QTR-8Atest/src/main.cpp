#include "mbed.h"
 
AnalogIn analog_value(A0);
Serial pc(USBTX,USBRX,115200);
DigitalOut led(LED1);

int main() {
    float meas;
    
    printf("\nAnalogIn example\n");
    
    while(1) {
        meas = analog_value.read();
        printf("meas:: %f \n",meas);
        wait(0.2); // 200 ms
    }
}