// 0x80313574 ERFlash::GetFlashBigData(void) (56 B)
// PRAGMA_STUB: ERFlash::GetFlashBigData(void)
void EResource_Detach(void *obj);

struct FlashBigFile;

struct ERFlash {
    char _pad[20];
    FlashBigFile *m_pFlashBigFile;

    FlashBigFile *GetFlashBigData(void);
};

FlashBigFile *ERFlash::GetFlashBigData(void)
{
    EResource_Detach(this);
    FlashBigFile *data = m_pFlashBigFile;
    m_pFlashBigFile = 0;
    return data;
}
