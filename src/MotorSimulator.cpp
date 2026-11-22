#include "MotorSimulator.hpp"

MotorSimulator::MotorSimulator(double accelerationStep)
    : currentRpm_(0.0),
      targetRpm_(0.0),
      accelerationStep_(accelerationStep) {
}

void MotorSimulator::setTargetSpeed(double rpm) {
    targetRpm_ = rpm;
}

void MotorSimulator::update() {

    if (currentRpm_ < targetRpm_) {

        currentRpm_ += accelerationStep_;

        if (currentRpm_ > targetRpm_) {
            currentRpm_ = targetRpm_;
        }
    }
    else if (currentRpm_ > targetRpm_) {

        currentRpm_ -= accelerationStep_;

        if (currentRpm_ < targetRpm_) {
            currentRpm_ = targetRpm_;
        }
    }
}

double MotorSimulator::getCurrentSpeed() const {
    return currentRpm_;
}

double MotorSimulator::getTargetSpeed() const {
    return targetRpm_;
}
