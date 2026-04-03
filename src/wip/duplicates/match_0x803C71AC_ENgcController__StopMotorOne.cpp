struct EController {
    int StopMotorOne();
};

struct ENgcController : EController {
    void UpdateMotors();
    int StopMotorOne();
};

int ENgcController::StopMotorOne() {
    int result = EController::StopMotorOne();
    if (result == 0) {
        return 0;
    }
    UpdateMotors();
    return 1;
}
