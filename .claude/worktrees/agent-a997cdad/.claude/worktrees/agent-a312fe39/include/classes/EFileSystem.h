#ifndef EFILESYSTEM_H
#define EFILESYSTEM_H

#include "types.h"

// EFileSystem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 12 known fields (1 named), 40 methods

class EFileSystem {
public:
    // Constructors / Destructors
    EFileSystem(void)  // 0x80749C84
    ~EFileSystem(void);  // 0x80749D00

    // Methods
    void Create(EFile *&, char *, char *, EFile::DeviceType, EFile::AccessMode, unsigned int);  // 0x8074A8D4 (544B)
    void Destroy(EFile *&);  // 0x8074AAF4 (124B)
    void ManagedShutdown(void);  // 0x80749D64 (60B)
    void FindCreator(EFile::DeviceType, EFile::IOMode, EFile::AccessMode, char *);  // 0x8074A4DC (440B)
    void Access(char *, char *, EFile::DeviceType, EFile::AccessMode);  // 0x8074A694 (576B)
    void ParseMode(char *, EFile::IOMode &);  // 0x8074B23C (240B)
    void Init(EFile::DeviceType);  // 0x8074AB70 (204B)
    void InitHDDFileSystem(void);  // 0x8074AC3C (40B)
    void InitHDD(bool, char *);  // 0x8074AC64 (48B)
    void HDDInitialized(void);  // 0x8074AC94 (56B)
    void HDDStatus(void);  // 0x8074ACCC (44B)
    void HDDTmpInitialized(void);  // 0x8074ACF8 (56B)
    void HDDTmpStatus(void);  // 0x8074AD30 (44B)
    void HDDSaveInitialized(void);  // 0x8074AD5C (56B)
    void HDDSaveStatus(void);  // 0x8074AD94 (44B)
    void HDDIsUnformatted(void);  // 0x8074ADC0 (40B)
    /* ? */ GetDefaultType(void);  // 0x8074ADE8 (44B)
    void RegisterFileCreator(EFile::DeviceType, EFile::IOMode, EFile::AccessMode, char *, EFile *(*);  // 0x8074AE14 (1064B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Access, Create, EFileSystem, ...)
    u32 m_field_004;  // 0x004 [R/W] (FileCreator::FileCreator, FileCreator::GetScore, FileCreator::operator==, ...)
    u32 m_field_008;  // 0x008 [R/W] (FileCreator::FileCreator, FileCreator::GetScore, FileCreator::operator==, ...)
    u32 m_field_00C;  // 0x00C [R/W] (FileCreator::FileCreator, FileCreator::GetScore, FileCreator::operator==)
    u8 m_field_010;  // 0x010 [R/W] (Access, Create, FileCreator::FileCreator, ...)
    u8 m_field_011;  // 0x011 [W] (FileCreator::FileCreator)
    u8 m_field_012;  // 0x012 [W] (FileCreator::FileCreator)
    u8 m_field_013;  // 0x013 [W] (FileCreator::FileCreator)
    u32 m_field_014;  // 0x014 [R/W] (Access, Create, EFileSystem, ...)
    u32 m_field_018;  // 0x018 [W] (EFileSystem)
    u32 m_field_01C;  // 0x01C [W] (EFileSystem)
    u32 m_field_020;  // 0x020 [W] (EFileSystem)
};

#endif // EFILESYSTEM_H
