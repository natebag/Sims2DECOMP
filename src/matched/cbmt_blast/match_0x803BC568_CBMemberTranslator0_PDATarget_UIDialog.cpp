// FLAGS: -fno-schedule-insns
// CBMemberTranslator0<PDATarget, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &) at 0x803BC568 (144 bytes)
// PMF ABI crack — 144B variant with multi-inheritance offset (UIDialog at +0x84)

class UIDialog {
public:
    virtual void dummy();
};

class OtherBase {
public:
    char pad[0x84];
};

class PDATarget : public OtherBase, public UIDialog {
};

class CBFunctorBase {
public:
    void (UIDialog::*m_pmf)();
    PDATarget* m_obj;
};

void cbmt_thunk_803BC568(CBFunctorBase& f) {
    PDATarget* obj = f.m_obj;
    (obj->*f.m_pmf)();
}
