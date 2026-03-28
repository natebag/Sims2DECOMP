// 0x80086840 (8 bytes)
class UIObjectBase;

class Wrapper {
public:
    char pad[136];
    UIObjectBase *m_objectBase;

    void WrapperStartup(UIObjectBase *obj);
};

void Wrapper::WrapperStartup(UIObjectBase *obj) {
    m_objectBase = obj;
}
