struct EResource {
    char _pad[0x08];
    unsigned int m_resId;
    unsigned int GetResId() const;
};
unsigned int EResource::GetResId() const { return m_resId; }
