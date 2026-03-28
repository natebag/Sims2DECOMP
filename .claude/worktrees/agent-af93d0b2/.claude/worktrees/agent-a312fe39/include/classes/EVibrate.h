#ifndef EVIBRATE_H
#define EVIBRATE_H

#include "types.h"

// EVibrate - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (1 named), 49 methods

class EVibrate {
public:
    // Constructors / Destructors
    EVibrate(void)  // 0x80822098
    ~EVibrate(void);  // 0x80822108

    // Methods
    bool IsControllerReady(unsigned char);  // 0x80822338 (92B)
    void Enable(void);  // 0x80822158 (160B)
    void TurnOn(unsigned char);  // 0x8082224C (236B)
    bool IsControllerOn(unsigned char);  // 0x8082245C (128B)
    void TurnOff(unsigned char);  // 0x80822394 (200B)
    void Disable(void);  // 0x808221F8 (40B)
    void VibrateAll(unsigned char, float, float, float, float);  // 0x80822AC8 (208B)
    void StopAllVibration(void);  // 0x80822F24 (224B)
    void UpdateVibration(void);  // 0x80823004 (40B)
    bool IsOn(void);  // 0x80822220 (44B)
    bool IsPortInvalid(unsigned char);  // 0x8082302C (56B)
    void Pause(void);  // 0x808224DC (328B)
    void Resume(void);  // 0x80822624 (244B)
    void VibrateMotorOne(unsigned char, float);  // 0x80822718 (184B)
    void VibrateMotorOne(unsigned char, float, float);  // 0x808227D0 (192B)
    void VibrateMotorTwo(unsigned char, float);  // 0x80822890 (184B)
    void VibrateMotorTwo(unsigned char, float, float);  // 0x80822948 (192B)
    void VibrateAll(unsigned char, float, float);  // 0x80822A08 (192B)
    void StopMotorOne(unsigned char);  // 0x80822B98 (180B)
    void StopMotorOne(unsigned char, float);  // 0x80822C4C (184B)
    void StopMotorTwo(unsigned char);  // 0x80822D04 (180B)
    void StopMotorTwo(unsigned char, float);  // 0x80822DB8 (184B)
    void StopVibration(unsigned char);  // 0x80822E70 (180B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EVibrate, Enable)
    u32 m_field_004;  // 0x004 [R/W] (EVibrate, Enable, Pause, ...)
};

#endif // EVIBRATE_H
