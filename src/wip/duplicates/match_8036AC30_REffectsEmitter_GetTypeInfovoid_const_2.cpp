// 0x8036AC30 (12 bytes)
class REffectsEmitter {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __REffectsEmitter_TypeInfo;

struct TypeInfo* REffectsEmitter::GetTypeInfo() const {
    return &__REffectsEmitter_TypeInfo;
}
