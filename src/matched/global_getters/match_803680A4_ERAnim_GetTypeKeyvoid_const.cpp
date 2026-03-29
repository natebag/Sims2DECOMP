// 0x803680A4 (12 bytes)
class ERAnim {
public:
    const char* GetTypeKey() const;
};

extern char gERAnimData[];

const char* ERAnim::GetTypeKey() const {
    return *(const char**)(gERAnimData + 0);
}
