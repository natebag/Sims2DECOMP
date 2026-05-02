// 0x802FAC88 (76B) ESubModel::~ESubModel(void)
// Variant L: SI deleting-dtor, parent TArray destruct with flag=2 + clear m20.

void TArrayDtor(void* obj, int flag);
void __builtin_delete(void* p);

struct ESubModel {
    char pad_00_13[20];
    int m_field_20;
    void dtor(int flag);
};

void ESubModel::dtor(int flag) {
    m_field_20 = 0;
    TArrayDtor(this, 2);
    if (flag & 1) {
        __builtin_delete(this);
    }
}
