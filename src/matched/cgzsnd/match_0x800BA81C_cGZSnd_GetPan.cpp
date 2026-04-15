// 0x800BA81C cGZSnd::GetPan (8B) — lwz r3, 36(r3)
struct cGZSnd {
    char pad[36];
    int m_pan;
    int GetPan();
};
int cGZSnd::GetPan() { return m_pan; }
