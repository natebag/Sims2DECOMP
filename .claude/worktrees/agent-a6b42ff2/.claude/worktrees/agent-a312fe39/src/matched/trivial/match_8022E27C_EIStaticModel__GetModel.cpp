// 0x8022E27C (8 bytes)
class EIStaticModel {
public:
    int GetModel();
};

int EIStaticModel::GetModel() {
    return *(int*)((char*)this + 0x120);
}
