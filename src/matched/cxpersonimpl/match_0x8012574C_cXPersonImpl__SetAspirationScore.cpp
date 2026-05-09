// cXPersonImpl::SetAspirationScore(float) - 0x8012574C (92B)
// ASMPROC_replace_insn: match="lwzu 10,4(8)" replacement="lwz 10,4(8)"

static const float kC0 = 1000.0f;
static const float kC1 = 200.0f;
static const float kC2 = 100.0f;

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
    virtual void s10() = 0;
    virtual void s11() = 0;
    virtual void s12() = 0;
    virtual void SetScore(int flags, float score) = 0;  // slot 13, lha offset 112
};
class IFull : public IPrimary, public ISecondary {};

struct cXPerson_SetAspScore {
    char pad[4];
    IFull* m_obj;  // offset 4

    void SetAspirationScore(float val);
};

void cXPerson_SetAspScore::SetAspirationScore(float val) {
    float f12 = val / kC0;
    float result = f12 * kC1 - kC2;
    m_obj->SetScore(0, result);
}
