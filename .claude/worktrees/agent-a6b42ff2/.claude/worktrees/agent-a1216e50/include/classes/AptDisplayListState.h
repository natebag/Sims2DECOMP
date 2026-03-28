#ifndef APTDISPLAYLISTSTATE_H
#define APTDISPLAYLISTSTATE_H

#include "types.h"

// AptDisplayListState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x64 (100 bytes)
// 22 known fields (1 named), 30 methods

class AptDisplayListState {
public:
    // Constructors / Destructors
    AptDisplayListState(void)  // 0x806E36BC
    ~AptDisplayListState(void);  // 0x806E37A8

    // Methods
    void insert(int, AptCIH *);  // 0x806DFF70 (236B)
    /* ? */ GetMovieclipInfo(AptMovieclipInformation *);  // 0x806E3650 (108B)
    void hasRenderData(void);  // 0x806E35D4 (124B)
    void findInst(int, EAStringC *, AptCIH **, AptCIH **);  // 0x806DF824 (596B)
    void RegisterReferences(AptValue *);  // 0x806DFB6C (132B)
    void remove(AptCIH *);  // 0x806E0198 (396B)
    void getLength(void);  // 0x806DFA78 (104B)
    void getValue(int);  // 0x806DFAE0 (140B)
    void insert(AptCIH *, AptCIH *);  // 0x806DFBF0 (344B)
    void insert(int, AptVirtualFunctionTable_Indices, AptCharacterInst *, AptCIH *, AptCIH *);  // 0x806DFD48 (264B)
    void insert(int, AptVirtualFunctionTable_Indices, AptCharacterInst *);  // 0x806DFE50 (288B)
    void insert(int, AptCIH *, AptCIH *, AptCIH *);  // 0x806E005C (212B)
    void remove(int);  // 0x806E0130 (104B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AptDisplayListState, GetMovieclipInfo, RegisterReferences, ...)
    u16 m_field_002;  // 0x002 [R] (findInst)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AptDisplayListState, insert)
    u8 _pad_00C[4];  // 0x00C
    f32 m_field_010;  // 0x010 [W] (AptDisplayListState, insert)
    f32 m_field_014;  // 0x014 [W] (AptDisplayListState, insert)
    f32 m_field_018;  // 0x018 [W] (AptDisplayListState, insert)
    f32 m_field_01C;  // 0x01C [W] (AptDisplayListState, insert)
    f32 m_field_020;  // 0x020 [W] (AptDisplayListState, insert)
    f32 m_field_024;  // 0x024 [W] (AptDisplayListState, insert)
    f32 m_field_028;  // 0x028 [W] (AptDisplayListState, insert)
    f32 m_field_02C;  // 0x02C [W] (AptDisplayListState, insert)
    f32 m_field_030;  // 0x030 [W] (AptDisplayListState, insert)
    f32 m_field_034;  // 0x034 [W] (AptDisplayListState, insert)
    f32 m_field_038;  // 0x038 [W] (AptDisplayListState, insert)
    f32 m_field_03C;  // 0x03C [W] (AptDisplayListState, insert)
    f32 m_field_040;  // 0x040 [W] (AptDisplayListState, insert)
    f32 m_field_044;  // 0x044 [W] (AptDisplayListState, insert)
    u32 m_field_048;  // 0x048 [W] (AptDisplayListState, insert)
    u32 m_field_04C;  // 0x04C [W] (AptDisplayListState, insert)
    u8 _pad_050[8];  // 0x050
    u32 m_field_058;  // 0x058 [R/W] (AptDisplayListState, insert)
    u16 m_field_05C;  // 0x05C [R/W] (AptDisplayListState, insert)
    u8 _pad_05E[2];  // 0x05E
    u32 m_field_060;  // 0x060 [W] (AptDisplayListState, insert)
};

#endif // APTDISPLAYLISTSTATE_H
