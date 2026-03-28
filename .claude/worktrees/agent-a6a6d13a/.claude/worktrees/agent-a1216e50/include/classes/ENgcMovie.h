#ifndef ENGCMOVIE_H
#define ENGCMOVIE_H

#include "types.h"

// ENgcMovie - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA5 (165 bytes)
// 14 known fields (7 named), 50 methods

class ENgcMovie {
public:
    // Constructors / Destructors
    ENgcMovie(void)  // 0x808AFAF0
    ~ENgcMovie(void);  // 0x808AFBEC

    // Methods
    void PlayerInit(int);  // 0x808B016C (408B)
    void PlayerQuit(void);  // 0x808B0304 (128B)
    void Load(EFile *, unsigned int, unsigned int, unsigned int);  // 0x808AFC50 (444B)
    void PlayerOpen(unsigned int, bool);  // 0x808B0384 (1132B)
    void PlayerGetVideoInfo(THPVideoInfo *);  // 0x808B1750 (108B)
    void PlayerGetAudioInfo(THPAudioInfo *);  // 0x808B17BC (108B)
    void PlayerCreateBuffers(EAllocGroup &);  // 0x808B0880 (924B)
    void PlayerPrepare(int, int, int);  // 0x808B0C1C (1036B)
    void Start(int, int);  // 0x808AFE0C (264B)
    void PlayerPlay(void);  // 0x808B1028 (204B)
    void Stop(void);  // 0x808AFF14 (76B)
    void PlayerStop(void);  // 0x808B10F4 (328B)
    void PlayerClose(void);  // 0x808B07F0 (144B)
    void Reset(void);  // 0x808AFF60 (32B)
    bool IsFinished(void);  // 0x808AFF80 (124B)
    void PlayerGetState(void);  // 0x808B18CC (56B)
    /* ? */ GetNextFrame(void);  // 0x808AFFFC (368B)
    void PlayerPause(void);  // 0x808B123C (132B)
    void PlayerDrawCurrentFrame(_GXRenderModeObj *, unsigned int, unsigned int, unsigned int, unsigned int);  // 0x808B15E4 (364B)
    void PlayerDrawDone(void);  // 0x808B1904 (116B)
    void PlayerSkip(void);  // 0x808B12C0 (804B)
    void PlayerGetFrameRate(void);  // 0x808B1828 (84B)
    void PlayerGetTotalFrame(void);  // 0x808B187C (80B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (PlayerOpen, Start)
    u32 m_field_004;  // 0x004 [W] (PlayerOpen, Start)
    u32 m_field_008;  // 0x008 [W] (ENgcMovie, PlayerOpen, ~ENgcMovie)
    u32 m_field_00C;  // 0x00C [W] (Load, PlayerOpen)
    u32 m_nextFrame;  // 0x010 [W] (GetNextFrame, PlayerOpen)
    u32 m_field_014;  // 0x014 [W] (PlayerOpen)
    u32 m_nextFrame_018;  // 0x018 [R/W] (GetNextFrame, Load, Start)
    u32 m_nextFrame_01C;  // 0x01C [R/W] (GetNextFrame, Load, Start)
    u32 m_field_020;  // 0x020 [R/W] (ENgcMovie, PlayerDrawDone, PlayerInit, ...)
    u32 m_nextFrame_024;  // 0x024 [R/W] (GetNextFrame, Load, Start)
    u32 m_nextFrame_028;  // 0x028 [R] (GetNextFrame, Load, Start)
    u32 m_nextFrame_02C;  // 0x02C [R] (GetNextFrame, Load, Start)
    u8 _pad_030[0x70];  // 0x030
    u32 m_field_0A0;  // 0x0A0 [R/W] (PlayerClose)
    u8 m_field_0A4;  // 0x0A4 [R] (PlayerClose)
};

#endif // ENGCMOVIE_H
