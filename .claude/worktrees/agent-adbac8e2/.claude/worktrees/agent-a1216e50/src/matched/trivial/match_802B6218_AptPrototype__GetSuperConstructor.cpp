// 0x802B6218 (8 bytes)
class AptPrototype {
public:
    int GetSuperConstructor();
};

int AptPrototype::GetSuperConstructor() {
    return *(int*)((char*)this + 0x20);
}
