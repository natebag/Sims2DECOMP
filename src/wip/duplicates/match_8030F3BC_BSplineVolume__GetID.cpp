// 0x8030F3BC (8 bytes)
class BSplineVolume {
public:
    int GetID();
};

int BSplineVolume::GetID() {
    return *(int*)((char*)this + 0x80);
}
