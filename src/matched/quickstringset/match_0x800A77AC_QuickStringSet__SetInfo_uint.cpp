// 0x800A77AC (112B) QuickStringSet::SetInfo(unsigned int, short, unsigned int, bool, char)

class iResFile;
extern "C" char* Globs__pObjectFolder;  // SDA r13-21508

class QuickStringSet {
public:
    void SetInfo(unsigned int id, short a, unsigned int b, bool c, char d);
    void SetInfo(iResFile* file, short a, unsigned int b, bool c, char d);
};

void QuickStringSet::SetInfo(unsigned int id, short a, unsigned int b, bool c, char d) {
    char* mgr = Globs__pObjectFolder;
    char* vt = *(char**)mgr;
    short adj = *(short*)(vt + 56);
    void* fn = *(void**)(vt + 60);
    iResFile* file = ((iResFile* (*)(void*, unsigned int))fn)(mgr + adj, id);
    SetInfo(file, a, b, c, d);
}
