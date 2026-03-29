// 0x8022F7F0 (12 bytes)
class EIStaticSubModel {
public:
    const char* GetTypeKey() const;
};

extern char gEIStaticSubModelData[];

const char* EIStaticSubModel::GetTypeKey() const {
    return *(const char**)(gEIStaticSubModelData + 0);
}
