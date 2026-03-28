/* NghResFile::GetCurrentHouse(void) const - 0x800D93C0 (12 bytes) */

struct NghResFile {
    char m_pad[0x24];
    int m_currentHouse;

    int GetCurrentHouse(void) const;
};

int NghResFile::GetCurrentHouse(void) const {
    return m_currentHouse + 1;
}
