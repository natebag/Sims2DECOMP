// 0x803C9800 (12 bytes)
class EAnimNodeDataPos {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EAnimNodeDataPos_TypeInfo;

struct TypeInfo* EAnimNodeDataPos::GetTypeInfo() const {
    return &__EAnimNodeDataPos_TypeInfo;
}
