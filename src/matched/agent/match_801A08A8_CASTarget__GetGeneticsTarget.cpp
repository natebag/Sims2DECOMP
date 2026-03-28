class CASTarget {
public:
    char _pad[0x1370];
    void *m_geneticsTarget;

    void *GetGeneticsTarget();
};

void *CASTarget::GetGeneticsTarget() {
    return m_geneticsTarget;
}
