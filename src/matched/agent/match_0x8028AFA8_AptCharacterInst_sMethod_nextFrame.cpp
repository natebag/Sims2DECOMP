// 0x8028AFA8 (76B) AptCharacterInst::sMethod_nextFrame(AptValue*, int)
struct AptValue;
struct AptCIH;
extern volatile int g_someGlobal;

struct AptCIH {
    char pad[0x18];
    int m_frame;
    int m_flags;
};

struct AptCharacterInst {
    char pad[0x4c];
    AptCIH* m_cih;
    void jumpToFrame(int);
    void sMethod_nextFrame(AptValue*, int);
};

void AptCharacterInst::sMethod_nextFrame(AptValue* val, int arg) {
    int frame = m_cih->m_frame + 1;
    jumpToFrame(frame);
    int dummy = g_someGlobal;
    m_cih->m_flags &= ~0x40;
}
