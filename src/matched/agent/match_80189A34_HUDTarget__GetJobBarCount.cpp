class HUDTarget {
public:
    char _pad[0xCA];
    unsigned short m_jobBarCount;

    int GetJobBarCount(void);
};

int HUDTarget::GetJobBarCount(void) {
    if (m_jobBarCount == 0) {
        return 5;
    }
    return m_jobBarCount + 2;
}
