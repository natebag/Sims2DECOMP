// 0x800BC974 (8B) HouseStats::GetLotSize(void)
// Getter for field at offset 0x14.

class HouseStats {
public:
    char pad_000[0x14];
    int m_field_14;
    int GetLotSize(void);
};

int HouseStats::GetLotSize(void) {
    return m_field_14;
}
