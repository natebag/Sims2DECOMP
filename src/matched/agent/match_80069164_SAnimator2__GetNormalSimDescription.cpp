typedef unsigned char u8;
class CasSimDescriptionS2C;

class SAnimator2 {
    u8 _pad0[0x604];
    CasSimDescriptionS2C *m_pNormalSimDescription;
public:
    CasSimDescriptionS2C *GetNormalSimDescription() const;
};

CasSimDescriptionS2C *SAnimator2::GetNormalSimDescription() const {
    return m_pNormalSimDescription;
}
