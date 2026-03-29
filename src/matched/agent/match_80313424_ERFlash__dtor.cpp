extern int ERFlash_vtable[];

void ERFlash_Deallocate(void *obj);
void EResourceDestructor(void *obj, int flag);

struct EResourceManager;
void EResourceManager__Free(EResourceManager *, void *ptr);
extern EResourceManager _flashman;

struct ERFlash {
    int *_vtable;
    char _pad_04[16];
    void *m_pFlashBigFile;

    void dtor(int flags);
};

void ERFlash::dtor(int flags)
{
    _vtable = ERFlash_vtable;
    ERFlash_Deallocate(this);
    EResourceDestructor(this, 0);
    if (flags & 1) {
        EResourceManager__Free(&_flashman, this);
    }
}
