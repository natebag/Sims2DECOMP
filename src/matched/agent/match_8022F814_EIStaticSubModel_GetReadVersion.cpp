// 0x8022F814 (12 bytes)
class EIStaticSubModel {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short EIStaticSubModel_readVersion[];

unsigned short EIStaticSubModel::GetReadVersion() const {
    return EIStaticSubModel_readVersion[0];
}
