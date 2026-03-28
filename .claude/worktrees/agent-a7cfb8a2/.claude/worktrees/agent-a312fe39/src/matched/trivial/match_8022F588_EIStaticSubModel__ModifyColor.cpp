// 0x8022F588 (8 bytes)
class EIStaticSubModel {
public:
    void ModifyColor(int p);
};

void EIStaticSubModel::ModifyColor(int p) {
    *(int*)((char*)this + 0x94) = p;
}
