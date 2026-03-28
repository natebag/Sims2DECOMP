typedef unsigned char u8;
class CasSimDescriptionS2C;

class SAnimator2 {
    u8 _pad0[0x604];
    CasSimDescriptionS2C *m_pNormalSimDescription;
public:
    void SetNormalSimDescription(CasSimDescriptionS2C *);
};

void SAnimator2::SetNormalSimDescription(CasSimDescriptionS2C *desc) {
    m_pNormalSimDescription = desc;
}
