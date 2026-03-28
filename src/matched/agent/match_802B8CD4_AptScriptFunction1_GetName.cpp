struct Inner_SF1N {
    char* m_name;
};
struct AptSF1_GN {
    char pad[0x34];
    Inner_SF1N* m_inner;
    char* GetName() const;
};
char* AptSF1_GN::GetName() const {
    return m_inner->m_name;
}
