/* HouseStats::GetNumBathrooms(void) at 0x800BC964 (8B) */

struct HouseStats {
    char pad[0x0C];
    int m_numBathrooms;

    int GetNumBathrooms(void);
};

int HouseStats::GetNumBathrooms(void) {
    return m_numBathrooms;
}
