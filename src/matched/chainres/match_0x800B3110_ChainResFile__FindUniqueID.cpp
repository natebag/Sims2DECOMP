// 0x800B3110 (100B) ChainResFile::FindUniqueID(int)

class iResFile {
public:
    int m_0, m_4, m_8;
    void SetError(int);
};

class ChainResFile : public iResFile {
public:
    char m_padC[16 - 12];
    void* m_10_first;
    short FindUniqueID(int arg);
};

short ChainResFile::FindUniqueID(int arg) {
    SetError(0);
    char* obj = (char*)m_10_first;
    if (obj == 0) return 0;
    char* vt = *(char**)(obj + 12);
    short adj = *(short*)(vt + 208);
    short (*fn)(void*, int) = *(short (**)(void*, int))(vt + 212);
    return fn(obj + adj, arg);
}
