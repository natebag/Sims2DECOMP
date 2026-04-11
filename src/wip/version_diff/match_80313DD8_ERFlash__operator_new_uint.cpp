typedef unsigned int size_t;

struct EResourceManager;
void *EResourceManager__Alloc(EResourceManager *, size_t size, unsigned int align);

extern EResourceManager _flashman;

struct ERFlash {
    void *operator new(size_t size);
};

void *ERFlash::operator new(size_t size)
{
    return EResourceManager__Alloc(&_flashman, size, 8);
}
