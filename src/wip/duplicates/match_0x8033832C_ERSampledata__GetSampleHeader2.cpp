struct ERSampledata {
    char _pad[0x18];
    int m_hdr2;
    int GetSampleHeader2() const;
};
int ERSampledata::GetSampleHeader2() const { return m_hdr2; }
