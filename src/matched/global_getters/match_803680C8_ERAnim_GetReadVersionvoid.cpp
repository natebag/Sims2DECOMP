// 0x803680C8 (12 bytes)
class ERAnim {
public:
    short GetReadVersion() const;
};

extern char gERAnimData[];

short ERAnim::GetReadVersion() const {
    return *(short*)(gERAnimData + 0);
}
