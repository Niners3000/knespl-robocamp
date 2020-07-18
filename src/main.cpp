#include "robotka.h"
// ahoj
// Funkce setup se zavolá vždy po startu robota.

int distanceLeft;
int motorDelay = 445;
int distanceFront;
/*
const int p = 0.8;
int correction;
const int distanceConst = 200;
int x = 5;

void turnLeft() {
    rkMotorsSetSpeed(100, 50);
    delay(750);
    rkMotorsSetSpeed(0, 0);
}
void turnRight() {
    rkMotorsSetSpeed(50, 100);
    delay(750);
    rkMotorsSetSpeed(0, 0);
}
void keepDistance() {

    while (distanceLeft < 180) {
        rkMotorsSetSpeed(50, 50 - correction);
        correction = (distanceConst - distanceLeft) * p;
        //x++;
        delay(10);
    }
    //x = 5;
    while (distanceLeft > 220) {
        correction = (distanceLeft - distanceConst) * p;
        rkMotorsSetSpeed(50 - correction, 50);
        //x++;
        delay(10);
    }
    //x = 5;
    while (distanceLeft >= 180 && distanceLeft <= 220) {
        rkMotorsSetSpeed(100, 100);
    }
}*/

void setup() {
    rkConfig cfg;

    cfg.motor_max_power_pct = 100;
    cfg.motor_max_acceleration = 1000000;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);

    rkUltraMeasureAsync(1, [&](uint32_t distance_mm) {
        distanceFront = distance_mm;
        return true;
    });
    rkUltraMeasureAsync(2, [&](uint32_t distance_mm) {
        distanceLeft = distance_mm;
        return true;
    });

    int lBlack = 2911;
    int rBlack = 2765;

    int black = 2000;
    int white = 1000;

    int leftWhite = 71;
    int rightWhite = 66;

    int lastState = 0;

    int distanceFront;
    int distanceLeft;

    int lookLeft;
    int lookRight;
    // Sem patří váš kód
    rkUltraMeasureAsync(1, [&](uint32_t distance_mm) {
        distanceFront = distance_mm;
        return true;
    });
    rkUltraMeasureAsync(2, [&](uint32_t distance_mm) {
        distanceLeft = distance_mm;
        return true;
    });
    while (rkButtonOn(true) == false) {
    }
    while (rkButtonOn() == false) {

        if (distanceFront <= 270 && distanceFront >= 11) {
            rkMotorsSetSpeed(30, -30); //otoci se doprava
            delay(motorDelay);
            rkMotorsDrive(300, 300, 30);
            //rkMotorsSetSpeed(50, 50); //jede rovne
            //delay(motorDelay);
            rkMotorsSetSpeed(-30, 30); //otoci se doleva
            delay(motorDelay);
            rkMotorsDrive(320, 320, 30);
            rkMotorsSetSpeed(-30, 30); //otoci se doleva
            delay(motorDelay);
            rkMotorsDrive(330, 330, 30);
            while (rkIrLeft() <= white || rkIrRight() <= white) {
                rkMotorsSetSpeed(28, -18); //jede rovne
                if (rkIrLeft() >= black && rkIrRight() < black) {
                    lastState = 0;
                    break;
                    //rkMotorsSetSpeed(100, 75);
                    //delay(10);
                }
                if (rkIrRight() >= black && rkIrLeft() < black) {
                    lastState = 1;
                    break;
                    //rkMotorsSetSpeed(75, 100);
                    //delay(10);
                }
            }
        }

        while (rkIrLeft() >= black && rkIrRight() < black) {
            lastState = 0;
            rkMotorsSetSpeed(85, 60);
            //delay(10);
        }
        while (rkIrRight() >= black && rkIrLeft() < black) {
            lastState = 1;
            rkMotorsSetSpeed(60, 85);
            //delay(10);
        }
        if (rkIrRight() < black && rkIrLeft() < black) {
            rkMotorsSetSpeed(80, 80);
        }
        if (rkIrRight() <= white && rkIrLeft() <= white) {
            if (lastState == 0) {
                while (rkIrRight() <= white) {
                    lastState = 3;
                    rkMotorsSetSpeed(15, 75);
                }
                while (rkIrLeft() <= white) {
                    lastState = 3;
                    rkMotorsSetSpeed(75, 15);
                }
            }
        }

        /*while (rkButtonOn(true) == false) {
    }

    while (true) {
        if (distanceFront <= 300) {
            turnLeft();
            //delay(1000);
        } else {
            keepDistance();
            fmt::print("distance left: {} \n", distanceLeft);
            fmt::print("distance front: {} \n", distanceFront);
            //rkMotorsSetSpeed(100, 100);
        }
    }*/
    }
}
