#ifndef CASNPCEDITOR_H
#define CASNPCEDITOR_H

#include "types.h"

// CasNpcEditor - struct layout extracted from assembly analysis
// Estimated minimum size: 0x68 (104 bytes)
// 14 known fields (3 named), 38 methods

class CasNpcEditor {
public:
    // Constructors / Destructors
    CasNpcEditor(void)  // 0x8043B9E8
    ~CasNpcEditor(void);  // 0x8043BA94

    // Methods
    void Enable(CasNpcEditor::eNPCEditTypeFlag);  // 0x8043BB10 (484B)
    void Update(float);  // 0x8043BCF4 (1724B)
    bool IsLoadInProgress(void);  // 0x8044049C (64B)
    void LoadNextSim(void);  // 0x8043D59C (660B)
    /* ? */ GetNpcData(unsigned int, UserDataSaveLoad *);  // 0x8044024C (592B)
    void MakeDataset(UserDataSaveLoad);  // 0x8043E824 (68B)
    /* ? */ GetGrandparent(unsigned int);  // 0x804404DC (200B)
    /* ? */ GetCostume(unsigned int);  // 0x804405A4 (164B)
    void SaveAllNpcs(void);  // 0x8043E868 (2020B)
    void SaveAllGrandparents(void);  // 0x8043F58C (1832B)
    void SaveSim(void);  // 0x8043D830 (168B)
    void Draw(ERC *);  // 0x8043C3B0 (4588B)
    void SaveNpc(void);  // 0x8043D8D8 (3916B)
    void SaveGrandparent(void);  // 0x8043F04C (1344B)
    void SaveCostume(void);  // 0x8044011C (304B)
    void WriteCompositedTextures(CasSimDescriptionS2C *);  // 0x8043FD88 (916B)
    /* ? */ GetNPCCompositeTextureName(CasSimDescriptionS2C *, unsigned char);  // 0x8043FCB4 (212B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CasNpcEditor, Draw, Enable, ...)
    u32 m_field_004;  // 0x004 [R/W] (CasNpcEditor, LoadNextSim, SaveNpc, ...)
    u32 m_field_008;  // 0x008 [R/W] (CasNpcEditor, Draw, Enable, ...)
    u32 m_npcData;  // 0x00C [R/W] (CasNpcEditor, Draw, GetNpcData, ...)
    u32 m_field_010;  // 0x010 [R/W] (CasNpcEditor, Draw, Enable, ...)
    s16 m_field_012;  // 0x012 [R] (SaveNpc)
    f32 m_field_014;  // 0x014 [R/W] (CasNpcEditor, Draw, LoadNextSim, ...)
    u8 m_field_018;  // 0x018 [W] (CasNpcEditor)
    u8 _pad_019[0xF];  // 0x019
    u32 m_field_028;  // 0x028 [R] (SaveNpc)
    u8 _pad_02C[0xC];  // 0x02C
    u8 m_field_038;  // 0x038 [W] (CasNpcEditor)
    u8 _pad_039[0x1F];  // 0x039
    u32 m_grandparent_058;  // 0x058 [R/W] (CasNpcEditor, Enable, GetGrandparent, ...)
    u32 m_field_05C;  // 0x05C [R] (SaveAllGrandparents, SaveAllNpcs, SaveGrandparent, ...)
    u32 m_field_060;  // 0x060 [R] (SaveAllGrandparents, SaveAllNpcs, SaveGrandparent, ...)
    u32 m_field_064;  // 0x064 [R] (WriteCompositedTextures, ~CasNpcEditor)
};

#endif // CASNPCEDITOR_H
