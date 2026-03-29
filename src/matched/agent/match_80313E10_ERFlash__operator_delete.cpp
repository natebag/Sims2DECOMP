struct EResourceManager;
void EResourceManager__Free(EResourceManager *, void *ptr);

extern EResourceManager _flashman;

struct ERFlash {
    void operator delete(void *ptr);
};

void ERFlash::operator delete(void *ptr)
{
    EResourceManager__Free(&_flashman, ptr);
}
