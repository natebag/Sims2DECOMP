// 0x8022F814 (12 bytes)
class EIStaticSubModel {
public:
    short GetReadVersion() const;
};

extern char gEIStaticSubModelData[];

short EIStaticSubModel::GetReadVersion() const {
    return *(short*)(gEIStaticSubModelData + 0);
}
