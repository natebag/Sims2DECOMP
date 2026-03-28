// 0x803A5208 (8 bytes)
class ObjSelector {
public:
    int GetSimDescription();
};

int ObjSelector::GetSimDescription() {
    return *(int*)((char*)this + 0x8C);
}
