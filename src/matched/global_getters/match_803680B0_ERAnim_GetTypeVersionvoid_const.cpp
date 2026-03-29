// 0x803680B0 (12 bytes)
class ERAnim {
public:
    short GetTypeVersion() const;
};

extern char gERAnimData[];

short ERAnim::GetTypeVersion() const {
    return *(short*)(gERAnimData + 0);
}
