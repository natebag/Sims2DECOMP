class SomeBase {
public:
    void Update(void);
};

class INVTarget {
public:
    char pad[0x319C];
    SomeBase m_base;
    void Update(void);
};

void INVTarget::Update(void) {
    m_base.Update();
}
