// 0x80304458 (28B) EController::IsMotorTwoActive(void) const
// Compare m_motor_two (float at offset 480) against global constant, return GT bit.

class EController {
public:
    char pad[480];
    float m_motorTwo;
    bool IsMotorTwoActive() const;
};

extern char s_motorTwoThreshold_store[];

bool EController::IsMotorTwoActive() const {
    return m_motorTwo > *(float*)s_motorTwoThreshold_store;
}
