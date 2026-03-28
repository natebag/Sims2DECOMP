class CASGeneticsTarget {
public:
    char _pad[0x94];
    void *m_casGenetics;

    void *GetCasGenetics();
};

void *CASGeneticsTarget::GetCasGenetics() {
    return m_casGenetics;
}
