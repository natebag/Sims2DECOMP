struct EController {
    int StopMotorTwo();
};

struct ENgcController : EController {
    void UpdateMotors();
    int StopMotorTwo();
};

int ENgcController::StopMotorTwo() {
    int result = EController::StopMotorTwo();
    if (result == 0) {
        return 0;
    }
    UpdateMotors();
    return 1;
}
