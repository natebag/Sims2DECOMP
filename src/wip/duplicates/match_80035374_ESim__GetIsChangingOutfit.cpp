// 0x80035374 (8 bytes)
class ESim {
public:
    int GetIsChangingOutfit();
};

int ESim::GetIsChangingOutfit() {
    return *(int*)((char*)this + 0x3D8);
}
