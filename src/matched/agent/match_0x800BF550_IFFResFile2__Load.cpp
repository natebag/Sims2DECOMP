// 0x800BF550 IFFResFile2::Load(Memory::HandleNode*) (128B)

struct HandleNode;

struct IFFResFile2 {
    char pad[12];
    int* m_vt;  // offset 12 — secondary vtable pointer
    void Load(HandleNode* h);
};

extern "C" void IFFRes_DoWithCode(IFFResFile2* self, int code);  // 0x8013562c
extern "C" int IFFRes_CheckDone(IFFResFile2* self);              // 0x80135624

void IFFResFile2::Load(HandleNode* h) {
    int* vt = m_vt;
    short adj = *(short*)((char*)vt + 96);
    int (*fn)(void*, HandleNode*) = (int (*)(void*, HandleNode*))*(void**)((char*)vt + 100);
    int rc = fn((char*)this + adj, h);

    if (rc == 0) {
        IFFRes_DoWithCode(this, -49);
    } else {
        IFFRes_DoWithCode(this, 0);
    }

    if (IFFRes_CheckDone(this) == 0) {
        IFFRes_DoWithCode(this, -95);
    }
}
