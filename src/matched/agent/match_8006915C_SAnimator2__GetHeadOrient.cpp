typedef unsigned char u8;

struct HeadOrient {
    float data[4];
};

class SAnimator2 {
    u8 _pad0[0x180];
    HeadOrient m_headOrient;
public:
    HeadOrient *GetHeadOrient();
};

HeadOrient *SAnimator2::GetHeadOrient() {
    return &m_headOrient;
}
