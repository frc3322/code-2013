#include "SetShooterPreset2.h"
SetShooterPreset2::SetShooterPreset2() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void SetShooterPreset2::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void SetShooterPreset2::Execute() {
	SmartDashboard::PutNumber("ShooterSpeed", 2500.0);
}
// Make this return true when this Command no longer needs to run execute()
bool SetShooterPreset2::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void SetShooterPreset2::End() {
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooterPreset2::Interrupted() {
}
