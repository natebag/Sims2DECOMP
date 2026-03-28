struct EResource {
    char _pad[0x08];
    unsigned int m_resId;
    void SetResId(unsigned int val);
};
void EResource::SetResId(unsigned int val) { m_resId = val; }
