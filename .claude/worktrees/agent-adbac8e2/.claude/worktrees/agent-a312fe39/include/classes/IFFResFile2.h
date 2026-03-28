#ifndef IFFRESFILE2_H
#define IFFRESFILE2_H

#include "types.h"

// IFFResFile2 - struct layout extracted from assembly analysis
// Estimated minimum size: 0x150 (336 bytes)
// 14 known fields (8 named), 92 methods

class IFFResFile2 {
public:
    // Constructors / Destructors
    IFFResFile2(void)  // 0x80251314
    ~IFFResFile2(void);  // 0x802513A8

    // Methods
    void ValidFile(void);  // 0x80252B38 (72B)
    void Close(void);  // 0x80252110 (1308B)
    void Open(StringBuffer &);  // 0x8025142C (1884B)
    /* ? */ GetBlockHeader(IFFHeader *, int);  // 0x8025570C (184B)
    void LoadNode(IFFResNode *, void (*);  // 0x80254D4C (1096B)
    void Create(StringBuffer &);  // 0x80251B88 (384B)
    void WriteHeader(MemFile *, int);  // 0x80251E58 (552B)
    void ClearMap(StringBuffer &);  // 0x80251D08 (336B)
    void InvalBlockHeader(int);  // 0x8025523C (184B)
    void Delete(StringBuffer &);  // 0x80252080 (144B)
    void Defrag(void);  // 0x80255CB4 (732B)
    void CloseForReopen(void);  // 0x8025262C (156B)
    void Reopen(void);  // 0x802526C8 (180B)
    void Update(void);  // 0x8025277C (816B)
    void Writable(void);  // 0x80252AAC (72B)
    /* ? */ GetFileName(StringBuffer &);  // 0x80252AF4 (68B)
    void CountTypes(void);  // 0x80252B80 (184B)
    /* ? */ GetIndType(short);  // 0x80252C38 (232B)
    void Count(int);  // 0x80252D20 (192B)
    /* ? */ GetByIDAndLanguage(int, short, char, void (*);  // 0x80252DE0 (388B)
    /* ? */ GetByID(int, short, void (*);  // 0x80252F64 (144B)
    /* ? */ GetByName(int, StringBuffer &, void (*);  // 0x80252FF4 (352B)
    /* ? */ GetByIndex(int, short, void (*);  // 0x80253154 (368B)
    /* ? */ GetName(Memory::HandleNode *, StringBuffer &);  // 0x802532C4 (252B)
    /* ? */ GetLanguage(Memory::HandleNode *);  // 0x802533C0 (268B)
    /* ? */ GetResType(Memory::HandleNode *);  // 0x802534CC (240B)
    /* ? */ GetID(Memory::HandleNode *, short *);  // 0x802535BC (240B)
    /* ? */ GetIndex(Memory::HandleNode *, short *);  // 0x802536AC (188B)
    void FindUniqueName(int, StringBuffer &);  // 0x80253768 (348B)
    void FindUniqueID(int);  // 0x802538C4 (212B)
    void Detach(Memory::HandleNode *);  // 0x80253998 (448B)
    void Load(Memory::HandleNode *);  // 0x80253B58 (172B)
    bool IsLittleEndian(Memory::HandleNode *);  // 0x80253C04 (276B)
    void SetID(Memory::HandleNode *, short);  // 0x80253D18 (284B)
    void AddWithLanguage(Memory::HandleNode *, int, short, StringBuffer &, char, bool);  // 0x80253E34 (764B)
    void LowLevelRemove(IFFResNode *);  // 0x80255194 (168B)
    void Add(Memory::HandleNode *, int, short, StringBuffer &, bool);  // 0x80254130 (148B)
    void Write(Memory::HandleNode *);  // 0x802541C4 (1828B)
    void NewBlockHeader(IFFHeader *, unsigned int, int *);  // 0x802552F4 (1048B)
    void SetBlockHeader(IFFHeader *, int);  // 0x802557C4 (244B)
    void Remove(Memory::HandleNode *);  // 0x802548E8 (364B)
    void SetInfo(Memory::HandleNode *, short, StringBuffer &, char);  // 0x80254A54 (760B)
    void MoveBlock(unsigned int, unsigned int, unsigned int, unsigned char *);  // 0x802558B8 (1020B)
    void SetOptimizeTarget(void);  // 0x802588DC (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddWithLanguage, Close, LoadNode, ...)
    u32 m_iD;  // 0x004 [R/W] (AddWithLanguage, Close, LoadNode, ...)
    u16 m_iD_006;  // 0x006 [R] (GetID)
    s16 m_language;  // 0x008 [R/W] (AddWithLanguage, GetLanguage, LoadNode, ...)
    u16 m_field_00A;  // 0x00A [W] (AddWithLanguage, Open)
    u32 m_index;  // 0x00C [R/W] (AddWithLanguage, ClearMap, Close, ...)
    u32 m_field_010;  // 0x010 [W] (Open)
    u8 _pad_014[0x120];  // 0x014
    u32 m_field_134;  // 0x134 [W] (IFFResFile2, ~IFFResFile2)
    u32 m_resType;  // 0x138 [R/W] (AddWithLanguage, Close, Count, ...)
    u32 m_field_13C;  // 0x13C [R/W] (Defrag, IFFResFile2, NewBlockHeader, ...)
    u32 m_blockHeader;  // 0x140 [R/W] (Close, IFFResFile2, NewBlockHeader, ...)
    u32 m_blockHeader_144;  // 0x144 [R/W] (Close, IFFResFile2, NewBlockHeader, ...)
    u32 m_field_148;  // 0x148 [R/W] (Close, IFFResFile2)
    u32 m_field_14C;  // 0x14C [R/W] (CloseForReopen, IFFResFile2, Reopen)
};

#endif // IFFRESFILE2_H
