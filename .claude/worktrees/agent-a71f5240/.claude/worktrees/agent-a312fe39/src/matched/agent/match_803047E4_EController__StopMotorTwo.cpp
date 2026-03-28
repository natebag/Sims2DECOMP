// 0x803047E4 (12 bytes) - EController::StopMotorTwo(float)
// stfs f1, 488(r3); li r3, 1; blr

class EController {
    char pad[488]; // 0x000-0x1E7
    float m_motorTwo; // 0x1E8
public:
    int StopMotorTwo(float val);
};

int EController::StopMotorTwo(float val) {
    m_motorTwo = val;
    return 1;
}
