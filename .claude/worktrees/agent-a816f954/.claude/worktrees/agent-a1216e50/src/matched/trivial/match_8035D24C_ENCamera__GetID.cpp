// 0x8035D24C (8 bytes)
class ENCamera {
public:
    int GetID();
};

int ENCamera::GetID() {
    return *(int*)((char*)this + 0x40);
}
