// 0x8022F7FC (12 bytes)
class EIStaticSubModel {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EIStaticSubModel_typeInfo_version[];

unsigned short EIStaticSubModel::GetTypeVersion() const {
    return EIStaticSubModel_typeInfo_version[0];
}
