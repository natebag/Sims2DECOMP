// cXPersonImpl::GetAspirationScore(void) - 0x801256EC (96B)
// ASMPROC_replace_insn: match="lwzu 9,4(11)" replacement="lwz 9,4(11)"

static const float kC0 = 100.0f;
static const float kC1 = 200.0f;
static const float kC2 = 1000.0f;

class IPrimary { public: virtual void p0() = 0; };
class ISecondary {
public:
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual float GetScore(int flags) = 0;  // slot 10, lha offset 88
};
class IFull : public IPrimary, public ISecondary {};

struct cXPerson_GetAspScore {
    char pad[4];
    IFull* m_obj;  // offset 4

    float GetAspirationScore();
};

float cXPerson_GetAspScore::GetAspirationScore() {
    float internal = m_obj->GetScore(0);
    return (internal + kC0) / kC1 * kC2;
}
