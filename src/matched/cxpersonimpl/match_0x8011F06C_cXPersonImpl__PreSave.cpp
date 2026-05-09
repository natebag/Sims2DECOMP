// cXPersonImpl::PreSave(void) - 0x8011F06C (80B)

class cXObjectImpl {
public:
    virtual void PreSave();
};

class INotifier {
public:
    virtual void F0() = 0;
    virtual void F1() = 0;
    virtual void F2() = 0;
    virtual void F3() = 0;
    virtual void F4() = 0;
    virtual void F5() = 0;
    virtual void F6() = 0;
    virtual void F7() = 0;
    virtual void F8() = 0;
    virtual void F9() = 0;
    virtual void F10() = 0;
    virtual void F11() = 0;
    virtual void F12() = 0;
    virtual void F13() = 0;
    virtual void F14() = 0;
    virtual void F15() = 0;
    virtual void F16() = 0;
    virtual void F17() = 0;
    virtual void F18() = 0;
    virtual void F19() = 0;
    virtual void F20() = 0;
    virtual void F21() = 0;
    virtual void F22() = 0;
    virtual void F23() = 0;
    virtual void F24() = 0;
    virtual void F25() = 0;
    virtual void F26() = 0;
    virtual void F27() = 0;
    virtual void F28() = 0;
    virtual void Notify(void* arg) = 0;  // slot 29, vtable offset 240
};

extern INotifier* g_notifier;

struct cXPerson_PreSave {
    cXObjectImpl* m_base;  // offset 0
    void* m_arg;           // offset 4

    void PreSave();
};

void cXPerson_PreSave::PreSave() {
    m_base->cXObjectImpl::PreSave();
    g_notifier->Notify(m_arg);
}
