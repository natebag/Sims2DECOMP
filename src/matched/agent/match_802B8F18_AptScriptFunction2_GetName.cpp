struct Inner_SF2N {
    char* m_name;
};
struct AptSF2_GN {
    char pad[0x34];
    Inner_SF2N* m_inner;
    char* GetName() const;
};
char* AptSF2_GN::GetName() const {
    return m_inner->m_name;
}
