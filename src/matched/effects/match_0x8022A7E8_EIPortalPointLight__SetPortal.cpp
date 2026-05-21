// 0x8022A7E8 EIPortalPointLight::SetPortal(EInstance*, bool) (60B)

struct EInstance {};

class EIPortalPointLight {
    char _pad0[0xd0];
    int m_field_d0;
    int m_field_d4;
public:
    void SetPortal(EInstance* portal, bool flag);
};

void EIPortalPointLight::SetPortal(EInstance* portal, bool flag) {
    m_field_d4 = (int)portal;
    m_field_d0 = (int)flag;
    char* vt = *(char**)this;
    short adj = *(short*)(vt + 0x58);
    int (*fn)(void*, EInstance*, bool) = *(int(**)(void*, EInstance*, bool))(vt + 0x5c);
    fn((char*)this + adj, portal, flag);
}
