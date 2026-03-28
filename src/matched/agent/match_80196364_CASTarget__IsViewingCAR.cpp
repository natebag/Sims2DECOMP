class CASTarget {
public:
    char _pad[0x104];
    int m_viewMode;

    int IsViewingCAR(void);
};

int CASTarget::IsViewingCAR(void) {
    return m_viewMode == 3;
}
