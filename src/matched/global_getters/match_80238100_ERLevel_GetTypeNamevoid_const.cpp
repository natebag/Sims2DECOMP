// 0x80238100 (12 bytes)
class ERLevel {
public:
    const char* GetTypeName() const;
};

extern char gERLevelData[];

const char* ERLevel::GetTypeName() const {
    return *(const char**)(gERLevelData + 0);
}
