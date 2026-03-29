// 0x802277FC (12 bytes)
class EIGameInstance {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EIGameInstance_TypeInfo;

struct TypeInfo* EIGameInstance::GetTypeInfo() const {
    return &__EIGameInstance_TypeInfo;
}
