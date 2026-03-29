// 0x8022F7FC (12 bytes)
class EIStaticSubModel {
public:
    short GetTypeVersion() const;
};

extern char gEIStaticSubModelData[];

short EIStaticSubModel::GetTypeVersion() const {
    return *(short*)(gEIStaticSubModelData + 0);
}
