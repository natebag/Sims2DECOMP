/* NghResFile::SetStoreChecksum(bool) - 0x800D8EE0 (8 bytes) */

struct NghResFile {
    char m_pad[0x18C];
    int m_storeChecksum;

    void SetStoreChecksum(bool val);
};

void NghResFile::SetStoreChecksum(bool val) {
    m_storeChecksum = val;
}
