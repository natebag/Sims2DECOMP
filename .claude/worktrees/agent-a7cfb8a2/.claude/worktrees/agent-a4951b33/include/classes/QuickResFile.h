#ifndef QUICKRESFILE_H
#define QUICKRESFILE_H

#include "types.h"

// QuickResFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 4 known fields (3 named), 74 methods

class QuickResFile {
public:
    // Constructors / Destructors
    QuickResFile(void)  // 0x80391D10
    ~QuickResFile(void);  // 0x80391D5C

    // Methods
    void Create(StringBuffer &);  // 0x80391DE4 (44B)
    void Delete(StringBuffer &);  // 0x80391E10 (44B)
    void Open(StringBuffer &);  // 0x80391E3C (120B)
    void CloseForReopen(void);  // 0x80391EB4 (40B)
    void Reopen(void);  // 0x80391EDC (40B)
    void Close(void);  // 0x80391F04 (40B)
    void Update(void);  // 0x80391F2C (32B)
    void Writable(void);  // 0x80391F4C (40B)
    /* ? */ GetFileName(StringBuffer &);  // 0x80391F74 (192B)
    void ValidFile(void);  // 0x80392034 (60B)
    void CountTypes(void);  // 0x80392070 (140B)
    /* ? */ GetIndType(short);  // 0x803920FC (152B)
    void Count(int);  // 0x80392194 (144B)
    /* ? */ GetByID(int, short, void (*);  // 0x80392224 (156B)
    /* ? */ GetByName(int, StringBuffer &, void (*);  // 0x803922C0 (152B)
    /* ? */ GetByIndex(int, short, void (*);  // 0x80392358 (156B)
    /* ? */ GetByIDAndLanguage(int, short, char, void (*);  // 0x803923F4 (164B)
    /* ? */ GetName(Memory::HandleNode *, StringBuffer &);  // 0x80392498 (148B)
    /* ? */ GetResType(Memory::HandleNode *);  // 0x8039252C (144B)
    /* ? */ GetID(Memory::HandleNode *, short *);  // 0x803925BC (152B)
    /* ? */ GetIndex(Memory::HandleNode *, short *);  // 0x80392654 (152B)
    /* ? */ GetLanguage(Memory::HandleNode *);  // 0x803926EC (144B)
    void FindUniqueName(int, StringBuffer &);  // 0x8039277C (148B)
    void FindUniqueID(int);  // 0x80392810 (144B)
    void Detach(Memory::HandleNode *);  // 0x803928A0 (136B)
    void Load(Memory::HandleNode *);  // 0x80392928 (136B)
    bool IsLittleEndian(Memory::HandleNode *);  // 0x803929B0 (144B)
    void SetID(Memory::HandleNode *, short);  // 0x80392A40 (148B)
    void Add(Memory::HandleNode *, int, short, StringBuffer &, bool);  // 0x80392AD4 (156B)
    void AddWithLanguage(Memory::HandleNode *, int, short, StringBuffer &, char, bool);  // 0x80392B70 (168B)
    void Write(Memory::HandleNode *);  // 0x80392C18 (136B)
    void Remove(Memory::HandleNode *);  // 0x80392CA0 (136B)
    void SetInfo(Memory::HandleNode *, short, StringBuffer &, char);  // 0x80392D28 (160B)
    /* ? */ GetString(StringBuffer &, short, short);  // 0x80392DC8 (280B)
    void _dyncastimpl(SCID);  // 0x80393060 (92B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_fileName;  // 0x000 [R] (GetFileName, GetString)
    u8 _pad_004[4];  // 0x004
    u32 m_fileName_008;  // 0x008 [R] (GetFileName, GetString)
    u32 m_field_00C;  // 0x00C [W] (~QuickResFile)
    u32 m_string;  // 0x010 [R] (GetString)
};

#endif // QUICKRESFILE_H
