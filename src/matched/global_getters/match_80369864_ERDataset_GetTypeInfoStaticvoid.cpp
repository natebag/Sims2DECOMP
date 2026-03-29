// 0x80369864 (12 bytes)
class ERDataset {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ERDataset_TypeInfo;

struct TypeInfo* ERDataset::GetTypeInfoStatic() const {
    return &__ERDataset_TypeInfo;
}
