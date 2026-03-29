// 0x8022F7E4 (12 bytes)
class EIStaticSubModel {
public:
    const char* GetTypeName() const;
};

extern char gEIStaticSubModelData[];

const char* EIStaticSubModel::GetTypeName() const {
    return *(const char**)(gEIStaticSubModelData + 0);
}
