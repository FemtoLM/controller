#include <iostream>

using namespace std;

double updateSpeed(double currentRpm, double targetRpm, double step) {

    if (currentRpm < targetRpm) {
        currentRpm = currentRpm + step;

        if (currentRpm > targetRpm) {
            currentRpm = targetRpm;
        }
    }
    else if (currentRpm > targetRpm) {
        currentRpm = currentRpm - step;

        if (currentRpm < targetRpm) {
            currentRpm = targetRpm;
        }
    }

    return currentRpm;
}

int main() {

    double currentRpm = 0.0;
    double targetRpm = 1500.0;
    double accelerationStep = 120.0;

    for (int cycle = 0; cycle < 15; cycle++) {

        currentRpm = updateSpeed(currentRpm, targetRpm, accelerationStep);

        cout << "Cycle " << cycle;
        cout << " | target=" << targetRpm;
        cout << " RPM | current=" << currentRpm;
        cout << " RPM" << endl;
    }

    return 0;
}
