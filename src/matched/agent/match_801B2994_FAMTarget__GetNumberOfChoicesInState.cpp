class FAMTarget {
public:
    char _pad[0x154];
    int m_numFamilies;
    int m_numLots;

    int GetNumberOfChoicesInState(int state);
};

int FAMTarget::GetNumberOfChoicesInState(int state) {
    switch (state) {
        case 0:
            return m_numFamilies;
        case 1:
            return 2;
        case 2:
            return m_numFamilies;
        case 3:
            return 3;
        case 4:
            return m_numLots;
        default:
            return -1;
    }
}
