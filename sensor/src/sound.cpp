#ifdef SOUND_PORT

#include "sound.h"
#include <stdlib.h>
#include <Ticker.h>

#include "debug.h"


void addSoundRead();

class SoundReading {
    int numReadings = 0;
    int* readings;      // the readings from the analog input
    int readIndex = 0;              // the index of the current reading
    int total = 0;                  // the running total
    int average = 0;                // the average

    public:
        SoundReading(int numReadings);
        ~SoundReading();
        void addReading(int r);
        int getAverage();
};

void SoundReading::addReading(int r) {
    // subtract the last reading:
    total = total - readings[readIndex];
    // read from the sensor:
    readings[readIndex] = r;
    // add the reading to the total:
    total = total + readings[readIndex];
    // advance to the next position in the array:
    readIndex = readIndex + 1;

    // if we're at the end of the array...
    if (readIndex >= numReadings) {
        // ...wrap around to the beginning:
        readIndex = 0;
    }

    // calculate the average:
    average = total / numReadings;
}

int SoundReading::getAverage() {
    return this->average;
}

SoundReading::SoundReading (int numReadings) {
    this->numReadings = numReadings;
    this->readings = (int*) malloc (numReadings*sizeof(int));

    for (int n = 0; n < numReadings; n++) {
        this->readings[n] = 0;
    }
}

SoundReading::~SoundReading() {
    free(readings);
}

SoundReading largeReading(255);
SoundReading smallReading(10);
Ticker timer(addSoundRead, 1000*1000, MICROS);

void initSound() {
    DEBUG_WARNING("timer.start")
    timer.start();
    DEBUG_WARNING("State", sprintf("%d", timer.state))
}

void handleSound() {
    DEBUG_WARNING("timer.update")
    timer.update();
}

int getSoundDiff(){
    return abs(largeReading.getAverage() - smallReading.getAverage());
}

void addSoundRead() {
    DEBUG_WARNING("addSoundRead")
    int read = analogRead(SOUND_PORT);
    largeReading.addReading(read);
    smallReading.addReading(read);
}

#endif