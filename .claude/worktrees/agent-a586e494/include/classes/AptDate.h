#ifndef APTDATE_H
#define APTDATE_H

#include "types.h"

// AptDate - struct layout extracted from assembly analysis
// Estimated minimum size: 0x68 (104 bytes)
// 21 known fields (1 named), 94 methods

class AptDate {
public:
    // Constructors / Destructors
    AptDate(int, int, int, int, int, int, int)  // 0x806DEC60
    ~AptDate(void);  // 0x806DEEAC

    // Methods
    void CleanNativeFunctions(void);  // 0x806DDD1C (3696B)
    void dateIsYearLeap(int);  // 0x806D9EC0 (192B)
    void dateGetNumDaysInYear(int);  // 0x806D9F80 (108B)
    void dateGetNumDaysInMonth(int, int);  // 0x806D9FEC (332B)
    void setDates(AptSysClock *, AptSysClock *, int);  // 0x806DA138 (596B)
    void getDayOfWeek(int, int, int);  // 0x806DA38C (1060B)
    void toString(EAStringC &);  // 0x806DA7B0 (760B)
    void sMethod_getDate(AptValue *, int);  // 0x806DAAA8 (84B)
    void sMethod_getDay(AptValue *, int);  // 0x806DAAFC (144B)
    void sMethod_getFullYear(AptValue *, int);  // 0x806DAB8C (84B)
    void sMethod_getHours(AptValue *, int);  // 0x806DABE0 (84B)
    void sMethod_getMilliseconds(AptValue *, int);  // 0x806DAC34 (84B)
    void sMethod_getMinutes(AptValue *, int);  // 0x806DAC88 (84B)
    void sMethod_getMonth(AptValue *, int);  // 0x806DACDC (84B)
    void sMethod_getSeconds(AptValue *, int);  // 0x806DAD30 (84B)
    void sMethod_getTime(AptValue *, int);  // 0x806DAD84 (72B)
    void sMethod_getTimezoneOffset(AptValue *, int);  // 0x806DADCC (104B)
    void sMethod_getUTCDate(AptValue *, int);  // 0x806DAE34 (84B)
    void sMethod_getUTCDay(AptValue *, int);  // 0x806DAE88 (144B)
    void sMethod_getUTCFullYear(AptValue *, int);  // 0x806DAF18 (84B)
    void sMethod_getUTCHours(AptValue *, int);  // 0x806DAF6C (84B)
    void sMethod_getUTCMilliseconds(AptValue *, int);  // 0x806DAFC0 (84B)
    void sMethod_getUTCMinutes(AptValue *, int);  // 0x806DB014 (84B)
    void sMethod_getUTCMonth(AptValue *, int);  // 0x806DB068 (84B)
    void sMethod_getUTCSeconds(AptValue *, int);  // 0x806DB0BC (84B)
    void sMethod_getYear(AptValue *, int);  // 0x806DB110 (92B)
    void sMethod_setDate(AptValue *, int);  // 0x806DB16C (224B)
    void sMethod_setFullYear(AptValue *, int);  // 0x806DB24C (352B)
    void sMethod_setHours(AptValue *, int);  // 0x806DB3AC (224B)
    void sMethod_setMilliseconds(AptValue *, int);  // 0x806DB48C (224B)
    void sMethod_setMinutes(AptValue *, int);  // 0x806DB56C (224B)
    void sMethod_setMonth(AptValue *, int);  // 0x806DB64C (224B)
    void sMethod_setSeconds(AptValue *, int);  // 0x806DB72C (224B)
    void sMethod_setTime(AptValue *, int);  // 0x806DB80C (72B)
    void sMethod_setUTCDate(AptValue *, int);  // 0x806DB854 (232B)
    void sMethod_setUTCFullYear(AptValue *, int);  // 0x806DB93C (360B)
    void sMethod_setUTCHours(AptValue *, int);  // 0x806DBAA4 (232B)
    void sMethod_setUTCMilliseconds(AptValue *, int);  // 0x806DBB8C (232B)
    void sMethod_setUTCMinutes(AptValue *, int);  // 0x806DBC74 (232B)
    void sMethod_setUTCMonth(AptValue *, int);  // 0x806DBD5C (232B)
    void sMethod_setUTCSeconds(AptValue *, int);  // 0x806DBE44 (232B)
    void sMethod_setYear(AptValue *, int);  // 0x806DBF2C (224B)
    void sMethod_toString(AptValue *, int);  // 0x806DC00C (160B)
    void sMethod_UTC(AptValue *, int);  // 0x806DC0AC (48B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806DC0DC (7232B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (objectMemberLookup, sMethod_getDate, sMethod_getDay, ...)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup)
    u32 m_field_004;  // 0x004 [R] (objectMemberLookup)
    u32 m_field_008;  // 0x008 [W] (AptDate, objectMemberLookup, sMethod_getDate, ...)
    u32 m_field_00C;  // 0x00C [R/W] (sMethod_getDate, sMethod_getDay, sMethod_getFullYear, ...)
    u8 _pad_010[0x10];  // 0x010
    u8 m_field_020;  // 0x020 [R/W] (AptDate, objectMemberLookup)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R/W] (AptDate, objectMemberLookup, sMethod_getSeconds, ...)
    u32 m_field_028;  // 0x028 [R/W] (AptDate, sMethod_getMinutes, sMethod_setMinutes, ...)
    u32 m_field_02C;  // 0x02C [R/W] (AptDate, sMethod_getHours, sMethod_setHours, ...)
    u8 _pad_030[4];  // 0x030
    u32 m_field_034;  // 0x034 [R/W] (AptDate, sMethod_getDate, sMethod_getDay, ...)
    u32 m_field_038;  // 0x038 [R/W] (AptDate, sMethod_getDay, sMethod_getMonth, ...)
    u32 m_field_03C;  // 0x03C [R/W] (AptDate, sMethod_getDay, sMethod_getFullYear, ...)
    u32 m_field_040;  // 0x040 [R/W] (AptDate, sMethod_getMilliseconds, sMethod_setMilliseconds)
    u32 m_field_044;  // 0x044 [R/W] (sMethod_getUTCSeconds, sMethod_setUTCSeconds)
    u32 m_field_048;  // 0x048 [R/W] (sMethod_getUTCMinutes, sMethod_setUTCMinutes)
    u32 m_field_04C;  // 0x04C [R/W] (AptDate, sMethod_getUTCHours, sMethod_setUTCHours)
    u8 _pad_050[4];  // 0x050
    u32 m_field_054;  // 0x054 [R/W] (AptDate, sMethod_getUTCDate, sMethod_getUTCDay, ...)
    u32 m_field_058;  // 0x058 [R/W] (sMethod_getUTCDay, sMethod_getUTCMonth, sMethod_setUTCFullYear, ...)
    u32 m_field_05C;  // 0x05C [R/W] (sMethod_getUTCDay, sMethod_getUTCFullYear, sMethod_setUTCFullYear)
    u32 m_field_060;  // 0x060 [R/W] (sMethod_getUTCMilliseconds, sMethod_setUTCMilliseconds)
    u32 m_field_064;  // 0x064 [R/W] (AptDate, sMethod_getTimezoneOffset, sMethod_setDate, ...)
};

#endif // APTDATE_H
