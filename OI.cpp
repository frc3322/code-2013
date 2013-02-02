// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveForward.h"
#include "Commands/ShiftToHigh.h"
#include "Commands/ShiftToLow.h"
#include "Commands/TelOpDrive.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
// This is just a dummy UI to test the robot.
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveStick = new Joystick(1);
	
	buttonB = new JoystickButton(driveStick, 2);
	buttonB->WhenPressed(new ShiftToHigh());
	buttonA = new JoystickButton(driveStick, 1);
	buttonA->WhenPressed(new ShiftToLow());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("ShiftToLow", new ShiftToLow());
	SmartDashboard::PutData("ShiftToHigh", new ShiftToHigh());
	SmartDashboard::PutData("TelOpDrive", new TelOpDrive());
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("DriveForward", new DriveForward());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	SmartDashboard::PutNumber("Fwd Duration", 1.0);
	SmartDashboard::PutNumber("Fwd Speed", 0.25);
	fwdChooser = new SendableChooser();
	fwdChooser->AddObject("Tank", (void *)1);
	fwdChooser->AddObject("Arcade", (void *)2);
	fwdChooser->AddDefault("Drive", (void *)3);
	SmartDashboard::PutData("Fwd Mode", fwdChooser);
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getDriveStick() {
	return driveStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
