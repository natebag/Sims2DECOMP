// 0x802293A0 (12 bytes)
class EInstance {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EInstance_TypeInfo;

struct TypeInfo* EInstance::GetTypeInfo() const {
    return &__EInstance_TypeInfo;
}
