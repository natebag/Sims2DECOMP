// 0x80367254 (12 bytes)
class ERAmbientScore {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ERAmbientScore_TypeInfo;

struct TypeInfo* ERAmbientScore::GetTypeInfoStatic() const {
    return &__ERAmbientScore_TypeInfo;
}
