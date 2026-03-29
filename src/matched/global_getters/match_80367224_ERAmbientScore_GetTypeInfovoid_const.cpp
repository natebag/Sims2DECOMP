// 0x80367224 (12 bytes)
class ERAmbientScore {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ERAmbientScore_TypeInfo;

struct TypeInfo* ERAmbientScore::GetTypeInfo() const {
    return &__ERAmbientScore_TypeInfo;
}
