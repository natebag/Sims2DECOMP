#ifndef CTRACK_H
#define CTRACK_H

#include "types.h"

// cTrack - struct layout extracted from assembly analysis
// Estimated minimum size: 0x98 (152 bytes)
// 24 known fields (13 named), 66 methods

class cTrack {
public:
    // Constructors / Destructors
    cTrack(ERSoundEvent *)  // 0x80341BF4
    ~cTrack(void);  // 0x80341D94

    // Methods
    /* ? */ GetMinRange(void);  // 0x80345314 (164B)
    /* ? */ GetMaxRange(void);  // 0x803453B8 (164B)
    /* ? */ GetControlGroup(void);  // 0x8034545C (164B)
    bool IsPlaying(void);  // 0x8034CC30 (44B)
    /* ? */ GetArgsType(void);  // 0x80345500 (164B)
    void PlayPause(int, int, int, float);  // 0x80342460 (940B)
    void Unpause(void);  // 0x8034288C (160B)
    void SetVolume(int);  // 0x80344ECC (80B)
    void SetPan(int);  // 0x80344F1C (80B)
    void CalculateCurrentVolume(void);  // 0x80344F6C (832B)
    void Stop(void);  // 0x8034292C (208B)
    void HandleTrackFlowError(char *);  // 0x803405D0 (224B)
    void Kill(void);  // 0x803429FC (340B)
    void UpdateVolPan(void);  // 0x803452AC (104B)
    void HandleTimerCallback(void);  // 0x803420E0 (896B)
    void OnEndPlaying(void);  // 0x80341FD4 (220B)
    void OnStartPlaying(void);  // 0x80341E98 (316B)
    void SetRegister(int, int);  // 0x80342C94 (652B)
    void StartPos(void);  // 0x803420B0 (48B)
    void RegisterVal(int);  // 0x80342B50 (324B)
    void DoCommand(void);  // 0x8034309C (6972B)
    bool IsPaused(void);  // 0x8034CC5C (60B)
    void InstanceId(void);  // 0x8034CC04 (44B)
    void SetInstanceId(int);  // 0x8034CBD4 (48B)
    void SetPatch(SndEvtHitPatch *, float);  // 0x80344CEC (388B)
    void Pause(void);  // 0x8034280C (128B)
    void NoteOff(void);  // 0x80344E70 (92B)
    void SetCompareFlags(int, int);  // 0x80344BD8 (120B)
    /* ? */ GetVHitList(int);  // 0x80342F20 (380B)
    void NoteOn(void);  // 0x80344C50 (156B)
    void CheckedRegId(int);  // 0x8034CC98 (92B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CalculateCurrentVolume, DoCommand, HandleTrackFlowError, ...)
    u32 m_field_004;  // 0x004 [R/W] (CalculateCurrentVolume, DoCommand, PlayPause, ...)
    u32 m_field_008;  // 0x008 [W] (cTrack)
    u32 m_patch_00C;  // 0x00C [R/W] (NoteOn, SetPatch, cTrack)
    u32 m_field_010;  // 0x010 [R/W] (DoCommand, cTrack)
    u32 m_field_014;  // 0x014 [R/W] (Unpause, cTrack)
    u32 m_field_018;  // 0x018 [R/W] (DoCommand, HandleTimerCallback, Kill, ...)
    u8 _pad_01C[0x18];  // 0x01C
    u32 m_register;  // 0x034 [R/W] (HandleTimerCallback, Kill, Pause, ...)
    u32 m_field_038;  // 0x038 [R/W] (HandleTimerCallback, Pause, PlayPause, ...)
    u32 m_field_03C;  // 0x03C [R] (DoCommand)
    u32 m_field_040;  // 0x040 [R] (DoCommand)
    u32 m_field_044;  // 0x044 [R/W] (DoCommand)
    u32 m_field_048;  // 0x048 [R/W] (DoCommand, cTrack)
    f32 m_register_04C;  // 0x04C [R/W] (PlayPause, SetRegister, cTrack)
    u32 m_patch_050;  // 0x050 [R/W] (DoCommand, NoteOn, Pause, ...)
    u8 _pad_054[0x20];  // 0x054
    u32 m_register_074;  // 0x074 [R/W] (CalculateCurrentVolume, RegisterVal, SetRegister, ...)
    u32 m_register_078;  // 0x078 [R/W] (PlayPause, RegisterVal, SetRegister, ...)
    u32 m_register_07C;  // 0x07C [R/W] (PlayPause, RegisterVal, SetRegister, ...)
    u32 m_register_080;  // 0x080 [R/W] (HandleTimerCallback, Kill, PlayPause, ...)
    u32 m_register_084;  // 0x084 [R/W] (HandleTimerCallback, Kill, PlayPause, ...)
    u32 m_register_088;  // 0x088 [R/W] (HandleTimerCallback, Kill, PlayPause, ...)
    u32 m_register_08C;  // 0x08C [R/W] (HandleTimerCallback, Kill, PlayPause, ...)
    u32 m_register_090;  // 0x090 [R/W] (HandleTimerCallback, Kill, PlayPause, ...)
    u32 m_field_094;  // 0x094 [W] (cTrack, ~cTrack)
};

#endif // CTRACK_H
