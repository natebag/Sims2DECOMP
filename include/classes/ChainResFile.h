#ifndef CHAINRESFILE_H
#define CHAINRESFILE_H

#include "types.h"

// ChainResFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 3 known fields (3 named), 80 methods

class ChainResFile {
public:
    // Constructors / Destructors
    ChainResFile(void)  // 0x80228A38
    ~ChainResFile(void);  // 0x80228AC8

    // Methods
    void AddFile(iResFile *);  // 0x80228B6C (368B)
    void RemoveFile(iResFile *);  // 0x80228CDC (280B)
    void CountFiles(void);  // 0x80228DF4 (136B)
    /* ? */ GetFile(short);  // 0x80228E7C (196B)
    void Close(void);  // 0x80228F40 (252B)
    void CloseForReopen(void);  // 0x8022903C (252B)
    void Reopen(void);  // 0x80229138 (252B)
    void Update(void);  // 0x80229234 (372B)
    void Writable(void);  // 0x802293A8 (232B)
    void ValidFile(void);  // 0x80229490 (232B)
    /* ? */ GetLanguage(Memory::HandleNode *);  // 0x80229578 (332B)
    void CountTypes(void);  // 0x802296C4 (156B)
    void BuildTypeVector(vector<int, allocator<int> > &);  // 0x80229760 (552B)
    /* ? */ GetIndType(short);  // 0x80229988 (292B)
    void Count(int);  // 0x80229AAC (328B)
    /* ? */ GetByIDAndLanguage(int, short, char, void (*);  // 0x80229BF4 (380B)
    /* ? */ GetByID(int, short, void (*);  // 0x80229D70 (144B)
    /* ? */ GetByName(int, StringBuffer &, void (*);  // 0x80229E00 (348B)
    /* ? */ GetByIndex(int, short, void (*);  // 0x80229F5C (576B)
    /* ? */ GetName(Memory::HandleNode *, StringBuffer &);  // 0x8022A19C (304B)
    /* ? */ GetResType(Memory::HandleNode *);  // 0x8022A2CC (324B)
    /* ? */ GetID(Memory::HandleNode *, short *);  // 0x8022A410 (304B)
    bool IsLittleEndian(Memory::HandleNode *);  // 0x8022A540 (296B)
    /* ? */ GetIndex(Memory::HandleNode *, short *);  // 0x8022A668 (304B)
    void FindUniqueName(int, StringBuffer &);  // 0x8022A798 (260B)
    void FindUniqueID(int);  // 0x8022A89C (236B)
    void Detach(Memory::HandleNode *);  // 0x8022A988 (296B)
    void Load(Memory::HandleNode *);  // 0x8022AAB0 (64B)
    void SetID(Memory::HandleNode *, short);  // 0x8022AAF0 (320B)
    void Add(Memory::HandleNode *, int, short, StringBuffer &, bool);  // 0x8022AC30 (148B)
    void AddWithLanguage(Memory::HandleNode *, int, short, StringBuffer &, char, bool);  // 0x8022ACC4 (980B)
    void Write(Memory::HandleNode *);  // 0x8022B098 (384B)
    void Remove(Memory::HandleNode *);  // 0x8022B218 (384B)
    void SetInfo(Memory::HandleNode *, short, StringBuffer &, char);  // 0x8022B398 (436B)
    void AddProhibitedType(iResFile *, unsigned int);  // 0x8022B54C (356B)
    void AddExclusiveType(iResFile *, unsigned int);  // 0x8022B6B0 (356B)
    void TypeWritable(unsigned int);  // 0x8022B814 (468B)
    void _dyncastimpl(SCID);  // 0x8022C68C (92B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_byIndex;  // 0x000 [R] (BuildTypeVector, Close, CloseForReopen, ...)
    u8 _pad_004[8];  // 0x004
    u32 m_byIndex_00C;  // 0x00C [R/W] (AddWithLanguage, BuildTypeVector, ChainResFile, ...)
    u32 m_file;  // 0x010 [R] (FindUniqueID, GetFile, TypeWritable)
};

#endif // CHAINRESFILE_H
