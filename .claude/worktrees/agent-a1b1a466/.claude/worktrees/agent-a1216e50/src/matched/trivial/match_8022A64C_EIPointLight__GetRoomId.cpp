// 0x8022A64C (8 bytes)
class EIPointLight {
public:
    int GetRoomId();
};

int EIPointLight::GetRoomId() {
    return *(int*)((char*)this + 0xC0);
}
