// 0x8012B754 cXPersonImpl::IsModelLoaded(void) (48B)
struct Leaf { char pad[1592]; int m_flag; };
struct L3 { char pad[20]; Leaf* m_leaf; };
struct L2 { L3* m_l3; };
struct Inner { L2* m_l2; };

struct cXPersonImpl {
    char pad[4];
    Inner* m_inner;
};

int cXPersonImpl__IsModelLoaded(cXPersonImpl* self) {
    Inner* i = self->m_inner;
    L2* l2 = i->m_l2;
    L3* l3 = l2->m_l3;
    Leaf* leaf = l3->m_leaf;
    int r = 1;
    if (leaf != 0 && leaf->m_flag != 0) return r;
    return 0;
}
