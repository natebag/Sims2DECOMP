/* NghResFile::SetCurrentHouse(unsigned int) - 0x800D3F78 (12 bytes) */

struct NghResFile {
    char m_pad[0x24];
    int m_currentHouse;

    void SetCurrentHouse(unsigned int house);
};

void NghResFile::SetCurrentHouse(unsigned int house) {
    m_currentHouse = house - 1;
}
