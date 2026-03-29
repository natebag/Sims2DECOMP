// 0x800483F8 (12 bytes)
class EIFloor {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EIFloor_TypeInfo;

struct TypeInfo* EIFloor::GetTypeInfo() const {
    return &__EIFloor_TypeInfo;
}
