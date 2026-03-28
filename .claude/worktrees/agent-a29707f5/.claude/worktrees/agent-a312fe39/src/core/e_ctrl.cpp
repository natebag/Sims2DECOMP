// e_ctrl.cpp - EController small functions
// From: engine_ngc_release_dvd.lib(e_ctrl.obj)
// Small functions (<=64 bytes) decompiled from e_ctrl.obj

#include "core/e_app.h"

// ============================================================================
// External references
// ============================================================================

extern "C" {
    void EController_BtnDataClear(void* data, int flags);
    void EController_BtnDataUpdate(void* dst, void* src);
    void EController_BtnDataCopy(void* dst, void* src);
    unsigned int EController_ComputeExclMask(unsigned int filter);
}

// ============================================================================
// EController small functions from e_ctrl.obj (30 functions)
// ============================================================================

// EController::ClearAllData - 0x803041e0 (44 bytes)
// Clears button data for both prev and current, using status bit 0
void EController::ClearAllData(void) {
    int status = *(int*)((char*)this + 0x04);
    void* prevData = *(void**)((char*)this + 0x1FC);
    // status >> 1 & 1 = bit 1 of status
    EController_BtnDataClear(prevData, (status >> 1) & 1);
}

// EController::ClearAppData - 0x8030420c (36 bytes)
// Clears current button data
void EController::ClearAppData(bool b) {
    void* curData = *(void**)((char*)this + 0x200);
    EController_BtnDataClear(curData, (int)b);
}

// EBtnToCmdAssoc::CompareControllerCommands - 0x80304230 (32 bytes)
// Compares two command values for qsort
int EBtnToCmdAssoc::CompareControllerCommands(void* a, void* b) {
    unsigned int va = *(unsigned int*)a;
    unsigned int vb = *(unsigned int*)b;
    if (va < vb) return -1;
    return (va > vb) ? 1 : 0;
}

// EController::OverrideStatus - 0x80304294 (8 bytes)
// Sets controller status directly
void EController::OverrideStatus(int status) {
    *(int*)((char*)this + 0x04) = status;
}

// EController::SwapAxes - 0x8030429c (24 bytes)
// Toggles axis swap flag (XOR with 1)
void EController::SwapAxes(int axis) {
    int offset = axis * 4;
    int* table = (int*)((char*)this + 0x18C);
    table[axis] ^= 1;
}

// EController::InvertAxis - 0x803042b4 (32 bytes)
// Negates a direction modifier
void EController::InvertAxis(int axis, int sub) {
    int idx = sub * 4 + axis * 8;
    int* table = (int*)((char*)this + 0x194);
    int* entry = (int*)((char*)table + idx);
    *entry = -*entry;
}

// EController::Flush - 0x8030440c (40 bytes)
// Clears all button state in both data buffers
void EController::Flush(void) {
    void* curData = *(void**)((char*)this + 0x200);
    // Clear hold/down/pressed/released masks
    *(int*)((char*)curData + 0x20) = 0;
    *(int*)((char*)curData + 0x18) = 0;
    void* prevData = *(void**)((char*)this + 0x1FC);
    *(int*)((char*)prevData + 0x20) = 0;
    *(int*)((char*)prevData + 0x18) = 0;
}

// EController::HasVibration - 0x80304434 (8 bytes)
// Always returns 0 (no vibration support on NGC in this build)
int EController::HasVibration(void) const {
    return 0;
}

// EController::IsMotorOneActive - 0x8030443c (28 bytes)
// Returns 1 if motor1 strength > threshold
int EController::IsMotorOneActive(void) const {
    float strength = *(float*)((char*)this + 0x1DC);
    // Compares against constant from rodata
    // Uses cr7 comparison and mfcr extraction
    return (strength > 0.0f) ? 1 : 0;
}

// EController::IsMotorTwoActive - 0x80304458 (28 bytes)
// Returns 1 if motor2 strength > threshold
int EController::IsMotorTwoActive(void) const {
    float strength = *(float*)((char*)this + 0x1E0);
    return (strength > 0.0f) ? 1 : 0;
}

// EController::StopMotorOne - 0x80304774 (12 bytes)
// Sets motor1 decay time
int EController::StopMotorOne(float val) {
    *(float*)((char*)this + 0x1E4) = val;
    return 1;
}

// EController::StopMotorTwo - 0x803047e4 (12 bytes)
// Sets motor2 decay time
int EController::StopMotorTwo(float val) {
    *(float*)((char*)this + 0x1E8) = val;
    return 1;
}

// EController::ResetControllerData - 0x803049c4 (36 bytes)
// Resets prev button data
void EController::ResetControllerData(bool clearAll) {
    void* prevData = *(void**)((char*)this + 0x1FC);
    EController_BtnDataUpdate(prevData, 0);
}

// EController::IsControlFake - 0x80304d10 (8 bytes)
int EController::IsControlFake(void) {
    return *(int*)((char*)this + 0x1AC);
}

