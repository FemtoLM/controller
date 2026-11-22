#ifndef MOTORSIMULATOR_HPP
#define MOTORSIMULATOR_HPP

class MotorSimulator {

private:
    double currentRpm_;
    double targetRpm_;
    double accelerationStep_;

public:
    MotorSimulator(double accelerationStep);

    void setTargetSpeed(double rpm);
    void update();

    double getCurrentSpeed() const;
    double getTargetSpeed() const;
};

#endif
