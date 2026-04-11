// FLAGS: -fno-schedule-insns
// Try: LoadGameTarget multiply inherits, UIDialog at offset 0x84

class UIDialog {
public:
    virtual void dummy();  // forces a vtable
};

class OtherBase {
public:
    char pad[0x84];  // 132 bytes of padding so UIDialog lands at offset 0x84
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
