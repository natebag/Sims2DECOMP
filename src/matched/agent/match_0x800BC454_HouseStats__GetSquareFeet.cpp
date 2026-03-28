/* HouseStats::GetSquareFeet(void) at 0x800BC454 (8B) */

struct HouseStats {
    int m_squareFeet;

    int GetSquareFeet(void);
};

int HouseStats::GetSquareFeet(void) {
    return m_squareFeet;
}
