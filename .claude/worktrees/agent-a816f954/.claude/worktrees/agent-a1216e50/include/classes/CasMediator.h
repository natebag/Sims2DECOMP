#ifndef CASMEDIATOR_H
#define CASMEDIATOR_H

#include "types.h"

// CasMediator - struct layout extracted from assembly analysis
// Estimated minimum size: 0xAB0 (2736 bytes)
// 14 known fields (5 named), 51 methods

class CasMediator {
public:
    // Constructors / Destructors
    CasMediator(void)  // 0x80435D30
    ~CasMediator(void);  // 0x80435DB8

    // Methods
    void SetSimState(CasSimState &);  // 0x80413B18 (40B)
    void SetSimRenderer(CasSimRendererDynamic &);  // 0x80413B68 (40B)
    void ClearSimRenderer(void);  // 0x80413B90 (40B)
    void ClearSimState(void);  // 0x80413B40 (40B)
    void AddListener(CasListener &);  // 0x80435E1C (140B)
    /* ? */ GetNumListeners(void);  // 0x80436008 (68B)
    void PostEvent(CasEvent &);  // 0x8043604C (296B)
    void RemoveListener(CasListener &);  // 0x80435EA8 (132B)
    /* ? */ GetEditSimDescription(void);  // 0x80436174 (88B)
    void RemoveAllListeners(void);  // 0x80435F2C (220B)
    /* ? */ GetNumBodyModels(eBodyPartS2C);  // 0x804361CC (96B)
    /* ? */ GetNumTattooTextures(eTattooTextureTypeS2C);  // 0x8043622C (96B)
    /* ? */ GetIconTextureId(eBodyPartS2C, unsigned int);  // 0x8043628C (104B)
    /* ? */ GetIconTattooTextureId(eTattooTextureTypeS2C, unsigned int);  // 0x804362F4 (104B)
    /* ? */ GetIndexes(eBodyPartS2C, unsigned char *, unsigned char *);  // 0x8043635C (112B)
    /* ? */ GetIndexes(eTattooTextureTypeS2C, unsigned char *, unsigned char *);  // 0x804363CC (112B)
    void DrawSim(ERC *);  // 0x8043643C (120B)
    void SetCasMode(int);  // 0x804364B4 (76B)
    bool IsTransitionComplete(void);  // 0x80436500 (120B)
    void SetControllerFilterId(unsigned int, unsigned int);  // 0x80436578 (212B)
    /* ? */ GetControllerFilterId(unsigned int);  // 0x8043664C (216B)
    /* ? */ GetNavTarget(void);  // 0x8044315C (44B)
    /* ? */ GetSimRenderer(void);  // 0x80443130 (44B)
    /* ? */ GetPlayerNumber(void);  // 0x80449DC8 (44B)
    /* ? */ GetScene(void);  // 0x80465988 (44B)
    /* ? */ GetCasMode(void);  // 0x804DEC9C (44B)
    void SetPlayerNumber(int);  // 0x804DECC8 (40B)
    void SetScene(CasScene &);  // 0x804DEBF4 (40B)
    void SetNavTarget(CASTarget &);  // 0x804DEC48 (40B)
    /* ? */ GetSimState(void);  // 0x804DEB74 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (CasMediator)
    u32 m_field_004;  // 0x004 [R/W] (CasMediator, PostEvent, RemoveAllListeners, ...)
    u32 m_field_008;  // 0x008 [R/W] (CasMediator, RemoveAllListeners, RemoveListener, ...)
    u8 m_field_00C;  // 0x00C [W] (CasMediator)
    u8 _pad_00D[3];  // 0x00D
    u32 m_field_010;  // 0x010 [W] (CasMediator)
    u32 m_bIsTransitionComplete;  // 0x014 [R/W] (CasMediator, IsTransitionComplete)
    u32 m_bIsTransitionComplete_018;  // 0x018 [R/W] (CasMediator, IsTransitionComplete)
    u32 m_field_01C;  // 0x01C [W] (CasMediator)
    u32 m_field_020;  // 0x020 [W] (CasMediator)
    u32 m_field_024;  // 0x024 [W] (CasMediator)
    u32 m_field_028;  // 0x028 [W] (CasMediator)
    u32 m_field_02C;  // 0x02C [W] (CasMediator)
    u8 _pad_030[0xA78];  // 0x030
    f32 m_bIsTransitionComplete_AA8;  // 0xAA8 [R] (IsTransitionComplete)
    f32 m_bIsTransitionComplete_AAC;  // 0xAAC [R] (IsTransitionComplete)
};

#endif // CASMEDIATOR_H
