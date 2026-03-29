// 0x80367260 (12 bytes)
class ERAmbientScore {
public:
    short GetReadVersion() const;
};

extern char gERAmbientScoreData[];

short ERAmbientScore::GetReadVersion() const {
    return *(short*)(gERAmbientScoreData + 0);
}
