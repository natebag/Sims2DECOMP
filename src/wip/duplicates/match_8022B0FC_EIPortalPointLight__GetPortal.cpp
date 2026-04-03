// 0x8022B0FC (8 bytes)
class EIPortalPointLight {
public:
    int GetPortal();
};

int EIPortalPointLight::GetPortal() {
    return *(int*)((char*)this + 0xD4);
}
