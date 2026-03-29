// 0x80368098 (12 bytes)
class ERAnim {
public:
    const char* GetTypeName() const;
};

extern char gERAnimData[];

const char* ERAnim::GetTypeName() const {
    return *(const char**)(gERAnimData + 0);
}
