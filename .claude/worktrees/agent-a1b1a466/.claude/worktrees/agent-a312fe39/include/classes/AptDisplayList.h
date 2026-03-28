#ifndef APTDISPLAYLIST_H
#define APTDISPLAYLIST_H

#include "types.h"

// AptDisplayList - struct layout extracted from assembly analysis
// Estimated minimum size: 0x70 (112 bytes)
// 25 known fields (1 named), 50 methods

class AptDisplayList {
public:
    // Static members (from map file)
    // static ??? BASE_MOVIE_DEPTH;

    // Constructors / Destructors
    AptDisplayList(void)  // 0x806E1FBC
    ~AptDisplayList(void);  // 0x806E200C

    // Methods
    void tick(void);  // 0x806E2720 (156B)
    void render(AptRenderingContext *, AptMaskRenderOperation);  // 0x806E23EC (640B)
    void deallocAssetStringRecursive(void);  // 0x806E2368 (132B)
    void getState(void);  // 0x806E29D4 (44B)
    void placeObject(AptCIH *, int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptCXForm *, AptMatrix *, AptEventActionSet *, float, AptValue *);  // 0x806E12A4 (940B)
    void removeClonedObject(AptCIH *);  // 0x806E1F40 (124B)
    void clear(bool);  // 0x806E27BC (368B)
    void PreDestroy(void);  // 0x806E292C (168B)
    void _getBoundingRect(AptRenderingContext *, AptRect *);  // 0x806E266C (180B)
    void mergeState(AptPseudoDisplayList *, AptNativeHash *, bool);  // 0x806E2D78 (1544B)
    void instantiateCharacter(int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptCIH **, int *);  // 0x806E0324 (2572B)
    void removeObject(AptCIH *);  // 0x806E1D84 (280B)
    void placeObjectNCXForm(AptCIH *, int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptnCXForm *, AptMatrix *, AptEventActionSet *, float);  // 0x806E0F6C (288B)
    void _addToSetCaches(AptCIH *, int);  // 0x806E108C (536B)
    void placeObject(AptControlPlaceObject2 *, AptCIH *);  // 0x806E1650 (1480B)
    void placeObject(AptPseudoCIH_t *, AptCIH *);  // 0x806E1C18 (364B)
    void removeObject(int);  // 0x806E1E9C (96B)
    void removeObject(AptControlRemoveObject2 *);  // 0x806E1EFC (68B)
    void useState(AptDisplayListState *);  // 0x806E2A00 (44B)
    void RemoveFromDisplayList(AptNativeHash *, AptCIH *);  // 0x806E2A2C (68B)
    void AddToDisplayList(AptNativeHash *, AptPseudoCIH_t *, AptCIH *);  // 0x806E2A70 (384B)
    void ReplaceDisplyListItem(AptNativeHash *, AptCIH *, AptPseudoCIH_t *, AptCIH *);  // 0x806E2BF0 (392B)
    void validate(AptCIH *);  // 0x806E3380 (596B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (PreDestroy, _getBoundingRect, clear, ...)
    u16 m_field_002;  // 0x002 [R] (instantiateCharacter, placeObject, validate)
    u32 m_field_004;  // 0x004 [R/W] (clear, instantiateCharacter, placeObject)
    u32 m_field_008;  // 0x008 [R/W] (instantiateCharacter, placeObject)
    u32 m_field_00C;  // 0x00C [R/W] (AddToDisplayList, instantiateCharacter, placeObject)
    f32 m_field_010;  // 0x010 [R/W] (instantiateCharacter, placeObject)
    u32 m_field_014;  // 0x014 [W] (instantiateCharacter)
    u32 m_field_018;  // 0x018 [R/W] (instantiateCharacter)
    s16 m_field_01A;  // 0x01A [R] (placeObject)
    u32 m_field_01C;  // 0x01C [R/W] (instantiateCharacter)
    u8 _pad_020[4];  // 0x020
    u32 m_field_024;  // 0x024 [W] (instantiateCharacter)
    u8 _pad_028[4];  // 0x028
    f32 m_field_02C;  // 0x02C [R] (placeObject)
    u32 m_field_030;  // 0x030 [R] (placeObject)
    u32 m_field_034;  // 0x034 [R] (placeObject)
    u32 m_field_038;  // 0x038 [R] (placeObject)
    u32 m_field_03C;  // 0x03C [W] (instantiateCharacter)
    u8 _pad_040[8];  // 0x040
    u32 m_field_048;  // 0x048 [R/W] (instantiateCharacter)
    u32 m_field_04C;  // 0x04C [R/W] (AddToDisplayList, instantiateCharacter)
    f32 m_field_050;  // 0x050 [W] (instantiateCharacter)
    f32 m_field_054;  // 0x054 [W] (instantiateCharacter)
    f32 m_field_058;  // 0x058 [R/W] (instantiateCharacter, placeObject)
    f32 m_field_05C;  // 0x05C [W] (instantiateCharacter)
    f32 m_field_060;  // 0x060 [W] (instantiateCharacter)
    u32 m_field_064;  // 0x064 [W] (instantiateCharacter)
    u8 _pad_068[4];  // 0x068
    u32 m_field_06C;  // 0x06C [W] (instantiateCharacter)
};

#endif // APTDISPLAYLIST_H
