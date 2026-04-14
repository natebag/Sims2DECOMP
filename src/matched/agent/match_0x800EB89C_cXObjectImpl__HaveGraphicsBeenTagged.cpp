// 0x800EB89C cXObjectImpl::HaveGraphicsBeenTagged(void) (40B)
struct cXObjectImpl {
    char pad[232];
    int m_tagFlag;
};

int cXObjectImpl__HaveGraphicsBeenTagged(cXObjectImpl* self) {
    if (self->m_tagFlag != 0) {
        self->m_tagFlag = 0;
        return 1;
    }
    return 0;
}
