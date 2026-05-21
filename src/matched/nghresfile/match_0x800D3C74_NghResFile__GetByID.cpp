// 0x800D3C74 (84B) NghResFile::GetByID(int, short, void (*)(void *, int))

extern "C" void* helper_0x800D4348(void* this_, int id);

class NghResFile {
public:
    void* GetByID(int id, short version, void (*cb)(void*, int));
};

void* NghResFile::GetByID(int id, short version, void (*cb)(void*, int)) {
    int v = version;
    void* it = helper_0x800D4348(this, id);
    goto advance;
compare:
    if ((int)*(unsigned short*)((char*)it + 8) == v) {
        return *(void**)((char*)it + 4);
    }
advance:
    it = *(void**)((char*)it + 0);
    if (it != 0) goto compare;
    return 0;
}
