// 0x8035D20C (8 bytes)
class ENCamera {
public:
    void SetID(int p);
};

void ENCamera::SetID(int p) {
    *(int*)((char*)this + 0x40) = p;
}
