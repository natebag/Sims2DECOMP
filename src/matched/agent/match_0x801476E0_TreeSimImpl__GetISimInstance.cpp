// 0x801476E0 TreeSimImpl::GetISimInstance() (76B) — MI vcall via Tech #47

class ISimInstance;

class Sim {
public:
    virtual ~Sim() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0C() = 0;
    virtual ISimInstance* GetISimInstance() = 0;
};

class Container {
public:
    char pad[0x10];
    Sim* m_sim;
};

class TreeSimImpl {
public:
    Container* m_0;
    ISimInstance* GetISimInstance();
};

ISimInstance* TreeSimImpl::GetISimInstance() {
    Sim* s = m_0->m_sim;
    if (s != 0) return s->GetISimInstance();
    return 0;
}
