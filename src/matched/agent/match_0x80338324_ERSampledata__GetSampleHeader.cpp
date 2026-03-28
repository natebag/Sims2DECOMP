struct ERSampledata {
    char _pad[0x14];
    int m_hdr;
    int GetSampleHeader() const;
};
int ERSampledata::GetSampleHeader() const { return m_hdr; }
