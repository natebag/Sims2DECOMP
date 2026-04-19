// 0x801C77CC (80B) MMUTarget::OnCancelKeyPressed(char*, char*)
// Guarded own-vtable call: if (m_field_08C == 0) this->SendCmd("MMU_GO_UP_TREE", 0)
// 3-layer hierarchy forces vtable at 0x80: base (pad) + mid (only virtuals) + derived (only fields).

struct MMUTargetBase { char pad[128]; };

struct MMUTargetMid : public MMUTargetBase {
    virtual void f0_filler() = 0;
    virtual void SendCmd(const char* cmd, const char* arg) = 0;
};

class MMUTarget : public MMUTargetMid {
public:
    char pad_084[8];   // 0x84-0x8B
    int m_field_08C;   // 0x8C

    void OnCancelKeyPressed(char* a, char* b);
};

void MMUTarget::OnCancelKeyPressed(char*, char*) {
    if (m_field_08C != 0) return;
    this->SendCmd("MMU_GO_UP_TREE", 0);
}
