class CASMorphTarget {
public:
    char _pad[0x1C0];
    int m_exitDone;

    void ExitMorphScreenDone(void);
};

void CASMorphTarget::ExitMorphScreenDone(void) {
    m_exitDone = 0;
}
