// 0x80238130 (12 bytes)
class ERLevel {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gERLevelData[];

unsigned short ERLevel::GetReadVersion() const {
    return gERLevelData[1];
}
