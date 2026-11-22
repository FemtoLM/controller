#include <iostream>

using namespace std;

#define MAX_SAMPLES 20


struct Telemetry {
	double rpm;
	double temperatureC;
	double voltageV;
	double currentA;
	bool motorEnabled;
};


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
    
    Telemetry telemetry;
    
    telemetry.rpm=0.0;
    telemetry.temperatureC=31.5;
    telemetry.voltageV=12.0;
    telemetry.currentA=1.2;
    telemetry.motorEnabled = true;
    
    double rpmHistory[MAX_SAMPLES];
    int sampleCount=0;
    
    if(sampleCount<MAX_SAMPLES) {
    	rpmHistory[sampleCount]=telemetry.rpm;
    	sampleCount++;
    	}

    for (int cycle = 0; cycle < 15; cycle++) {

        currentRpm = updateSpeed(currentRpm, targetRpm, accelerationStep);

        cout << "Cycle " << cycle;
        cout << " | target=" << targetRpm;
        cout << " RPM | current=" << currentRpm;
        cout << " RPM" << endl;
    }

    return 0;
}
