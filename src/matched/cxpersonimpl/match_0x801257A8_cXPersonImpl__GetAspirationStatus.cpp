// cXPersonImpl::GetAspirationStatus(void) - 0x801257A8 (140B)
// ASMPROC_replace_insn: match="lwzu 9,4(11)" replacement="lwz 9,4(11)"

static const float kThresh0 = 0.1f;
static const float kThresh1 = 0.5f;
static const float kThresh2 = 0.9f;

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
    virtual void s13() = 0;
    virtual void s14() = 0;
    virtual void s15() = 0;
    virtual float GetStatus() = 0;  // slot 16, lha offset 136
};
class IFull : public IPrimary, public ISecondary {};

struct cXPerson_GetAspirationStatus {
    char pad[4];
    IFull* m_obj;  // offset 4

    int GetAspirationStatus();
};

int cXPerson_GetAspirationStatus::GetAspirationStatus() {
    float score = m_obj->GetStatus();
    if (score <= kThresh0) return 0;
    if (score <= kThresh1) return 1;
    if (score <= kThresh2) return 2;
    return 3;
}
