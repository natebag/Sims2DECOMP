// 0x800BF3D4 (152B) IFFResFile2::FindUniqueID(int)

class iResFile {
public:
    int m_0, m_4, m_8;
    void SetError(int);
    int GetError();
};

class IFFResMap {
public:
    int GetHighestID(unsigned int, short);
};

class IFFResFile2 : public iResFile {
public:
    char m_padC[312-12];
    IFFResMap* m_138_resMap;
    short FindUniqueID(int arg);
};

short IFFResFile2::FindUniqueID(int arg) {
    char* obj = (char*)this;
    char* vt = *(char**)(obj + 12);
    short adj = *(short*)(vt + 96);
    int (*fn)(void*) = *(int (**)(void*))(vt + 100);
    int rc = fn(obj + adj);
    if (rc == 0) {
        SetError(-49);
    } else {
        SetError(0);
    }
    if (GetError() != 0) return 0;
    int id = m_138_resMap->GetHighestID((unsigned int)arg, 128);
    return (short)(id + 1);
}
