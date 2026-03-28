class HouseStats {
public:
    int m_squareFeet;
    int pad_04;
    int m_numBedrooms;
    int m_numBathrooms;
    int m_numLevels;

    int GetNumLevels(void);
};

int HouseStats::GetNumLevels(void) {
    return m_numLevels;
}
