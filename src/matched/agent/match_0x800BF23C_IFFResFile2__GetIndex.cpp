// 0x800BF23C IFFResFile2::GetIndex(Memory::HandleNode*, short*) (136B)

struct HandleNode;

struct IFFResFile2 {
    char pad[12];
    int* m_vt;
    void GetIndex(HandleNode* h, short* outIdx);
};

extern "C" void IFFRes_DoWithCode(IFFResFile2* self, int code);
extern "C" int IFFRes_CheckDone(IFFResFile2* self);

void IFFResFile2::GetIndex(HandleNode* h, short* outIdx) {
    int* vt = m_vt;
    short adj = *(short*)((char*)vt + 96);
    int (*fn)(void*, HandleNode*) = (int (*)(void*, HandleNode*))*(void**)((char*)vt + 100);
    int rc = fn((char*)this + adj, h);

    if (rc == 0) {
        IFFRes_DoWithCode(this, -49);
    } else {
        IFFRes_DoWithCode(this, 0);
    }

    int r = IFFRes_CheckDone(this);
    if (r == 0) {
        IFFRes_DoWithCode(this, -95);
        *outIdx = (short)r;
    }
}
