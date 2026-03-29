// 0x8036723C (12 bytes)
class ERAmbientScore {
public:
    const char* GetTypeKey() const;
};

extern char gERAmbientScoreData[];

const char* ERAmbientScore::GetTypeKey() const {
    return *(const char**)(gERAmbientScoreData + 0);
}
