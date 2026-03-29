// 0x80048428 (12 bytes)
class EIFloor {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EIFloor_TypeInfo;

struct TypeInfo* EIFloor::GetTypeInfoStatic() const {
    return &__EIFloor_TypeInfo;
}
