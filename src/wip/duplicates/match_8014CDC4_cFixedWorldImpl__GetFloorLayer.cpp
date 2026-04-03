// 0x8014CDC4 (8 bytes)
class cFixedWorldImpl {
public:
    int GetFloorLayer();
};

int cFixedWorldImpl::GetFloorLayer() {
    return *(int*)((char*)this + 0x2C);
}
