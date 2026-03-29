// 0x8036B160 (12 bytes)
class REffectsSequencer {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __REffectsSequencer_TypeInfo;

struct TypeInfo* REffectsSequencer::GetTypeInfo() const {
    return &__REffectsSequencer_TypeInfo;
}
