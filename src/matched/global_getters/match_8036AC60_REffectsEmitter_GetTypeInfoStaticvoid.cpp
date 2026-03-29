// 0x8036AC60 (12 bytes)
class REffectsEmitter {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __REffectsEmitter_TypeInfo;

struct TypeInfo* REffectsEmitter::GetTypeInfoStatic() const {
    return &__REffectsEmitter_TypeInfo;
}
