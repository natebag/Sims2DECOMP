// 0x801108DC (8 bytes)
class ObjSelector {
public:
    int GetGUID();
};

int ObjSelector::GetGUID() {
    return *(int*)((char*)(*(int*)((char*)this + 0x38)) + 0x1C);
}
