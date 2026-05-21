// 0x800BF5D0 (192B) IFFResFile2::IsLittleEndian(Memory::HandleNode*)

class iResFile {
public:
    int m_0, m_4, m_8;
    void SetError(int);
    int GetError();
};

namespace Memory { class HandleNode; }

struct IFFResNode {
    char m_pad0[8];
    unsigned short m_flags;
};

class IFFResMap {
public:
    IFFResNode* GetNode(Memory::HandleNode* hn, unsigned int* idxOut, void (*cb)(void*, int));
};

class IFFResFile2 : public iResFile {
public:
    char m_padC[300];
    IFFResMap* m_138_resMap;
    int IsLittleEndian(Memory::HandleNode* hn);
};

int IFFResFile2::IsLittleEndian(Memory::HandleNode* hn) {
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
    if (GetError() != 0) return 1;

    unsigned int localIdx;
    IFFResNode* node = m_138_resMap->GetNode(hn, &localIdx, 0);
    if (node != 0) {
        SetError(0);
        return (node->m_flags >> 4) & 1;
    }
    SetError(-99);
    return 1;
}
