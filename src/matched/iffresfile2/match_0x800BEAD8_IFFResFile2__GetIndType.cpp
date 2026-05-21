// 0x800BEAD8 (160B) IFFResFile2::GetIndType(short)

class iResFile {
public:
    int m_0, m_4, m_8;
    void SetError(int);
    int GetError();
};

class IFFResMap {
public:
    void* GetIndType(short);
};

class IFFResFile2 : public iResFile {
public:
    char m_padC[312-12];
    IFFResMap* m_138_resMap;
    void* GetIndType(short arg);
};

void* IFFResFile2::GetIndType(short arg) {
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
    void* result = m_138_resMap->GetIndType(arg);
    if (result == 0) {
        SetError(-100);
    }
    return result;
}
