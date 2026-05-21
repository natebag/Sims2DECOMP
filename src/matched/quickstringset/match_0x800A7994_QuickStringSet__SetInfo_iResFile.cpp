// 0x800A7994 (108B) QuickStringSet::SetInfo(iResFile *, short, unsigned int, bool, char)

class iResFile;
extern "C" void* helper_0x803A22D4(void* start, void* end);

class QuickStringSet {
public:
    void SetInfo(iResFile* file, short a, unsigned int b, bool c, char d);
};

void QuickStringSet::SetInfo(iResFile* file, short a, unsigned int b, bool c, char d) {
    *(volatile int*)((char*)this + 8) = 0;
    *(volatile int*)((char*)this + 4) = 0;
    if (file == 0) return;
    char* p = *(char**)((char*)file + 8);
    if (p == 0) return;
    char* subobj = *(char**)((char*)p + 16);
    int count = 0;
    if (subobj != 0) count = *(int*)(subobj - 4);
    char* end_addr = subobj + count * 12;
    *(void**)((char*)this + 8) = helper_0x803A22D4(subobj, end_addr);
}
