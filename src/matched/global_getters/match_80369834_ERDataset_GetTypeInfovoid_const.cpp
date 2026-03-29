// 0x80369834 (12 bytes)
class ERDataset {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ERDataset_TypeInfo;

struct TypeInfo* ERDataset::GetTypeInfo() const {
    return &__ERDataset_TypeInfo;
}
