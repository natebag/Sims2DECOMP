// 0x80304774 (12 bytes) - EController::StopMotorOne(float)
// stfs f1, 484(r3); li r3, 1; blr

class EController {
    char pad[484]; // 0x000-0x1E3
    float m_motorOne; // 0x1E4
public:
    int StopMotorOne(float val);
};

int EController::StopMotorOne(float val) {
    m_motorOne = val;
    return 1;
}
