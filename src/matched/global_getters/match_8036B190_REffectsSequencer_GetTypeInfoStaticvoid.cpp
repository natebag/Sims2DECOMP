// 0x8036B190 (12 bytes)
class REffectsSequencer {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __REffectsSequencer_TypeInfo;

struct TypeInfo* REffectsSequencer::GetTypeInfoStatic() const {
    return &__REffectsSequencer_TypeInfo;
}
