struct AptSFBCB_GN {
    char pad[0x3C];
    char* m_name;
    char* GetName() const;
};

char* AptSFBCB_GN::GetName() const {
    return m_name;
}
