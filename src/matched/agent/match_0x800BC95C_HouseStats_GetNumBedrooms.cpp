// 0x800BC95C (8B) HouseStats::GetNumBedrooms(void)
// Getter for field at offset 0x8.

class HouseStats {
public:
    char pad_000[0x8];
    int m_field_8;
    int GetNumBedrooms(void);
};

int HouseStats::GetNumBedrooms(void) {
    return m_field_8;
}
