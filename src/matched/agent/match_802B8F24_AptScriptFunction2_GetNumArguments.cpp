struct Inner_SF2NA {
    char pad[0x04];
    int m_numArgs;
};
struct AptSF2_GNA {
    char pad[0x34];
    Inner_SF2NA* m_inner;
    int GetNumArguments();
};
int AptSF2_GNA::GetNumArguments() {
    return m_inner->m_numArgs;
}
