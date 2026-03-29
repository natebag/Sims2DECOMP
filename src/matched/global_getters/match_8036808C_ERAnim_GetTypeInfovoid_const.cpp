// 0x8036808C (12 bytes)
class ERAnim {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ERAnim_TypeInfo;

struct TypeInfo* ERAnim::GetTypeInfo() const {
    return &__ERAnim_TypeInfo;
}
