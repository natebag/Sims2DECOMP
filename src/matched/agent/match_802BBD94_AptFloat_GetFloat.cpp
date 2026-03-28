struct AptFloat_GF {
    char pad[0x0C];
    float m_float;
    float GetFloat() const;
};

float AptFloat_GF::GetFloat() const {
    return m_float;
}
