// 0x803680C8 (12 bytes)
class ERAnim {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gERAnimData[];

unsigned short ERAnim::GetReadVersion() const {
    return gERAnimData[1];
}
