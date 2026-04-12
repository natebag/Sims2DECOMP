// 0x80367248 (12 bytes)
class ERAmbientScore {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gERAmbientScoreData[];

unsigned short ERAmbientScore::GetTypeVersion() const {
    return gERAmbientScoreData[0];
}
