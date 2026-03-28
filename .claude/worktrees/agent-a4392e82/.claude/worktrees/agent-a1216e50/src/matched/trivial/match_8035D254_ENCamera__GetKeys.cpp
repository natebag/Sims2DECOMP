// 0x8035D254 (8 bytes)
class ENCamera {
public:
    int GetKeys();
};

int ENCamera::GetKeys() {
    return *(int*)((char*)this + 0x44);
}
