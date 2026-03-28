class CASTarget {
public:
    char _pad[0x104];
    int m_viewMode;

    int ShowAllCFAOptions(void);
};

int CASTarget::ShowAllCFAOptions(void) {
    int mode = m_viewMode;
    if (mode == 0 || mode == 1 || mode == 5) {
        return 1;
    }
    return 0;
}
