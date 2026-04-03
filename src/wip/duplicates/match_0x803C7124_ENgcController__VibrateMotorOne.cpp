struct EController {
    int VibrateMotorOne(float val);
};

struct ENgcController : EController {
    void UpdateMotors();
    int VibrateMotorOne(float val);
};

int ENgcController::VibrateMotorOne(float val) {
    int result = EController::VibrateMotorOne(val);
    if (result == 0) {
        return 0;
    }
    UpdateMotors();
    return 1;
}
