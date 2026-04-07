// FLAGS: -fno-schedule-insns
// CBMemberTranslator0<LoadGameTarget, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &) at 0x803B2AF4 (144 bytes)
// PMF ABI crack — 144B variant with multi-inheritance offset (UIDialog at +0x84)

class UIDialog {
public:
    virtual void dummy();
};

class OtherBase {
public:
    char pad[0x84];
};

class LoadGameTarget : public OtherBase, public UIDialog {
};

class CBFunctorBase {
public:
    void (UIDialog::*m_pmf)();
    LoadGameTarget* m_obj;
};

void cbmt_thunk_803B2AF4(CBFunctorBase& f) {
    LoadGameTarget* obj = f.m_obj;
    (obj->*f.m_pmf)();
}
