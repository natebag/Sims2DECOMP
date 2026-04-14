/* NghResFile::GetThumbGUID(unsigned int) - 0x800D5470 (20 bytes) */

struct NghResFile {
    char m_pad[0x194];
    unsigned int m_thumbGUIDs[1];

    unsigned int GetThumbGUID(unsigned int index);
};

unsigned int NghResFile::GetThumbGUID(unsigned int index) {
    return m_thumbGUIDs[index - 1];
}
