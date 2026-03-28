#ifndef CHITMAN_H
#define CHITMAN_H

#include "types.h"

// cHitMan - struct layout extracted from assembly analysis
// Estimated minimum size: 0x54 (84 bytes)
// 14 known fields (1 named), 46 methods

class cHitMan {
public:
    // Constructors / Destructors
    cHitMan(void)  // 0x80340D00
    ~cHitMan(void);  // 0x80340F08

    // Methods
    /* ? */ GetSoundCache(void);  // 0x80224DBC (44B)
    void NumActiveTracks(void);  // 0x80224D74 (72B)
    void ActiveTrackList(void);  // 0x80224D48 (44B)
    void Init(void);  // 0x80340DFC (268B)
    void RegisterSourceDataRequestHandler(bool (*);  // 0x803406B0 (164B)
    void Shutdown(void);  // 0x80340FBC (352B)
    void TimerCallback(void);  // 0x8034156C (416B)
    void ControlGroup(int);  // 0x80340824 (524B)
    void DuckMapRemoveAll(void);  // 0x80341B0C (232B)
    /* ? */ GetSourceDataField(int, int, int *);  // 0x80340754 (208B)
    void ClearControlGroups(void);  // 0x80340A30 (248B)
    void SetSequenceGroupTrackId(int, ERSoundEvent *);  // 0x80341278 (284B)
    void StopCallbackTimer(void);  // 0x80341544 (40B)
    void UpdateActiveTrackVolumes(void);  // 0x8034111C (348B)
    void SequenceGroupTrackId(int);  // 0x80341394 (292B)
    void StartCallbackTimer(void);  // 0x803414B8 (140B)
    void AddToUpdateList(cTrack *);  // 0x8034170C (88B)
    void RemoveFromUpdateList(cTrack *);  // 0x80341764 (388B)
    void DuckMapSetSndobPri(cTrack *, int);  // 0x803418E8 (156B)
    void DuckMapMaxPri(void);  // 0x80341A30 (220B)
    void DuckMapSndobPri(cTrack *);  // 0x80341984 (172B)
    void Timer(void);  // 0x8034CAD0 (44B)
    void Random(int, int);  // 0x8034CAFC (84B)
    void GZSndSys(void);  // 0x8034CA08 (156B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddToUpdateList, Init, RemoveFromUpdateList, ...)
    u32 m_field_004;  // 0x004 [R/W] (AddToUpdateList, ControlGroup, DuckMapMaxPri, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddToUpdateList, ControlGroup, TimerCallback, ...)
    u32 m_field_00C;  // 0x00C [R/W] (RemoveFromUpdateList, TimerCallback)
    u32 m_field_010;  // 0x010 [R/W] (ControlGroup, Init, TimerCallback)
    u32 m_field_014;  // 0x014 [R] (ControlGroup, Shutdown)
    u32 m_field_018;  // 0x018 [W] (cHitMan)
    u32 m_field_01C;  // 0x01C [R/W] (Init, TimerCallback, cHitMan)
    u32 m_field_020;  // 0x020 [R/W] (ClearControlGroups)
    u8 _pad_024[4];  // 0x024
    u32 m_field_028;  // 0x028 [R/W] (ClearControlGroups)
    u8 m_field_02C;  // 0x02C [R/W] (ClearControlGroups)
    u8 _pad_02D[3];  // 0x02D
    u32 m_field_030;  // 0x030 [W] (cHitMan)
    u8 _pad_034[8];  // 0x034
    u32 m_field_03C;  // 0x03C [R/W] (Init, TimerCallback, cHitMan)
    u8 _pad_040[0x10];  // 0x040
    u32 m_field_050;  // 0x050 [R/W] (Shutdown, cHitMan, ~cHitMan)
};

#endif // CHITMAN_H
