// 0x801B0750 (12 bytes)
class FAMTarget {
public:
    struct TypeInfo* UpdateText() const;
};

struct TypeInfo;
extern TypeInfo __FAMTarget_TypeInfo;

struct TypeInfo* FAMTarget::UpdateText() const {
    return &__FAMTarget_TypeInfo;
}
