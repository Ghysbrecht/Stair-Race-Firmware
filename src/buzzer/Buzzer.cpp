
#include "Buzzer.h"

Buzzer::Buzzer() : pwm(PTA2){
    pwm = 0.0;
}

void Buzzer::playFreq(float frequency, float duration, float volume){
        pwm.period(1.0/frequency);
        pwm = volume/2.0;
        wait_ms(duration);
        pwm = 0.0;
}

void Buzzer::completeSound(){
    playFreq(1318, 130, 1);
    playFreq(1567, 130, 1);
    playFreq(2637, 130, 1);
    playFreq(2093, 130, 1);
    playFreq(2349, 130, 1);
    playFreq(3135, 130, 1);
}
