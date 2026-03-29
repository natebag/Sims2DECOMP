// 0x80238130 (12 bytes)
class ERLevel {
public:
    short GetReadVersion() const;
};

extern char gERLevelData[];

short ERLevel::GetReadVersion() const {
    return *(short*)(gERLevelData + 0);
}
