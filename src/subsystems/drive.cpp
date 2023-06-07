#include "main.h"
#include "ports.hpp"


using namespace okapi;

Motor right(rightPort, false, AbstractMotor::gearset::green,
            AbstractMotor::encoderUnits::degrees);
Motor left(leftPort, true, AbstractMotor::gearset::green,
           AbstractMotor::encoderUnits::degrees);

std::shared_ptr<OdomChassisController> drive =
    ChassisControllerBuilder()
        .withMotors({left}, {right})
        .withDimensions(AbstractMotor::gearset::green,
                        {{4_in, 7_in}, imev5BlueTPR})
        .withSensors(left.getEncoder(), right.getEncoder())
        // Specify the tracking wheels diam (2.75 in), track (7 in), and TPR
        // (360)
        .withOdometry()
        .buildOdometry();

static Controller controller = Controller();

void updateDrive() {
  drive->getModel()->tank(controller.getAnalog(ControllerAnalog::leftY),
                          controller.getAnalog(ControllerAnalog::rightY));

  left.setBrakeMode(AbstractMotor::brakeMode::hold);
  right.setBrakeMode(AbstractMotor::brakeMode::hold);
};