class cGZSnd {
public:
    char pad[0x24];
    int m_pan;

    int GetPan(void);
};

int cGZSnd::GetPan(void) {
    return m_pan;
}
