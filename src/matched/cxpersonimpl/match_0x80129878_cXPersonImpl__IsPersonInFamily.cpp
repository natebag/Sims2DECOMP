// cXPersonImpl::IsPersonInFamily(int) - 0x80129878 (112B)
// FLAGS: -msdata=eabi -G 8

class INeighborhood_P { public: virtual void p0() = 0; };
class INeighborhood_S {
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
    virtual void s16() = 0;
    virtual void s17() = 0;
    virtual void s18() = 0;
    virtual void s19() = 0;
    virtual void s20() = 0;
    virtual void s21() = 0;
    virtual void s22() = 0;
    virtual void s23() = 0;
    virtual void s24() = 0;
    virtual void s25() = 0;
    virtual void s26() = 0;
    virtual void s27() = 0;
    virtual void s28() = 0;
    virtual void s29() = 0;
    virtual void s30() = 0;
    virtual void s31() = 0;
    virtual void s32() = 0;
    virtual void s33() = 0;
    virtual void s34() = 0;
    virtual void* GetFamily(int playerIdx) = 0;  // slot 35
};
class INeighborhood : public INeighborhood_S, public INeighborhood_P {};

class IFamily_P { public: virtual void p0() = 0; };
class IFamily_S {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual int TestMember(void* person) = 0;  // slot 9
};
class IFamily : public IFamily_S, public IFamily_P {};

extern INeighborhood* g_neighborhood;

struct cXPerson_IsPersonInFamily {
    char pad0[4];
    void* m_person;  // offset 4

    int IsPersonInFamily(int playerIdx);
};

int cXPerson_IsPersonInFamily::IsPersonInFamily(int playerIdx) {
    INeighborhood* nb = g_neighborhood;
    IFamily* fam = (IFamily*)nb->GetFamily(playerIdx);
    if (!fam) return 0;
    return fam->TestMember(m_person);
}
