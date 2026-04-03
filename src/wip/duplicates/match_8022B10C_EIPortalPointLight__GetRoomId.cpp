// 0x8022B10C (8 bytes)
class EIPortalPointLight {
public:
    int GetRoomId();
};

int EIPortalPointLight::GetRoomId() {
    return *(int*)((char*)this + 0xC0);
}
