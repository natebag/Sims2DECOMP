class EMirrorPortal {
public:
    char m_pad[56];
    int m_numCorners;
    void SetNumCorners(int);
};
void EMirrorPortal::SetNumCorners(int n) { m_numCorners = n; }
