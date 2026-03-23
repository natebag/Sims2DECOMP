#ifndef CASSIMRENDERERDYNAMIC_H
#define CASSIMRENDERERDYNAMIC_H

#include "types.h"

// CasSimRendererDynamic - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1E28 (7720 bytes)
// 27 known fields (8 named), 44 methods

class CasSimRendererDynamic {
public:
    // Constructors / Destructors
    CasSimRendererDynamic(void)  // 0x80465F44
    ~CasSimRendererDynamic(void);  // 0x80465FE0

    // Methods
    /* ? */ GetIndexes(eBodyPartS2C, unsigned char *, unsigned char *);  // 0x80466100 (728B)
    /* ? */ GetIndexes(eTattooTextureTypeS2C, unsigned char *, unsigned char *);  // 0x804663D8 (728B)
    void SetupSim(void);  // 0x8046602C (212B)
    void Update(float);  // 0x804666B0 (1028B)
    void SelectNextStandingAnimation(void);  // 0x80466F34 (1416B)
    bool IsPersonalityAnim(unsigned int);  // 0x80466AB4 (296B)
    bool IsShirtIdleAnim(unsigned int);  // 0x80466BDC (152B)
    bool IsShoeIdleAnim(unsigned int);  // 0x80466C74 (104B)
    bool IsPantIdleAnim(unsigned int);  // 0x80466CDC (128B)
    bool IsRegularIdleAnim(unsigned int);  // 0x80466D5C (124B)
    void SetNextRandomShirtIdle(void);  // 0x80466DD8 (176B)
    void SetNextRandomRegularIdle(void);  // 0x80466E88 (172B)
    void PlayPersonalityAnim(short);  // 0x804674BC (436B)
    void DrawDebugInfo(ERC *);  // 0x80467670 (10876B)
    void HandleEventChangeSim(CasEventChangeSimS2C &);  // 0x8046A0EC (3180B)
    void HandleEventMorphSim(CasEventMorphSimS2C &);  // 0x8046AD58 (2280B)
    void HandleEventResetSimDraw(CasEventResetSimDraw &);  // 0x8046B640 (304B)
    void HandleEventInitSim(CasEventInitSim &);  // 0x8046B770 (272B)
    void HandleEventChangeFocus(CasEventChangeFocus &);  // 0x8046B880 (460B)
    void LockSimRotation(bool);  // 0x8046F6D0 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_indexes;  // 0x000 [R] (DrawDebugInfo, GetIndexes, HandleEventChangeSim, ...)
    f32 m_debugInfo;  // 0x004 [W] (CasSimRendererDynamic, DrawDebugInfo)
    u8 _pad_008[0x20];  // 0x008
    u32 m_field_028;  // 0x028 [R] (Update)
    u8 _pad_02C[0x58];  // 0x02C
    u32 m_indexes_084;  // 0x084 [R] (GetIndexes)
    u8 m_field_088;  // 0x088 [R] (HandleEventChangeSim)
    u8 m_field_089;  // 0x089 [R] (HandleEventChangeSim)
    u8 _pad_08A[2];  // 0x08A
    u8 m_field_08C;  // 0x08C [R] (HandleEventChangeSim)
    u8 _pad_08D[0x6B];  // 0x08D
    f32 m_field_0F8;  // 0x0F8 [R] (HandleEventChangeSim)
    f32 m_field_0FC;  // 0x0FC [R] (HandleEventChangeSim)
    f32 m_field_100;  // 0x100 [R] (HandleEventChangeSim)
    u8 _pad_104[0x1C];  // 0x104
    u32 m_field_120;  // 0x120 [R] (HandleEventMorphSim)
    u8 _pad_124[0x14];  // 0x124
    u32 m_indexes_138;  // 0x138 [R] (GetIndexes)
    u8 _pad_13C[8];  // 0x13C
    u32 m_upSim;  // 0x144 [R] (SetupSim)
    u8 _pad_148[0xC4];  // 0x148
    f32 m_field_20C;  // 0x20C [R/W] (HandleEventChangeFocus, Update)
    u8 _pad_210[4];  // 0x210
    u32 m_field_214;  // 0x214 [R/W] (CasSimRendererDynamic, Update)
    u32 m_field_218;  // 0x218 [R/W] (CasSimRendererDynamic, HandleEventChangeFocus, HandleEventInitSim, ...)
    u32 m_field_21C;  // 0x21C [R/W] (CasSimRendererDynamic, Update)
    u32 m_field_220;  // 0x220 [R/W] (CasSimRendererDynamic, HandleEventChangeFocus, SelectNextStandingAnimation)
    u32 m_bIsPersonalityAnim;  // 0x224 [R/W] (CasSimRendererDynamic, HandleEventChangeFocus, HandleEventInitSim, ...)
    u32 m_field_228;  // 0x228 [R/W] (CasSimRendererDynamic, HandleEventChangeSim, SelectNextStandingAnimation)
    u32 m_field_22C;  // 0x22C [R/W] (CasSimRendererDynamic, HandleEventChangeSim, SelectNextStandingAnimation)
    u32 m_field_230;  // 0x230 [R/W] (CasSimRendererDynamic, HandleEventChangeSim, SelectNextStandingAnimation)
    u32 m_field_234;  // 0x234 [R/W] (CasSimRendererDynamic, PlayPersonalityAnim, SelectNextStandingAnimation)
    u32 m_field_238;  // 0x238 [R/W] (PlayPersonalityAnim, SelectNextStandingAnimation)
    u32 m_field_23C;  // 0x23C [R/W] (HandleEventChangeFocus)
    u8 _pad_240[0x1BCC];  // 0x240
    f32 m_debugInfo_1E0C;  // 0x1E0C [R] (DrawDebugInfo)
    u8 _pad_1E10[0x14];  // 0x1E10
    f32 m_debugInfo_1E24;  // 0x1E24 [R] (DrawDebugInfo)
};

#endif // CASSIMRENDERERDYNAMIC_H
