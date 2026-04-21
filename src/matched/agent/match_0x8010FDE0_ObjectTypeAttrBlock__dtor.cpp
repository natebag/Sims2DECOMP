// 0x8010FDE0 ObjectTypeAttrBlock::~ObjectTypeAttrBlock (76B)
// dtor: if (m_field8) __builtin_vec_delete(m_field8); delete-flag check.

struct ObjectTypeAttrBlock {
    char pad[8];
    int* m_field8;
    ~ObjectTypeAttrBlock();
};

ObjectTypeAttrBlock::~ObjectTypeAttrBlock() {
    delete[] m_field8;
}
