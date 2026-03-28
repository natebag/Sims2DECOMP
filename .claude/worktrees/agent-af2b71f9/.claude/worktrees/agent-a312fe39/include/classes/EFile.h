#ifndef EFILE_H
#define EFILE_H

#include "types.h"

// EFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C (44 bytes)
// 8 known fields (5 named), 36 methods

class EFile {
public:
    // Constructors / Destructors
    EFile(void)  // 0x80748868
    ~EFile(void);  // 0x807488EC

    // Methods
    /* ? */ GetLength(void);  // 0x80749B40 (44B)
    void Allocate(unsigned int &);  // 0x807499E0 (44B)
    /* ? */ GetName(void);  // 0x80749AE8 (44B)
    void Fprintf(char *,...);  // 0x80748E84 (684B)
    void SetErrorSimulation(bool);  // 0x8074897C (44B)
    void SetName(char *);  // 0x80748D50 (308B)
    void ReadStructure(unsigned int);  // 0x80749130 (1224B)
    /* ? */ GetIOMode(void);  // 0x80749A0C (44B)
    /* ? */ GetAccessMode(void);  // 0x80749A38 (44B)
    /* ? */ GetDeviceType(void);  // 0x80749A64 (44B)
    /* ? */ GetDrive(void);  // 0x80749A90 (44B)
    /* ? */ GetPath(void);  // 0x80749ABC (44B)
    /* ? */ GetExt(void);  // 0x80749B14 (44B)
    void SetDevice(EFile::DeviceType);  // 0x80749B6C (40B)
    void SetAccess(EFile::AccessMode);  // 0x80749B94 (40B)
    void SetMode(EFile::IOMode);  // 0x80749BBC (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ReadStructure)
    u32 m_field_004;  // 0x004 [R/W] (ReadStructure)
    u8 _pad_008[0xE];  // 0x008
    u16 m_field_016;  // 0x016 [W] (ReadStructure)
    u8 _pad_018[3];  // 0x018
    u8 m_name;  // 0x01B [W] (SetName)
    u32 m_name_01C;  // 0x01C [R/W] (SetName, ~EFile)
    u32 m_name_020;  // 0x020 [R/W] (SetName, ~EFile)
    u8 _pad_024[3];  // 0x024
    u8 m_name_027;  // 0x027 [W] (SetName)
    u32 m_field_028;  // 0x028 [R/W] (Fprintf, ReadStructure, ~EFile)
};

#endif // EFILE_H
