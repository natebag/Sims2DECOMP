/* NghResFile::StoreThumbGUID(unsigned int, unsigned int) - 0x800D545C (20 bytes) */

struct NghResFile {
    char m_pad[0x194];
    unsigned int m_thumbGUIDs[1];

    void StoreThumbGUID(unsigned int index, unsigned int guid);
};

void NghResFile::StoreThumbGUID(unsigned int index, unsigned int guid) {
    m_thumbGUIDs[index - 1] = guid;
}
