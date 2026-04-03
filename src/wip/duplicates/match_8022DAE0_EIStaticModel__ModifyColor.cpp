// 0x8022DAE0 (8 bytes)
class EIStaticModel {
public:
    void ModifyColor(int p);
};

void EIStaticModel::ModifyColor(int p) {
    *(int*)((char*)this + 0x114) = p;
}
