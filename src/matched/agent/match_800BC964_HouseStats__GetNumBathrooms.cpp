class HouseStats {
public:
    int m_squareFeet;
    int pad_04;
    int m_numBedrooms;
    int m_numBathrooms;

    int GetNumBathrooms(void);
};

int HouseStats::GetNumBathrooms(void) {
    return m_numBathrooms;
}
