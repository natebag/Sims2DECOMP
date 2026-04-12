// 0x80238118 (12 bytes)
class ERLevel {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gERLevelData[];

unsigned short ERLevel::GetTypeVersion() const {
    return gERLevelData[0];
}
