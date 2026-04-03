/* HouseStats::GetNumLevels(void) at 0x800BC96C (8B) */

struct HouseStats {
    char pad[0x10];
    int m_numLevels;

    int GetNumLevels(void);
};

int HouseStats::GetNumLevels(void) {
    return m_numLevels;
}
