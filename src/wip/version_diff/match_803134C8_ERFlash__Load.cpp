typedef unsigned int uint;

struct EFile;

struct EDataHeader {
    uint m_000;
    char m_004[12];
    uint m_010;
    uint m_014;
};

void EDataHeader_ctor(EDataHeader *hdr);
int EDataHeader_Read(EDataHeader *hdr, EFile *file, uint magic, uint ver1, uint ver2);
char *EDataHeader_GetName(EDataHeader *hdr);
void EDataHeader_dtor(EDataHeader *hdr, int flags);

struct FlashBigFile;
FlashBigFile *FlashBigFile_ctor(FlashBigFile *obj);
void FlashBigFile_LoadFiles(FlashBigFile *obj, EFile *file);

void ERFlash_Deallocate(void *obj);
void *__builtin_new(uint size);

struct ERFlash {
    char _pad[16];
    unsigned m_010_hi24: 24;
    unsigned m_010_lo8: 8;
    FlashBigFile *m_pFlashBigFile;

    void Load(EFile *file, uint);
};

void ERFlash::Load(EFile *file, uint)
{
    ERFlash_Deallocate(this);

    EDataHeader hdr;
    EDataHeader_ctor(&hdr);

    if (!EDataHeader_Read(&hdr, file, 0x464C5348, 3, 3)) {
        EDataHeader_dtor(&hdr, 2);
        return;
    }

    EDataHeader_GetName(&hdr);

    m_010_hi24 = hdr.m_010;

    FlashBigFile *flash = FlashBigFile_ctor((FlashBigFile *)__builtin_new(8));
    m_pFlashBigFile = flash;
    FlashBigFile_LoadFiles(flash, file);

    EDataHeader_dtor(&hdr, 2);
}
