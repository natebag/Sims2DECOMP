#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "types.h"

// Forward declarations
class cSimulatorImpl;
class ReconBuffer;
class ReconObject;
class SimLoopProbe;
// TimeOfDay is likely an enum or small integral type
typedef int TimeOfDay;

// ============================================================================
// ExpenseReport - Tracks expenses/income by category
// Size: 0x24 (36 bytes) - 8 ints for categories + 1 header
// ============================================================================
struct ExpenseReport {
    void reset(void);
    // +0x00: 8 u32 fields covering offsets 0x1c..0x38 (relative to simulator)
    u32 m_data[8]; // zeroed in reverse order from offset+0x1c down
};

// ============================================================================
// cSimulator - Abstract base class for the game simulator
// Size: at least 0x08
// ============================================================================
class cSimulator {
public:
    // Nested types
    typedef int tFundsPlayerNumber;
    enum Mode {
        MODE_0 = 0,
        MODE_1 = 1,
        MODE_2 = 2,
        MODE_3 = 3
    };

    static cSimulator* CreateInstance(void);
    static void DestroyInstance(cSimulator* sim);

    virtual ~cSimulator(void);

    // Pure virtuals implemented by cSimulatorImpl
};

// ============================================================================
// cSimulatorImpl - Full implementation of the simulator
// Size: 0x180 (384 bytes)
//
// Member layout (from disassembly):
//   +0x00: vtable pointer
//   +0x14: short m_globals[N]  (accessed via index*2 from +0x14)
//   +0x1c: TimeOfDay fields start
//   +0x14: short m_hours      (accessed at +0x14 via GetGlobal index)
//   +0x1e: short m_minutes
//   +0x20: short m_seconds
//   +0x2a: short m_resetDay
//   +0x34: short m_speed
//   +0x36: short m_pauseCount
//   +0x3a: short m_mode
//   +0x4c: short m_daysRunning
//   +0x56: short m_objectsValueLow
//   +0x58: short m_objectsValueHigh
//   +0x5a: short m_archValueLow
//   +0x5c: short m_archValueHigh
//   +0x5e: short m_pauseTimer
//   +0x68: u16 m_lightingFlags (bits 0-8 = intensity, bit 9 = strobe)
//   +0x6a: short m_gbaStatus
//   +0x6c: short m_gbaMoney
//   +0x6e: short m_gbaNumMinigames
//   +0x70: short m_timerHours
//   +0x72: short m_timerMinutes
//   +0x74: int m_funds
//   +0x78: int m_pendingFunds
//   +0x7c: int m_ticks
//   +0x80: int m_postSecondOfDay
//   +0x84: int m_lotValue
//   +0x88: int m_objectsValue
//   +0x8c: int m_archValue
//   +0x90: short m_dummy90[2]
//   +0x94: SimLoopProbe* m_probe
//   +0x98: int m_stalledCount
//   +0x9c: int m_pauseStallCount
//   +0xa0: float m_accumulator
//   +0xa4: float m_dtOverride
//   +0xa8: float m_speedMultiplier
//   +0xac: float m_timerAccum
//   +0xb0: float m_timerTarget
//   +0xb4..+0x174: expense data (ExpenseReport arrays)
//   +0x174: SimLoopProbe* m_passiveInfluence
//   +0x178: int m_stopFlag
//   +0x17c: int m_updateFlag
// ============================================================================
class cSimulatorImpl : public cSimulator {
public:
    cSimulatorImpl(void);
    virtual ~cSimulatorImpl(void);

    // Speed / pausing
    short GetSpeed(void);
    bool IsPaused(void);
    bool IsStalled(void);
    bool IsPausedAtAll(void);
    bool IsStopped(void);
    float GetSpeedMultiplier(void);

    // Funds
    int GetFunds(tFundsPlayerNumber player);
    void CommitPendingFunds(void);

    // Time
    short GetDaysRunning(void);
    void SetGlobal(short index, short value);
    void RestoreTrueDt(void);
    void GetTimeOfDay(void);
    void SetTimeOfDay(TimeOfDay tod);
    void PostSecondOfDay(int second);
    int GetTicks(void);

    // Mode
    short GetMode(void);
    void SetMode(cSimulator::Mode mode);

    // Lot/arch/objects value
    int GetLotValue(void);
    void SetLotValue(int value);
    int GetArchValue(void);
    void SetArchValue(int value);
    int GetObjectsValue(void);
    void SetObjectsValue(int value);

    // Lighting
    int GetLightingIntensity(void);
    int GetStrobeOn(void);

    // GBA link
    void SetGbaStatus(short status);
    void SetGbaMoney(short money);
    void SetGbaNumMinigames(short num);

    // Probe
    SimLoopProbe* GetProbe(void);
    void SetProbe(SimLoopProbe* probe);
    SimLoopProbe* GetPassiveInfluenceSystem(void);

    // Reset status
    // Data members (partial - for compilation)
    char _pad_04[0x30];           // +0x04
    short m_speed;                // +0x34
    short m_pauseCount;           // +0x36
    char _pad_38[0x02];           // +0x38
    short m_mode;                 // +0x3a
    char _pad_3c[0x10];           // +0x3c
    short m_daysRunning;          // +0x4c
    char _pad_4e[0x08];           // +0x4e
    short m_objectsValLow;        // +0x56
    short m_objectsValHigh;       // +0x58
    short m_archValLow;           // +0x5a
    short m_archValHigh;          // +0x5c
    short m_pauseTimer;           // +0x5e
    char _pad_60[0x08];           // +0x60
    u16 m_lightingFlags;          // +0x68
    short m_gbaStatus;            // +0x6a
    short m_gbaMoney;             // +0x6c
    short m_gbaNumMinigames;      // +0x6e
    char _pad_70[0x04];           // +0x70
    int m_funds;                  // +0x74
    int m_pendingFunds;           // +0x78
    int m_ticks;                  // +0x7c
    int m_postSecondOfDay;        // +0x80
    int m_lotValue;               // +0x84
    int m_objectsValue;           // +0x88
    int m_archValue;              // +0x8c
    char _pad_90[0x04];           // +0x90
    SimLoopProbe* m_probe;        // +0x94
    int m_stalledCount;           // +0x98
    int m_pauseStallCount;        // +0x9c
    float m_accumulator;          // +0xa0
    float m_dtOverride;           // +0xa4
    float m_speedMultiplier;      // +0xa8
    char _pad_ac[0xC8];           // +0xac
    SimLoopProbe* m_passiveInfluence; // +0x174
    int m_stopFlag;               // +0x178
    int m_updateFlag;             // +0x17c
};

// Free function
int BeingReset(void);

// External: operator new/delete
extern void* operator new(u32 size);
extern void operator delete(void* ptr);

#endif // SIMULATOR_H
