// ============================================================================
// simulator.cpp - Game simulator implementation
// Object file: simulator.obj
// All small functions (<=64 bytes) from the DVD map
// ============================================================================

#include "core/simulator.h"
#include "types.h"

// External functions
extern void* operator new(u32 size);
extern void operator delete(void* ptr);

// Global variable stored relative to r13
extern float gSavedDt; // r13 - 26800 (0x9750)

// ============================================================================
// cSimulator::CreateInstance(void) - 0x801401e4 (40 bytes)
// NON_MATCHING - GCC generates different new+ctor inlining pattern
// ============================================================================
cSimulator* cSimulator::CreateInstance(void) {
    cSimulatorImpl* impl = new cSimulatorImpl();
    return impl;
}

// ============================================================================
// cSimulator::DestroyInstance(cSimulator *) - 0x8014020c (64 bytes)
// NON_MATCHING - original uses vtable this-adjust + blrl pattern
// ============================================================================
void cSimulator::DestroyInstance(cSimulator* sim) {
    if (sim) {
        delete sim;
    }
}

// ============================================================================
// cSimulatorImpl::CommitPendingFunds(void) - 0x80140924 (56 bytes)
// NON_MATCHING - needs exact register allocation for cap check
// Caps funds at 999999 (0x000F423F)
// ============================================================================
void cSimulatorImpl::CommitPendingFunds(void) {
    if (m_pendingFunds == 0) return;
    m_funds += m_pendingFunds;
    if (m_funds > 999999) {
        m_funds = 999999;
    }
    m_pendingFunds = 0;
}

// ============================================================================
// cSimulatorImpl::GetSpeed(void) - 0x80141134 (8 bytes)
// lha r3, 52(r3); blr
// ============================================================================
short cSimulatorImpl::GetSpeed(void) {
    return m_speed;
}

// ============================================================================
// cSimulatorImpl::IsPaused(void) - 0x801412e8 (52 bytes)
// NON_MATCHING - calls virtual function through vtable
// ============================================================================
bool cSimulatorImpl::IsPaused(void) {
    // Original calls a virtual method through vtable at offset 0x70/0x74
    // which checks pause state. Stubbed.
    return false; // TODO: needs vtable dispatch
}

// ============================================================================
// cSimulatorImpl::IsStalled(void) - 0x8014131c (8 bytes)
// lwz r3, 156(r3); blr
// ============================================================================
bool cSimulatorImpl::IsStalled(void) {
    return m_pauseStallCount != 0;
}

// ============================================================================
// cSimulatorImpl::IsPausedAtAll(void) - 0x80141324 (44 bytes)
// Checks m_stalledCount at +0x98, then m_pauseCount at +0x36
// ============================================================================
bool cSimulatorImpl::IsPausedAtAll(void) {
    if (m_stalledCount != 0) {
        return true;
    }
    if (m_pauseCount != 0) {
        return true;
    }
    return false;
}

// ============================================================================
// cSimulatorImpl::GetFunds(tFundsPlayerNumber) - 0x801413dc (16 bytes)
// lwz r0, 120(r3); lwz r3, 116(r3); add r3,r3,r0; blr
// ============================================================================
int cSimulatorImpl::GetFunds(tFundsPlayerNumber player) {
    return m_funds + m_pendingFunds;
}

// ============================================================================
// cSimulatorImpl::GetDaysRunning(void) - 0x801415dc (8 bytes)
// lha r3, 76(r3); blr
// ============================================================================
short cSimulatorImpl::GetDaysRunning(void) {
    return m_daysRunning;
}

// ============================================================================
// cSimulatorImpl::SetGlobal(short, short) - 0x801415e4 (16 bytes)
// slwi r4,r4,1; addi r3,r3,20; sthx r5,r3,r4; blr
// ============================================================================
void cSimulatorImpl::SetGlobal(short index, short value) {
    // Stores value at this+0x14 + index*2
    short* globals = (short*)((char*)this + 0x14);
    globals[index] = value;
}

