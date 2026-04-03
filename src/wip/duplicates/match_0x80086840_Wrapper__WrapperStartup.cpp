struct UIObjectBase;

struct Wrapper {
    char pad[0x88];
    UIObjectBase *m_uiObject;

    void WrapperStartup(UIObjectBase *obj);
};

void Wrapper::WrapperStartup(UIObjectBase *obj) {
    m_uiObject = obj;
}
