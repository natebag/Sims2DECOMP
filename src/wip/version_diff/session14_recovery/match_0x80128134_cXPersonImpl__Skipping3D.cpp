// cXPersonImpl::Skipping3D(void) - 0x80128134 (128B)

class IFoo_P { public: virtual void p0() = 0; };
class IFoo_S {
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
    virtual void s35() = 0;
    virtual void s36() = 0;
    virtual void s37() = 0;
    virtual void s38() = 0;
    virtual void s39() = 0;
    virtual void s40() = 0;
    virtual void s41() = 0;
    virtual void s42() = 0;
    virtual void s43() = 0;
    virtual void s44() = 0;
    virtual void s45() = 0;
    virtual void s46() = 0;
    virtual void s47() = 0;
    virtual void* GetObj() = 0;  // slot 48, secondary vtable adj=392 fptr=396
};
class IFoo : public IFoo_P, public IFoo_S {};  // P primary → secondary vtable at +4

class IBar_S {
public:
    virtual void b0() = 0;
    virtual void b1() = 0;
    virtual void b2() = 0;
    virtual void b3() = 0;
    virtual void b4() = 0;
    virtual void b5() = 0;
    virtual void b6() = 0;
    virtual void b7() = 0;
    virtual void b8() = 0;
    virtual void b9() = 0;
    virtual void b10() = 0;
    virtual void b11() = 0;
    virtual void b12() = 0;
    virtual void b13() = 0;
    virtual void b14() = 0;
    virtual void b15() = 0;
    virtual void b16() = 0;
    virtual void b17() = 0;
    virtual void b18() = 0;
    virtual int IsSkipping3D() = 0;  // slot 19, primary vtable adj=160 fptr=164
};
class IBar_P { public: virtual void p0() = 0; };
class IBar : public IBar_S, public IBar_P {};  // S primary → primary vtable at +0

struct cXPerson_Skipping3D {
    char pad[4];
    IFoo* m_field;  // offset 4

    int Skipping3D();
};

int cXPerson_Skipping3D::Skipping3D() {
    if (!m_field->GetObj())
        return 0;
    IBar* bar = (IBar*)m_field->GetObj();
    return bar->IsSkipping3D();
}