// ============================================================================
// cSimulatorImpl::RestoreTrueDt(void) - 0x801415f4 (24 bytes)
// Loads saved dt from r13-relative global, stores 1.0 as new override
// ============================================================================
void cSimulatorImpl::RestoreTrueDt(void) {
    float saved = gSavedDt;
    // Stores 1.0f to m_dtOverride
    m_dtOverride = 1.0f;
    // Stores saved value to the r13-relative global
    gSavedDt = saved;
    // Actually stores saved into m_dtOverride
    m_dtOverride = saved; // NON_MATCHING - instruction order differs
}

// ============================================================================
// BeingReset(void) - 0x8014160c (8 bytes)
// li r3, 0; blr
// ============================================================================
int BeingReset(void) {
    return 0;
}

// ============================================================================
// cSimulatorImpl::GetLightingIntensity(void) - 0x80141a2c (12 bytes)
// lhz r3, 104(r3); clrlwi r3,r3,23; blr
// Extracts bits 0-8 from m_lightingFlags
// ============================================================================
int cSimulatorImpl::GetLightingIntensity(void) {
    return m_lightingFlags & 0x1FF;
}

// ============================================================================
// cSimulatorImpl::GetStrobeOn(void) - 0x80141a38 (12 bytes)
// lhz r3, 104(r3); rlwinm r3,r3,23,31,31; blr
// Extracts bit 9 from m_lightingFlags
// ============================================================================
int cSimulatorImpl::GetStrobeOn(void) {
    return (m_lightingFlags >> 9) & 1;
}

// ============================================================================
// cSimulatorImpl::SetGbaStatus(short) - 0x80141a44 (8 bytes)
// sth r4, 106(r3); blr
// ============================================================================
void cSimulatorImpl::SetGbaStatus(short status) {
    m_gbaStatus = status;
}

// ============================================================================
// cSimulatorImpl::SetGbaMoney(short) - 0x80141a4c (8 bytes)
// sth r4, 108(r3); blr
// ============================================================================
void cSimulatorImpl::SetGbaMoney(short money) {
    m_gbaMoney = money;
}

// ============================================================================
// cSimulatorImpl::SetGbaNumMinigames(short) - 0x80141a54 (8 bytes)
// sth r4, 110(r3); blr
// ============================================================================
void cSimulatorImpl::SetGbaNumMinigames(short num) {
    m_gbaNumMinigames = num;
}

// ============================================================================
// cSimulatorImpl::PostSecondOfDay(int) - 0x80141a5c (40 bytes)
// Calculates seconds elapsed from hours/minutes/seconds globals and stores delta
// ============================================================================
void cSimulatorImpl::PostSecondOfDay(int second) {
    short* globals = (short*)((char*)this + 0x14);
    short secs = globals[5];    // +0x1e = seconds (index 5)
    short mins = globals[0];    // +0x14 = hours (index 0)
    int totalSecs = secs * 60;
    short hrs = globals[3];     // +0x1a = ? (index 3)
    totalSecs += hrs;
    totalSecs += mins * 3600;
    m_postSecondOfDay = second - totalSecs;
}

// ============================================================================
// cSimulatorImpl::GetSpeedMultiplier(void) - 0x80141a84 (8 bytes)
// lfs f1, 168(r3); blr
// ============================================================================
float cSimulatorImpl::GetSpeedMultiplier(void) {
    return m_speedMultiplier;
}

// ============================================================================
// cSimulatorImpl::IsStopped(void) - 0x80141a8c (44 bytes)
// Checks m_updateFlag and m_stopFlag
// ============================================================================
bool cSimulatorImpl::IsStopped(void) {
    if (m_updateFlag != 0) {
        return false;
    }
    if (m_stopFlag != 0) {
        return true;
    }
    return false;
}

// ============================================================================
// cSimulatorImpl::GetMode(void) - 0x80141ab8 (8 bytes)
// lha r3, 58(r3); blr
// ============================================================================
short cSimulatorImpl::GetMode(void) {
    return m_mode;
}

// ============================================================================
// cSimulatorImpl::SetMode(cSimulator::Mode) - 0x80141ac0 (8 bytes)
// sth r4, 58(r3); blr
// ============================================================================
void cSimulatorImpl::SetMode(cSimulator::Mode mode) {
    m_mode = (short)mode;
}

// ============================================================================
// cSimulatorImpl::GetTicks(void) - 0x80141ac8 (8 bytes)
// lwz r3, 124(r3); blr
// ============================================================================
int cSimulatorImpl::GetTicks(void) {
    return m_ticks;
}

