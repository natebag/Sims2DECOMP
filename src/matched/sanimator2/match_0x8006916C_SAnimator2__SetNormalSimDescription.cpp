/* 0x8006916C (8 bytes) - SAnimator2::SetNormalSimDescription(CasSimDescriptionS2C *) */
class CasSimDescriptionS2C;
struct SAnimator2 {
    char pad[0x604];
    CasSimDescriptionS2C* m_normalSimDesc;
    void SetNormalSimDescription(CasSimDescriptionS2C* p);
};
void SAnimator2::SetNormalSimDescription(CasSimDescriptionS2C* p) { m_normalSimDesc = p; }
