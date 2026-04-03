// 0x800C9A8C (8 bytes)
class Neighbor {
public:
    int GetGUID();
};

int Neighbor::GetGUID() {
    return *(int*)((char*)this + 0x8);
}
