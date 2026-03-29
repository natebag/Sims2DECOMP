typedef unsigned int uint;

void *BIG_count(void *big);
int ERFlash_IsTexture(void *self, int index);
void EResource_DelRef(void *r);
void __builtin_delete(void *p);

struct EResourceManager;
extern EResourceManager _flashman;
void EResourceManager_Free(EResourceManager *mgr, void *ptr);

struct TextureEntry {
    void *pTexture;
    int width;
    int height;
};

struct FlashBigFile {
    void *m_bigFile;
    TextureEntry **m_dataArray;

    void dtor(int flags);
};

void FlashBigFile::dtor(int flags)
{
    int count = (int)(uint)BIG_count(m_bigFile);
    for (int i = 0; i < count; i++) {
        if (ERFlash_IsTexture(this, i)) {
            TextureEntry *entry = m_dataArray[i];
            if (entry != 0) {
                if (entry->pTexture != 0)
                    EResource_DelRef(entry->pTexture);
                entry->width = 0;
                entry->height = 0;
                __builtin_delete(entry);
            }
        } else {
            EResourceManager_Free(&_flashman, m_dataArray[i]);
        }
        m_dataArray[i] = 0;
    }
    EResourceManager_Free(&_flashman, m_dataArray);
    m_dataArray = 0;
    EResourceManager_Free(&_flashman, m_bigFile);
    m_bigFile = 0;
    if (flags & 1)
        __builtin_delete(this);
}
