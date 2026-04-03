// 0x802293D0 (12 bytes)
class EInstance {
public:
    static struct TypeInfo* GetTypeInfoStatic();
};

struct TypeInfo;
extern TypeInfo __EInstance_TypeInfo;

struct TypeInfo* EInstance::GetTypeInfoStatic() {
    return &__EInstance_TypeInfo;
}
