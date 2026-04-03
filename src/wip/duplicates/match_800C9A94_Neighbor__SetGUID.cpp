// 0x800C9A94 (8 bytes)
class Neighbor {
public:
    void SetGUID(int p);
};

void Neighbor::SetGUID(int p) {
    *(int*)((char*)this + 0x8) = p;
}
