struct AptBoolean_GB {
    char pad[0x0C];
    int m_bool;
    int GetBool() const;
};

int AptBoolean_GB::GetBool() const {
    return m_bool;
}
