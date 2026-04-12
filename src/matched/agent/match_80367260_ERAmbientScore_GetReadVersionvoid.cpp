// 0x80367260 (12 bytes)
class ERAmbientScore {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gERAmbientScoreData[];

unsigned short ERAmbientScore::GetReadVersion() const {
    return gERAmbientScoreData[1];
}
