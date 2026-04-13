class HouseStats {
public:
    int m_squareFeet;
    int pad_04;
    int m_numBedrooms;

    int GetNumBedrooms(void);
};

int HouseStats::GetNumBedrooms(void) {
    return m_numBedrooms;
}
