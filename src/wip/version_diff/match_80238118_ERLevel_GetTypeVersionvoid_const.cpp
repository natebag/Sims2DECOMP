// 0x80238118 (12 bytes)
class ERLevel {
public:
    short GetTypeVersion() const;
};

extern char gERLevelData[];

short ERLevel::GetTypeVersion() const {
    return *(short*)(gERLevelData + 0);
}
