// 0x8006A69C SAnimator2::GetMovementVelocityFromStyle (140B)

extern float g_velRun1[1] __attribute__((section(".data")));      // 0x803D4D08
extern float g_velRun2[1] __attribute__((section(".data")));      // 0x803D4D0C
extern float g_velRun3[1] __attribute__((section(".data")));      // 0x803D4D10

class SAnimator2 {
    char pad[0x9C];
    float m_defaultVel;  // 0x9C
    float m_walkVel;     // 0xA0
    char pad2[4];        // 0xA4
    float m_runVel;      // 0xA8
    float m_sprintVel;   // 0xAC
public:
    enum eWalkRunStyle {
        kWalk = 1,
        kRun = 2,
        kSprint = 3,
        kStyle4 = 4,
        kStyle5 = 5,
        kStyle6 = 6,
        kStyle7 = 7,
        kStyle8 = 8,
    };
    float GetMovementVelocityFromStyle(eWalkRunStyle style);
};

float SAnimator2::GetMovementVelocityFromStyle(eWalkRunStyle style) {
    float f = m_defaultVel;
    if (style == kRun) f = m_runVel;
    else if (style == kSprint) f = m_sprintVel;
    else if (style == kWalk) f = m_walkVel;
    else if (style == kStyle7) f = g_velRun1[0];
    else if (style == kStyle8) f = g_velRun2[0];
    else if (style == kStyle4) f = g_velRun3[0];
    else if (style == kStyle5) f = g_velRun1[0];
    else if (style == kStyle6) f = g_velRun3[0];
    return f;
}
