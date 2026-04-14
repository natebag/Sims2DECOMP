// 0x8012953C cXPersonImpl::IsSelected (16B)

struct PersonInner_IS {
    char pad[0x84];
    int m_flags;
};

struct cXPersonImpl_IsSel {
    PersonInner_IS* m_inner;
    int IsSelected();
};

int cXPersonImpl_IsSel::IsSelected() {
    return (m_inner->m_flags >> 1) & 1;
}
