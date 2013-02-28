#include "BackgroundHoldCamera.h"
BackgroundHoldCamera::BackgroundHoldCamera() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::camera);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void BackgroundHoldCamera::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void BackgroundHoldCamera::Execute() {
	Robot::camera->direction->SetAngle(Robot::camera->savedDirection);
	Robot::camera->elevation->SetAngle(Robot::camera->savedElevation);
}
// Make this return true when this Command no longer needs to run execute()
bool BackgroundHoldCamera::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void BackgroundHoldCamera::End() {
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BackgroundHoldCamera::Interrupted() {
	End();
}