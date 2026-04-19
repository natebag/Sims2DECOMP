/* AptCharacterAnimationInst::getSwfVersion(void) at 0x80282FD0 (44B) */

struct AptFileData_GSV {
    char pad[8];
    unsigned char m_magic;
    char m_version;
};

struct AptFile_GSV {
    char pad[12];
    AptFileData_GSV* m_data;
};

struct AptCharacterAnimationInst_GSV {
    char pad[0x34];
    AptFile_GSV* m_file;
    int getSwfVersion();
};

int AptCharacterAnimationInst_GSV::getSwfVersion() {
    AptFileData_GSV* d = m_file->m_data;
    if (d->m_magic != 0x3a) return 6;
    return (signed char)d->m_version - 48;
}
