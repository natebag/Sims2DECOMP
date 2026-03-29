// 0x80364B6C (12 bytes)
class EFontData {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EFontData_TypeInfo;

struct TypeInfo* EFontData::GetTypeInfoStatic() const {
    return &__EFontData_TypeInfo;
}