// ============================================================================
// cSimulatorImpl::GetTimeOfDay(void) - 0x80141ad0 (56 bytes)
// NON_MATCHING - calls virtual function at vtable offset 0x30/0x34 with r4=4
// ============================================================================
void cSimulatorImpl::GetTimeOfDay(void) {
    // Original: loads vtable, gets fn at +0x30/0x34, calls with r4=4
    // TODO: needs vtable dispatch
}

// ============================================================================
// cSimulatorImpl::SetTimeOfDay(TimeOfDay) - 0x80141b08 (8 bytes)
// sth r4, 28(r3); blr
// ============================================================================
void cSimulatorImpl::SetTimeOfDay(TimeOfDay tod) {
    // sth r4, 28(r3); blr
    *(short*)((char*)this + 0x1c) = (short)tod;
}

// ============================================================================
// cSimulatorImpl::GetLotValue(void) - 0x80141b10 (8 bytes)
// lwz r3, 132(r3); blr
// ============================================================================
int cSimulatorImpl::GetLotValue(void) {
    return m_lotValue;
}

// ============================================================================
// cSimulatorImpl::SetLotValue(int) - 0x80141b18 (8 bytes)
// stw r4, 132(r3); blr
// ============================================================================
void cSimulatorImpl::SetLotValue(int value) {
    m_lotValue = value;
}

// ============================================================================
// cSimulatorImpl::GetArchValue(void) - 0x80141b20 (8 bytes)
// lwz r3, 140(r3); blr
// ============================================================================
int cSimulatorImpl::GetArchValue(void) {
    return m_archValue;
}

// ============================================================================
// cSimulatorImpl::SetArchValue(int) - 0x80141b28 (48 bytes)
// Stores value and also computes high/low parts (value / 10000, value % 10000)
// ============================================================================
void cSimulatorImpl::SetArchValue(int value) {
    m_archValue = value;
    int high = value / 10000;
    int low = value - (high * 10000);
    m_archValHigh = (short)high;
    m_archValLow = (short)low;
}

// ============================================================================
// cSimulatorImpl::GetObjectsValue(void) - 0x80141b58 (8 bytes)
// lwz r3, 136(r3); blr
// ============================================================================
int cSimulatorImpl::GetObjectsValue(void) {
    return m_objectsValue;
}

// ============================================================================
// cSimulatorImpl::SetObjectsValue(int) - 0x80141b60 (48 bytes)
// Same pattern as SetArchValue
// ============================================================================
void cSimulatorImpl::SetObjectsValue(int value) {
    m_objectsValue = value;
    int high = value / 10000;
    int low = value - (high * 10000);
    m_objectsValHigh = (short)high;
    m_objectsValLow = (short)low;
}

// ============================================================================
// cSimulatorImpl::GetProbe(void) - 0x80141b90 (8 bytes)
// lwz r3, 148(r3); blr
// ============================================================================
SimLoopProbe* cSimulatorImpl::GetProbe(void) {
    return m_probe;
}

// ============================================================================
// cSimulatorImpl::SetProbe(SimLoopProbe *) - 0x80141b98 (8 bytes)
// stw r4, 148(r3); blr
// ============================================================================
void cSimulatorImpl::SetProbe(SimLoopProbe* probe) {
    m_probe = probe;
}

// ============================================================================
// cSimulatorImpl::GetPassiveInfluenceSystem(void) - 0x80141ba0 (8 bytes)
// lwz r3, 372(r3); blr
// ============================================================================
SimLoopProbe* cSimulatorImpl::GetPassiveInfluenceSystem(void) {
    return m_passiveInfluence;
}

// ============================================================================
// ExpenseReport::reset(void) - 0x803ad480 (32 bytes)
// Zeroes 8 u32s in reverse order from offset +0x1c downward
// ============================================================================
void ExpenseReport::reset(void) {
    u32* p = (u32*)((char*)this + 0x1c);
    for (int i = 0; i < 8; i++) {
        *p = 0;
        p--;
    }
}

// ============================================================================
// cSimulator::~cSimulator(void) - 0x803ad4a0 (52 bytes)
// NON_MATCHING - SN generates vtable store + r4&1 delete check
// ============================================================================
cSimulator::~cSimulator(void) {
}
