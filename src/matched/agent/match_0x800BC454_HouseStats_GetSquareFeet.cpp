// 0x800BC454 (8B) HouseStats::GetSquareFeet(void)
// Getter for field at offset 0x0.

class HouseStats {
public:
    int m_field_0;
    int GetSquareFeet(void);
};

int HouseStats::GetSquareFeet(void) {
    return m_field_0;
}
