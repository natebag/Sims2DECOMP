// 0x80364B3C (12 bytes)
class EFontData {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EFontData_TypeInfo;

struct TypeInfo* EFontData::GetTypeInfo() const {
    return &__EFontData_TypeInfo;
}
