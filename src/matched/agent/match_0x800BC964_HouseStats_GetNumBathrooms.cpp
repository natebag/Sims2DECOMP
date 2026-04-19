// 0x800BC964 (8B) HouseStats::GetNumBathrooms(void)
// Getter for field at offset 0xC.

class HouseStats {
public:
    char pad_000[0xC];
    int m_field_C;
    int GetNumBathrooms(void);
};

int HouseStats::GetNumBathrooms(void) {
    return m_field_C;
}
