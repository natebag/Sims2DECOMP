// 0x8022782C (12 bytes)
class EIGameInstance {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EIGameInstance_TypeInfo;

struct TypeInfo* EIGameInstance::GetTypeInfoStatic() const {
    return &__EIGameInstance_TypeInfo;
}
