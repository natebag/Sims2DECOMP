// 0x803680B0 (12 bytes)
class ERAnim {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gERAnimData[];

unsigned short ERAnim::GetTypeVersion() const {
    return gERAnimData[0];
}
