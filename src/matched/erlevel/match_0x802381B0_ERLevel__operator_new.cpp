/* ERLevel::operator new(unsigned int) at 0x802381B0 (48B) */

extern char gEResourceManager[];

struct EResourceManager_ONW {
    void* Alloc(unsigned int size, unsigned int align);
};

struct ERLevel_ONW {
    static void* operator new(unsigned int size);
};

void* ERLevel_ONW::operator new(unsigned int size) {
    return ((EResourceManager_ONW*)gEResourceManager)->Alloc(size, 16);
}
