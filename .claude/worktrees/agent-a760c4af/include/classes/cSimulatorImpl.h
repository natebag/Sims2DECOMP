#ifndef CSIMULATORIMPL_H
#define CSIMULATORIMPL_H

#include "types.h"

// cSimulatorImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x180 (384 bytes)
// 59 known fields (16 named), 110 methods

class cSimulatorImpl {
public:
    // Constructors / Destructors
    cSimulatorImpl(void)  // 0x803B7704
    ~cSimulatorImpl(void);  // 0x803B7A0C

    // Methods
    void SetMode(cSimulator::Mode);  // 0x803BB634 (44B)
    void Init(void);  // 0x803B783C (464B)
    void DoStream(ReconBuffer *, int);  // 0x803B7B60 (1172B)
    void UpdateSpeed(void);  // 0x803B91D4 (460B)
    void DoCommand(short, int);  // 0x803B7FF4 (400B)
    void CommitPendingFunds(void);  // 0x803B8184 (108B)
    void SimulateOneTick(void);  // 0x803B81F0 (1596B)
    void TickAllObjects(void);  // 0x803B8AB0 (1672B)
    void ComputeTimeOfDay(void);  // 0x803B882C (164B)
    void HourTimeOfDayLastChanged(void);  // 0x803B88D0 (240B)
    void HourTimeOfDayNextChanges(void);  // 0x803B89C0 (240B)
    void SetSpeed(SimSpeed);  // 0x803B9138 (100B)
    /* ? */ GetSpeed(void);  // 0x803B919C (56B)
    void Pause(void);  // 0x803B93A0 (152B)
    void Resume(void);  // 0x803B9438 (160B)
    bool IsPaused(void);  // 0x803B94D8 (112B)
    bool IsStalled(void);  // 0x803B9548 (52B)
    bool IsPausedAtAll(void);  // 0x803B957C (92B)
    void SetCurrentHour(int);  // 0x803B95D8 (220B)
    /* ? */ GetFunds(cSimulator::tFundsPlayerNumber);  // 0x803B96B4 (56B)
    void SetFunds(int, cSimulator::tFundsPlayerNumber);  // 0x803B96EC (520B)
    void Spend(ExpenseType, int, cSimulator::tFundsPlayerNumber);  // 0x803B98F4 (156B)
    void ClearHistory(void);  // 0x803B9990 (136B)
    /* ? */ GetDaysRunning(void);  // 0x803B9A18 (48B)
    void SetGlobal(short, short);  // 0x803B9A48 (76B)
    void RestoreTrueDt(void);  // 0x803B9A94 (200B)
    void Simulate(void);  // 0x803B9B80 (1160B)
    /* ? */ GetTodaysExpenses(ExpenseReport *);  // 0x803BA008 (136B)
    /* ? */ GetPreviousExpenses(int, ExpenseReport *);  // 0x803BA090 (308B)
    /* ? */ GetExpensesHistory(ExpenseReport *);  // 0x803BA1C4 (232B)
    /* ? */ GetGlobal(short);  // 0x803BA2AC (188B)
    /* ? */ GetGlobalRef(short, short **);  // 0x803BA368 (212B)
    /* ? */ GetLightingIntensity(void);  // 0x803BA43C (84B)
    /* ? */ GetStrobeOn(void);  // 0x803BA490 (80B)
    void SetGbaStatus(short);  // 0x803BA4E0 (52B)
    void SetGbaMoney(short);  // 0x803BA514 (52B)
    void SetGbaNumMinigames(short);  // 0x803BA548 (52B)
    void PostSecondOfDay(int);  // 0x803BA57C (96B)
    /* ? */ GetSpeedMultiplier(void);  // 0x803BB588 (44B)
    bool IsStopped(void);  // 0x803BB5B4 (80B)
    /* ? */ GetMode(void);  // 0x803BB604 (48B)
    /* ? */ GetTicks(void);  // 0x803BB660 (44B)
    /* ? */ GetTimeOfDay(void);  // 0x803BB68C (112B)
    void SetTimeOfDay(TimeOfDay);  // 0x803BB6FC (44B)
    /* ? */ GetLotValue(void);  // 0x803BB728 (44B)
    void SetLotValue(int);  // 0x803BB754 (40B)
    /* ? */ GetArchValue(void);  // 0x803BB77C (44B)
    void SetArchValue(int);  // 0x803BB7A8 (112B)
    /* ? */ GetObjectsValue(void);  // 0x803BB818 (44B)
    void SetObjectsValue(int);  // 0x803BB844 (112B)
    /* ? */ GetProbe(void);  // 0x803BB8B4 (44B)
    void SetProbe(SimLoopProbe *);  // 0x803BB8E0 (40B)
    /* ? */ GetPassiveInfluenceSystem(void);  // 0x803BB908 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DoCommand, DoStream, GetTodaysExpenses, ...)
    u32 m_todaysExpenses_004;  // 0x004 [R] (GetTodaysExpenses, SimulateOneTick)
    u32 m_todaysExpenses_008;  // 0x008 [R] (GetTodaysExpenses, SimulateOneTick)
    u32 m_todaysExpenses_00C;  // 0x00C [R] (GetTodaysExpenses, SimulateOneTick)
    u32 m_todaysExpenses_010;  // 0x010 [R/W] (GetTodaysExpenses, SimulateOneTick, cSimulatorImpl, ...)
    s16 m_todaysExpenses_014;  // 0x014 [R/W] (ComputeTimeOfDay, GetTodaysExpenses, Init, ...)
    s16 m_field_016;  // 0x016 [R/W] (Init, SimulateOneTick)
    u16 m_field_018;  // 0x018 [R/W] (DoCommand, TickAllObjects)
    u16 m_field_01A;  // 0x01A [W] (DoCommand)
    s16 m_currentHour;  // 0x01C [R/W] (HourTimeOfDayLastChanged, HourTimeOfDayNextChanges, Init, ...)
    u16 m_currentHour_01E;  // 0x01E [R/W] (Init, SetCurrentHour, SimulateOneTick)
    u16 m_field_020;  // 0x020 [R/W] (SimulateOneTick)
    s16 m_field_022;  // 0x022 [R/W] (DoStream, Init, SimulateOneTick)
    s16 m_field_024;  // 0x024 [R/W] (DoStream, Init, SimulateOneTick)
    u8 _pad_026[2];  // 0x026
    s16 m_field_028;  // 0x028 [R] (TickAllObjects)
    s16 m_field_02A;  // 0x02A [R/W] (Simulate)
    u16 m_field_02C;  // 0x02C [W] (DoStream, Init)
    u16 m_funds;  // 0x02E [W] (SetFunds)
    u16 m_funds_030;  // 0x030 [W] (SetFunds)
    u16 m_field_032;  // 0x032 [W] (DoStream, Init)
    s16 m_speed;  // 0x034 [R/W] (DoStream, Init, SetSpeed, ...)
    s16 m_field_036;  // 0x036 [R/W] (DoStream, Init, Pause, ...)
    s16 m_field_038;  // 0x038 [R/W] (DoStream, Init)
    u16 m_field_03A;  // 0x03A [W] (cSimulatorImpl)
    u16 m_field_03C;  // 0x03C [W] (Init)
    u8 _pad_03E[8];  // 0x03E
    s16 m_field_046;  // 0x046 [R/W] (DoStream)
    u8 _pad_048[4];  // 0x048
    u16 m_field_04C;  // 0x04C [R/W] (ClearHistory, SimulateOneTick)
    u16 m_field_04E;  // 0x04E [W] (DoStream, SimulateOneTick)
    u16 m_field_050;  // 0x050 [W] (DoStream)
    u8 _pad_052[2];  // 0x052
    u16 m_field_054;  // 0x054 [W] (DoCommand)
    u16 m_field_056;  // 0x056 [W] (DoStream)
    u16 m_field_058;  // 0x058 [W] (DoStream)
    u16 m_field_05A;  // 0x05A [W] (DoStream)
    u16 m_field_05C;  // 0x05C [W] (DoStream)
    s16 m_field_05E;  // 0x05E [R/W] (Simulate)
    u8 _pad_060[2];  // 0x060
    s16 m_field_062;  // 0x062 [R/W] (DoStream, Init)
    u8 _pad_064[4];  // 0x064
    u16 m_field_068;  // 0x068 [W] (DoStream, Init)
    u8 _pad_06A[6];  // 0x06A
    u16 m_global;  // 0x070 [W] (GetGlobal)
    u16 m_global_072;  // 0x072 [W] (GetGlobal)
    u32 m_funds_074;  // 0x074 [R/W] (DoStream, Init, SetFunds, ...)
    u32 m_funds_078;  // 0x078 [R/W] (Init, SetFunds, Spend)
    u32 m_field_07C;  // 0x07C [R/W] (DoStream, Init, SimulateOneTick, ...)
    u32 m_field_080;  // 0x080 [R/W] (SimulateOneTick, cSimulatorImpl)
    u32 m_field_084;  // 0x084 [W] (Init, cSimulatorImpl)
    u32 m_field_088;  // 0x088 [R/W] (DoStream, Init, cSimulatorImpl)
    u32 m_field_08C;  // 0x08C [R/W] (DoStream, Init, cSimulatorImpl)
    u32 m_field_090;  // 0x090 [R/W] (Init, SimulateOneTick)
    u32 m_field_094;  // 0x094 [W] (cSimulatorImpl)
    u32 m_field_098;  // 0x098 [W] (DoStream, cSimulatorImpl)
    u32 m_field_09C;  // 0x09C [W] (Init, Simulate)
    f32 m_speed_0A0;  // 0x0A0 [R/W] (Resume, SetSpeed, Simulate, ...)
    f32 m_field_0A4;  // 0x0A4 [W] (Simulate, cSimulatorImpl)
    f32 m_field_0A8;  // 0x0A8 [W] (DoStream, Pause, TickAllObjects, ...)
    f32 m_field_0AC;  // 0x0AC [R/W] (DoStream, Simulate, cSimulatorImpl)
    f32 m_field_0B0;  // 0x0B0 [R/W] (DoStream, Simulate, cSimulatorImpl)
    u8 _pad_0B4[0xC0];  // 0x0B4
    u32 m_field_174;  // 0x174 [R/W] (DoStream, Init, cSimulatorImpl, ...)
    u32 m_field_178;  // 0x178 [R/W] (DoCommand, DoStream, Init, ...)
    s16 m_field_17A;  // 0x17A [R] (DoStream)
    u32 m_field_17C;  // 0x17C [W] (Simulate, cSimulatorImpl)
};

#endif // CSIMULATORIMPL_H
