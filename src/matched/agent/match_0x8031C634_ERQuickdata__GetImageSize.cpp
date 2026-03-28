struct ERQuickdata {
    char _pad[0x18];
    int m_imageSize;
    int GetImageSize() const;
};
int ERQuickdata::GetImageSize() const { return m_imageSize; }
