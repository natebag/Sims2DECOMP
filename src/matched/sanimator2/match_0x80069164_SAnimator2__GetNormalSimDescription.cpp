/* 0x80069164 (8 bytes) - SAnimator2::GetNormalSimDescription(void) const */
class CasSimDescriptionS2C;
struct SAnimator2 {
    char pad[0x604];
    CasSimDescriptionS2C* m_normalSimDesc;
    CasSimDescriptionS2C* GetNormalSimDescription() const;
};
CasSimDescriptionS2C* SAnimator2::GetNormalSimDescription() const { return m_normalSimDesc; }
