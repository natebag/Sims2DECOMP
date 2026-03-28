// 0x800C90B4 (8 bytes)
class Neighbor {
public:
    int GetRelations();
};

int Neighbor::GetRelations() {
    return *(int*)((char*)this + 0x10);
}
