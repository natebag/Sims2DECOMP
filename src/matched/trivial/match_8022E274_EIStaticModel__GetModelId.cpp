// 0x8022E274 (8 bytes)
class EIStaticModel {
public:
    int GetModelId();
};

int EIStaticModel::GetModelId() {
    return *(int*)((char*)this + 0x110);
}
