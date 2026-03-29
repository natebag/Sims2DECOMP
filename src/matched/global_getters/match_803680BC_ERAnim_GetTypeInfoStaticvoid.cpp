// 0x803680BC (12 bytes)
class ERAnim {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ERAnim_TypeInfo;

struct TypeInfo* ERAnim::GetTypeInfoStatic() const {
    return &__ERAnim_TypeInfo;
}
