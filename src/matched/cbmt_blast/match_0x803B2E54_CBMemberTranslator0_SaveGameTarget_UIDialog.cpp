// FLAGS: -fno-schedule-insns
// CBMemberTranslator0<SaveGameTarget, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &) at 0x803B2E54 (144 bytes)
// PMF ABI crack — 144B variant with multi-inheritance offset (UIDialog at +0x84)

class UIDialog {
public:
    virtual void dummy();
};

class OtherBase {
public:
    char pad[0x84];
};

class SaveGameTarget : public OtherBase, public UIDialog {
};

class CBFunctorBase {
public:
    void (UIDialog::*m_pmf)();
    SaveGameTarget* m_obj;
};

void cbmt_thunk_803B2E54(CBFunctorBase& f) {
    SaveGameTarget* obj = f.m_obj;
    (obj->*f.m_pmf)();
}
