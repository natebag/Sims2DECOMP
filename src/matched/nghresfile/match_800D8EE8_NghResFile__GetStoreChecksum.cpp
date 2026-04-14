/* NghResFile::GetStoreChecksum(void) - 0x800D8EE8 (8 bytes) */

struct NghResFile {
    char m_pad[0x18C];
    int m_storeChecksum;

    int GetStoreChecksum(void);
};

int NghResFile::GetStoreChecksum(void) {
    return m_storeChecksum;
}
