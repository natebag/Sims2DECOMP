struct ERQuickdata {
    char _pad[0x14];
    int m_image;
    int GetImage() const;
};
int ERQuickdata::GetImage() const { return m_image; }
