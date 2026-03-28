#ifndef CBOXX_H
#define CBOXX_H

#include "types.h"

// cBoxX - struct layout extracted from assembly analysis
// Estimated minimum size: 0x7C (124 bytes)
// 15 known fields (8 named), 70 methods

class cBoxX {
public:
    // Constructors / Destructors
    cBoxX(void)  // 0x802196F0
    ~cBoxX(void);  // 0x802197AC

    // Methods
    /* ? */ GetSurroundVol(AmbientScorePlayer *, EVec3 &, float, float, int &, int &, int &, int &);  // 0x80219F54 (1144B)
    void ConvertSurroundToVolPan(int, int, int, int, int &, int &);  // 0x8021B554 (1004B)
    void Init(void);  // 0x80219840 (560B)
    void LoadQdataTables(void);  // 0x80219A70 (32B)
    void Shutdown(void);  // 0x80219A90 (244B)
    void Update(unsigned int);  // 0x80219B84 (896B)
    /* ? */ GetListenerPosAndDir(ESimsCam *, EVec3 &, EVec3 &);  // 0x8021E2E4 (532B)
    void UpdateAllSndobVolPan(void);  // 0x8021D2E8 (692B)
    void UpdateGameMode(void);  // 0x80219F04 (80B)
    void CalculateSurroundVol(EVec3 &, EVec3 &, EVec3 &, float, float, int &, int &, int &, int &);  // 0x8021A8E4 (1236B)
    /* ? */ GetSurroundVol(EVec3 &, float, float, int &, int &, int &, int &, int);  // 0x8021A3CC (1304B)
    /* ? */ GetInstanceSurroundVol(int, cTrack *, int &, int &, int &, int &);  // 0x8021ADB8 (724B)
    /* ? */ GetInstanceVolNoPan(int, cTrack *, int &);  // 0x8021B08C (1224B)
    void MappedEvent(ERSoundEvent *, int, float);  // 0x8021B940 (208B)
    void Event(int, int, int, ERSoundEvent *, float);  // 0x8021BA10 (5184B)
    void KillSource(int);  // 0x8021D710 (364B)
    /* ? */ GetSndobSurroundVols(ERSoundEvent *, int &, int &, int &, int &);  // 0x8021DC54 (796B)
    void AddToInstanceMap(ERSoundEvent *, int);  // 0x8021D1B4 (308B)
    void Pause(void);  // 0x8021DF70 (72B)
    void Unpause(void);  // 0x8021DFB8 (72B)
    void PauseMusic(void);  // 0x8021E204 (100B)
    void UnpauseMusic(void);  // 0x8021E268 (124B)
    void PauseSFX(void);  // 0x8021E000 (156B)
    void UnpauseSFX(void);  // 0x8021E09C (168B)
    void PauseAmbient(void);  // 0x8021E144 (84B)
    void UnpauseAmbient(void);  // 0x8021E198 (108B)
    void SetAmbientScore(int);  // 0x8021CE50 (396B)
    void SetAmbientScoreVolume(int);  // 0x8021CFDC (84B)
    /* ? */ GetAmbientScoreVolume(void);  // 0x8021D030 (96B)
    void FindSndobInstancePair(ERSoundEvent *, int);  // 0x8021D090 (292B)
    void UpdateSndobVolPan(_Rb_tree_iterator<pair<ERSoundEvent *, int>, _Nonconst_traits<pair<ERSoundEvent *, int> > >, _Rb_tree_iterator<pair<ERSoundEvent *, int>, _Nonconst_traits<pair<ERSoundEvent *, int> > >);  // 0x8021D988 (716B)
    void CheckForTooManySounds(void);  // 0x8021D59C (372B)
    void UpdateSndobVolPan(ERSoundEvent *);  // 0x8021D87C (268B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_surroundVol;  // 0x000 [R/W] (CalculateSurroundVol, Event, FindSndobInstancePair, ...)
    f32 m_surroundVol_004;  // 0x004 [R/W] (CalculateSurroundVol, Event, GetInstanceSurroundVol, ...)
    f32 m_sndobSurroundVols;  // 0x008 [R/W] (CalculateSurroundVol, CheckForTooManySounds, GetInstanceSurroundVol, ...)
    u32 m_field_00C;  // 0x00C [W] (cBoxX)
    u32 m_field_010;  // 0x010 [R/W] (Event, Init, Shutdown, ...)
    u32 m_sndobSurroundVols_014;  // 0x014 [R/W] (Event, GetSndobSurroundVols, Init, ...)
    u32 m_field_018;  // 0x018 [W] (cBoxX)
    u8 _pad_01C[8];  // 0x01C
    u32 m_sndobSurroundVols_024;  // 0x024 [R] (GetSndobSurroundVols, UpdateSndobVolPan)
    u8 _pad_028[8];  // 0x028
    u32 m_ambientScore;  // 0x030 [R] (Event, SetAmbientScore)
    u8 _pad_034[0x30];  // 0x034
    u32 m_ambientScore_064;  // 0x064 [R/W] (Event, Init, SetAmbientScore, ...)
    u32 m_field_068;  // 0x068 [R/W] (Init, cBoxX, ~cBoxX)
    u32 m_field_06C;  // 0x06C [R/W] (Event, PauseSFX, UnpauseSFX, ...)
    u32 m_field_070;  // 0x070 [R/W] (Event, PauseMusic, UnpauseMusic, ...)
    u32 m_ambientScore_074;  // 0x074 [R/W] (SetAmbientScore, UnpauseAmbient, cBoxX)
    u32 m_field_078;  // 0x078 [W] (cBoxX, ~cBoxX)
};

#endif // CBOXX_H
