// 0x80367248 (12 bytes)
class ERAmbientScore {
public:
    short GetTypeVersion() const;
};

extern char gERAmbientScoreData[];

short ERAmbientScore::GetTypeVersion() const {
    return *(short*)(gERAmbientScoreData + 0);
}
