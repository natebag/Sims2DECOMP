// 0x800BE4A4 (96B) IFFResFile2::Delete(StringBuffer&)
// Tech #47 MI-vcall via secondary vt @ +12, fn slot 96/100

class StringBuffer;

extern "C" int Delete__7MemFileFR12StringBuffer(void*, StringBuffer&);

class IFFResFile2 {
public:
    int Delete(StringBuffer& sb);
};

int IFFResFile2::Delete(StringBuffer& sb) {
    char* obj = (char*)this;
    char* vt = *(char**)(obj + 12);
    short adj = *(short*)(vt + 96);
    int (*fn)(void*) = *(int (**)(void*))(vt + 100);
    int rc = fn(obj + adj);
    if (rc != 0) return -47;
    return Delete__7MemFileFR12StringBuffer(obj + 16, sb);
}
