struct EController {
    int VibrateMotorTwo(float val);
};

struct ENgcController : EController {
    void UpdateMotors();
    int VibrateMotorTwo(float val);
};

int ENgcController::VibrateMotorTwo(float val) {
    int result = EController::VibrateMotorTwo(val);
    if (result == 0) {
        return 0;
    }
    UpdateMotors();
    return 1;
}
