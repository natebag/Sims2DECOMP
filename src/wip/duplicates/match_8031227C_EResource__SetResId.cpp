// 0x8031227C (8 bytes)
class EResource {
public:
    void SetResId(int p);
};

void EResource::SetResId(int p) {
    *(int*)((char*)this + 0x8) = p;
}
