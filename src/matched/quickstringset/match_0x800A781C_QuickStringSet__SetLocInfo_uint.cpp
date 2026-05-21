// 0x800A781C (112B) QuickStringSet::SetLocInfo(unsigned int, short, unsigned int, bool, char)
// Direct port of SetInfo(uint) — calls SetLocInfo(iResFile*) instead

class iResFile;
extern "C" char* Globs__pObjectFolder;

class QuickStringSet {
public:
    void SetLocInfo(unsigned int id, short a, unsigned int b, bool c, char d);
    void SetLocInfo(iResFile* file, short a, unsigned int b, bool c, char d);
};

void QuickStringSet::SetLocInfo(unsigned int id, short a, unsigned int b, bool c, char d) {
    char* mgr = Globs__pObjectFolder;
    char* vt = *(char**)mgr;
    short adj = *(short*)(vt + 56);
    void* fn = *(void**)(vt + 60);
    iResFile* file = ((iResFile* (*)(void*, unsigned int))fn)(mgr + adj, id);
    SetLocInfo(file, a, b, c, d);
}
