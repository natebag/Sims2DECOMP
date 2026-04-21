// 0x80338334 (60B) ENgcRC::ENgcRC(void)
// Calls base ERC ctor, then writes vtable pointer to this+0x70 (=112).
// stmw/lmw r30 saves `this` across the base-ctor bl.

class ERC {
public:
    ERC();
};

extern char s_ENgcRC_vtable[];  // at 0x804735F0

class ENgcRC : public ERC {
public:
    char pad[112 - 4];  // base ERC is small; vtable slot at offset 112
    void* m_vtable;
    ENgcRC();
};

ENgcRC::ENgcRC() : ERC() {
    m_vtable = s_ENgcRC_vtable;
}
