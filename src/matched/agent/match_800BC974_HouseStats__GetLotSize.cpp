class HouseStats {
public:
    int m_squareFeet;
    int pad_04;
    int m_numBedrooms;
    int m_numBathrooms;
    int m_numLevels;
    int m_lotSize;

    int GetLotSize(void);
};

int HouseStats::GetLotSize(void) {
    return m_lotSize;
}
