/* HouseStats::GetNumBedrooms(void) at 0x800BC95C (8B) */

struct HouseStats {
    char pad[0x08];
    int m_numBedrooms;

    int GetNumBedrooms(void);
};

int HouseStats::GetNumBedrooms(void) {
    return m_numBedrooms;
}
