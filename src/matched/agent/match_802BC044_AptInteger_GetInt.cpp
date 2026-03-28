struct AptInteger_GI {
    char pad[0x0C];
    int m_int;
    int GetInt() const;
};

int AptInteger_GI::GetInt() const {
    return m_int;
}
