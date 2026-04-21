// 0x8030443C (28B) EController::IsMotorOneActive(void) const
// Compare m_motor_one (float at offset 476) against global constant, return GT bit.

class EController {
public:
    char pad[476];
    float m_motorOne;
    bool IsMotorOneActive() const;
};

extern char s_motorOneThreshold_store[];

bool EController::IsMotorOneActive() const {
    return m_motorOne > *(float*)s_motorOneThreshold_store;
}
