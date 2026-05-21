// 0x800A7A00 (108B) QuickStringSet::SetLocInfo(iResFile *, short, unsigned int, bool, char)

class iResFile;
extern "C" void* helper_0x803A2344(void* start, void* end);

class QuickStringSet {
public:
    void SetLocInfo(iResFile* file, short a, unsigned int b, bool c, char d);
};

void QuickStringSet::SetLocInfo(iResFile* file, short a, unsigned int b, bool c, char d) {
    if (file == 0) return;
    *(volatile int*)((char*)this + 8) = 0;
    *(volatile int*)((char*)this + 4) = 0;
    char* p = *(char**)((char*)file + 8);
    if (p == 0) return;
    char* subobj = *(char**)((char*)p + 20);
    int count = 0;
    if (subobj != 0) count = *(int*)(subobj - 4);
    char* end_addr = subobj + count * 12;
    *(void**)((char*)this + 4) = helper_0x803A2344(subobj, end_addr);
}
