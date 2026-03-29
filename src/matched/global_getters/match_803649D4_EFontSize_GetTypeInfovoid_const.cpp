// 0x803649D4 (12 bytes)
class EFontSize {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EFontSize_TypeInfo;

struct TypeInfo* EFontSize::GetTypeInfo() const {
    return &__EFontSize_TypeInfo;
}
