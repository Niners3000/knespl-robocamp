#include "robotka.h"
// ahoj
// Funkce setup se zavolá vždy po startu robota.
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
void keepDistance(){
    
}

void setup() {
    rkConfig cfg;

    cfg.motor_max_power_pct = 100;
    cfg.motor_max_acceleration = 1000000;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);

    /*int lBlack = 2911;
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
    while(rkButtonOn(true) == false){
    }
    while (rkButtonOn() == false) {
        
        while(rkIrLeft() >= black && rkIrRight() < black){
            lastState = 0;
            rkMotorsSetSpeed(100, 75);
            //delay(10);
        }
        while(rkIrRight() >= black && rkIrLeft() < black){
            lastState = 1;
            rkMotorsSetSpeed(75, 100);
            //delay(10);
        }
        if(rkIrRight() < black && rkIrLeft() < black){
            rkMotorsSetSpeed(100,100);
        }
        if(rkIrRight() <= white && rkIrLeft() <= white){
            if (lastState == 0)
            {
                while (rkIrRight() <= white)
                {
                    lastState = 3;
                    rkMotorsSetSpeed(40, 100);
                } 
                while (rkIrLeft() <= white)
                {
                    lastState = 3;
                    rkMotorsSetSpeed(100, 40);
                } 
            }
        }*/

    /*if (distanceFront <= 150)
        {
            rkMotorsSetSpeed(-50, 50); //look left
            delay(200);
            rkMotorsSetSpeed(0, 0); //wait for sensor
            delay(100);
            lookLeft = distanceFront;

            rkMotorsSetSpeed(50, -50); //look right (twice the left distance)
            delay(400);
            rkMotorsSetSpeed(0, 0); //wait for sensor
            delay(100);
            lookRight = distanceFront;

            rkMotorsSetSpeed(-50, 50); //set back to middle
            delay(200);

            if (lookLeft >= lookRight)
            {
                rkMotorsSetSpeed(-50, 50); //otoci se doleva
                delay(440);
                rkMotorsSetSpeed(50, 50); //jede rovne
                delay(440);
                rkMotorsSetSpeed(50, -50); //otoci se doprava
                delay(440);
                rkMotorsSetSpeed(50, 50); //jede rovne
                delay(440);
                rkMotorsSetSpeed(50, -50); //otoci se doprava
                delay(440);
                while (rkIrLeft() <= white || rkIrRight() <= white)
                {
                    rkMotorsSetSpeed(50, 50); //jede rovne
                }
            }
            else{
                rkMotorsSetSpeed(50, -50); //otoci se doprava
                delay(440);
                rkMotorsSetSpeed(50, 50); //jede rovne
                delay(440);
                rkMotorsSetSpeed(-50, 50); //otoci se doleva
                delay(440);
                rkMotorsSetSpeed(50, 50); //jede rovne
                delay(440);
                rkMotorsSetSpeed(-50, 50); //otoci se doleva
                delay(440);
                while (rkIrLeft() <= white || rkIrRight() <= white)
                {
                    rkMotorsSetSpeed(50, 50); //jede rovne
                }
            }
            
        }*/
    int distanceLeft;
    int distanceFront;

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

    while (true) {
        turnRight();
        delay(1000);
    }
}
