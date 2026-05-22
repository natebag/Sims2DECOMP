// 0x800BE7CC IFFResFile2::CloseForReopen(void) (104B)
// ASMPROC_swap_adj: a=addi b=mr which=first

class StringBuffer {
public:
    StringBuffer(char* buf, unsigned int len);
};

extern "C" void GetFileName__7MemFileFR12StringBuffer(void*, StringBuffer&);

class IFFResFile2 {
public:
    void CloseForReopen();
};

extern "C" void __ct__12StringBufferFPcUi(StringBuffer*, char*, unsigned int);

void IFFResFile2::CloseForReopen() {
    char* obj = (char*)this;
    char* alloc = (char*)operator new(268);
    __ct__12StringBufferFPcUi((StringBuffer*)alloc, alloc + 8, 260);
    *(char**)(obj + 332) = alloc;
    GetFileName__7MemFileFR12StringBuffer(obj + 16, *(StringBuffer*)alloc);
    char* vt = *(char**)(obj + 12);
    short adj = *(short*)(vt + 64);
    void* fn = *(void**)(vt + 68);
    ((void (*)(void*))fn)(obj + adj);
}