// EController::SetControlFake - 0x80304d18 (8 bytes)
void EController::SetControlFake(bool fake) {
    *(int*)((char*)this + 0x1AC) = (int)fake;
}

// EController::SetFakeButtons - 0x80304d20 (8 bytes)
void EController::SetFakeButtons(unsigned int btns) {
    *(unsigned int*)((char*)this + 0x1B0) = btns;
}

// EController::SetBtnExcl - 0x80304fe8 (16 bytes)
// Sets exclusive button flag in current button data
void EController::SetBtnExcl(void) {
    void* curData = *(void**)((char*)this + 0x200);
    *(int*)((char*)curData + 0x78) = 1;
}

// EController::GetBtnResultAny - 0x8030503c (64 bytes)
// Checks if any button in mask is set, with exclusivity handling
unsigned int EController::GetBtnResultAny(unsigned int mask, bool excl, unsigned int filter) {
    unsigned int result = mask & filter;
    if (result == 0) return 0;
    if (!excl) return 1;
    // Check exclusive flag
    void* curData = *(void**)((char*)this + 0x200);
    if (*(int*)((char*)curData + 0x78) != 0) return 0;
    // Set exclusive flag
    *(int*)((char*)curData + 0x78) = 1;
    return 1;
}

// EBtnToCmdAssoc::CompareControllerCommandToKey - 0x8030507c (32 bytes)
// Compares command values for bsearch
int EBtnToCmdAssoc::CompareControllerCommandToKey(void* a, void* b) {
    unsigned int va = *(unsigned int*)a;
    unsigned int vb = *(unsigned int*)b;
    if (va < vb) return -1;
    return (va > vb) ? 1 : 0;
}

// EController::GetBtnDownMask - 0x80305778 (56 bytes)
// Returns buttons that are currently held down (filtered)
// NON_MATCHING - calls EController_ComputeExclMask then andc's with btn_data
unsigned int EController::GetBtnDownMask(unsigned int filter) {
    unsigned int exclMask = EController_ComputeExclMask(filter);
    void* curData = *(void**)((char*)this + 0x200);
    unsigned int down = *(unsigned int*)((char*)curData + 0x08);
    return down & ~exclMask;
}

// EController::GetBtnUpMask - 0x803057b0 (56 bytes)
// Returns buttons that are currently up (filtered)
unsigned int EController::GetBtnUpMask(unsigned int filter) {
    unsigned int exclMask = EController_ComputeExclMask(filter);
    void* curData = *(void**)((char*)this + 0x200);
    unsigned int up = *(unsigned int*)((char*)curData + 0x10);
    return up & ~exclMask;
}

// EController::GetBtnPressedMask - 0x803057e8 (56 bytes)
// Returns buttons just pressed this frame (filtered)
unsigned int EController::GetBtnPressedMask(unsigned int filter) {
    unsigned int exclMask = EController_ComputeExclMask(filter);
    void* curData = *(void**)((char*)this + 0x200);
    unsigned int pressed = *(unsigned int*)((char*)curData + 0x18);
    return pressed & ~exclMask;
}

// EController::GetBtnReleasedMask - 0x80305820 (56 bytes)
// Returns buttons just released this frame (filtered)
unsigned int EController::GetBtnReleasedMask(unsigned int filter) {
    unsigned int exclMask = EController_ComputeExclMask(filter);
    void* curData = *(void**)((char*)this + 0x200);
    unsigned int released = *(unsigned int*)((char*)curData + 0x20);
    return released & ~exclMask;
}

// EController::GetBtnRepeatMask - 0x80305858 (52 bytes)
// Returns repeat mask (filtered)
unsigned int EController::GetBtnRepeatMask(unsigned int filter) {
    unsigned int exclMask = EController_ComputeExclMask(filter);
    unsigned int repeat = *(unsigned int*)((char*)this + 0x1B4);
    return repeat & ~exclMask;
}

// EController::GetId - 0x8030588c (8 bytes)
// Returns controller index
int EController::GetId(void) {
    return *(int*)((char*)this + 0x00);
}

// EController::GetStatus - 0x80305894 (8 bytes)
// Returns controller status
int EController::GetStatus(void) {
    return *(int*)((char*)this + 0x04);
}

// EController::IsStable - 0x8030589c (12 bytes)
// Returns bit 1 of status (stable flag)
int EController::IsStable(void) {
    int status = *(int*)((char*)this + 0x04);
    return (status >> 1) & 1;
}

// EController::AreAxesSwapped - 0x80305d58 (16 bytes)
// Returns swap flag for given axis
int EController::AreAxesSwapped(int axis) {
    int* table = (int*)((char*)this + 0x18C);
    return table[axis];
}

// EController::GetDirectionModifier - 0x80305d68 (24 bytes)
// Returns direction modifier for given axis/sub
int EController::GetDirectionModifier(int axis, int sub) {
    int idx = sub * 4 + axis * 8;
    int* table = (int*)((char*)this + 0x194);
    return *(int*)((char*)table + idx);
}
