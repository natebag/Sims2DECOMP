// 0x80367230 (12 bytes)
class ERAmbientScore {
public:
    const char* GetTypeName() const;
};

extern char gERAmbientScoreData[];

const char* ERAmbientScore::GetTypeName() const {
    return *(const char**)(gERAmbientScoreData + 0);
}
