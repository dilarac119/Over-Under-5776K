#include "subsystems/cata.hpp"
#include "subsystems/ports.hpp"
#include "globals.hpp"

Motor cataMotor(cataMotorPort, true, AbstractMotor::gearset::blue,
            AbstractMotor::encoderUnits::degrees);


ADIButton limitSwitch('A', true);



void updateCata(){

    // without limit switch 

    bool catapult = false;

    if (controller.getDigital(ControllerDigital::R1) == 1){
        catapult = !catapult;

        if(catapult){
            cataMotor.moveVoltage(12000);
        }
        else{
            cataMotor.moveVoltage(0);
        }
    pros::delay(100);

    }



    /* with limit switch (if we end up added) 

    if (controller.getDigital(ControllerDigital::R1) == 1){
        while (!limitSwitch.isPressed()) {
            cataMotor.moveVoltage(12000);
        }
        
        cataMotor.moveVoltage(0);
    }

    else {
        if (!limitSwitch.isPressed()) {
            cataMotor.moveVoltage(12000);
        }

        else {
            cataMotor.moveVoltage(0);
        }
    }
    
    */
}