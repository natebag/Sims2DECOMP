// 0x8031A628 (8 bytes)
class ERModel {
public:
    int GetNumMorphBases();
};

int ERModel::GetNumMorphBases() {
    return *(int*)((char*)this + 0x108);
}
