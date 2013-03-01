#include "../Robot.h"
#include "Drivetrain.h"
#include "../Robotmap.h"
#include "../Commands/BackgroundDrive.h"
Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftMotorA = RobotMap::drivetrainLeftMotorA;
	leftMotorB = RobotMap::drivetrainLeftMotorB;
	rightMotorA = RobotMap::drivetrainRightMotorA;
	rightMotorB = RobotMap::drivetrainRightMotorB;
	drive = RobotMap::drivetrainDrive;
	shiftGear = RobotMap::drivetrainShiftGear;
	leftEncoder = RobotMap::drivetrainLeftEncoder;
	rightEncoder = RobotMap::drivetrainRightEncoder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}    
void Drivetrain::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new BackgroundDrive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Drivetrain::ShiftIntoLowGear() {
	shiftGear->Set(DoubleSolenoid::kForward);
}
void Drivetrain::ShiftIntoHighGear() {
	shiftGear->Set(DoubleSolenoid::kReverse);
}
void Drivetrain::ToggleShiftGears() {
	DoubleSolenoid::Value newGear = (shiftGear->Get() == DoubleSolenoid::kForward) ? DoubleSolenoid::kReverse : DoubleSolenoid::kForward;
	shiftGear->Set(newGear);
}
void Drivetrain::Snapshot(){
	MotorSnapshot(leftMotorA);
	MotorSnapshot(leftMotorB);
	MotorSnapshot(rightMotorA);
	MotorSnapshot(rightMotorB);
}
void Drivetrain::MotorSnapshot(CANJaguar* motor)
{
	if (Robot::diag) {
		int motorNumber = motor->m_deviceNumber;
		int status = motor->m_lastReceiveStatus;
		float busVoltage = motor->GetBusVoltage();
		float outputCurrent = motor->GetOutputCurrent();
		Robot::diag->BufferPrintf("m,%d,%d,%.2f,%.2f\n", motorNumber, status, busVoltage, outputCurrent);
	}
}
