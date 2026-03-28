class CASMorphTarget {
public:
    char _pad[0x1C0];
    int m_morphScreenActive;

    void ExitMorphScreenDone(void);
};

void CASMorphTarget::ExitMorphScreenDone(void) {
    m_morphScreenActive = 0;
}
