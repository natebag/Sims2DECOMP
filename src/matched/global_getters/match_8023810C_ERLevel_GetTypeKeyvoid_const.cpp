// 0x8023810C (12 bytes)
class ERLevel {
public:
    const char* GetTypeKey() const;
};

extern char gERLevelData[];

const char* ERLevel::GetTypeKey() const {
    return *(const char**)(gERLevelData + 0);
}
