#ifndef ENGCCONTROLLER_H
#define ENGCCONTROLLER_H

#include "types.h"

// ENgcController - struct layout extracted from assembly analysis
// Estimated minimum size: 0x210 (528 bytes)
// 3 known fields (3 named), 24 methods

class ENgcController {
public:
    // Constructors / Destructors
    ENgcController(void)  // 0x808A6DA4
    ~ENgcController(void);  // 0x808A6FFC

    // Methods
    void Update(PADStatus);  // 0x808A6DF0 (524B)
    /* ? */ GetButtons(PADStatus &);  // 0x808A72D4 (912B)
    /* ? */ GetStick(PADStatus &, int, int);  // 0x808A7664 (536B)
    bool HasVibration(void);  // 0x808A7084 (40B)
    void VibrateMotorOne(float);  // 0x808A70AC (112B)
    void VibrateMotorTwo(float);  // 0x808A711C (112B)
    void StopMotorOne(void);  // 0x808A718C (96B)
    void StopMotorTwo(void);  // 0x808A71EC (96B)
    bool IsMotorOneActive(void);  // 0x808A724C (68B)
    bool IsMotorTwoActive(void);  // 0x808A7290 (68B)
    void UpdateMotors(void);  // 0x808A78F8 (244B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x1DC];  // 0x000
    f32 m_motors;  // 0x1DC [R] (UpdateMotors)
    f32 m_motors_1E0;  // 0x1E0 [R] (UpdateMotors)
    u8 _pad_1E4[0x28];  // 0x1E4
    u32 m_motors_20C;  // 0x20C [R] (UpdateMotors)
};

#endif // ENGCCONTROLLER_H
