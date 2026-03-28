typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x130];
    int m_nLastCostume;
public:
    void SetLastCostume(int);
};

void SAnimator2::SetLastCostume(int costume) {
    m_nLastCostume = costume;
}
