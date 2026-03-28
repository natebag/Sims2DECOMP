typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0x130];
    int m_nLastCostume;
public:
    int GetLastCostume();
};

int SAnimator2::GetLastCostume() {
    return m_nLastCostume;
}
