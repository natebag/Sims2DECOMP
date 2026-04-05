void SA2_AwareFn(void *, void *);

struct SA2_SAO {
    char _pad[0x620];
    int m_awareness;
    void SetAwareOfObject(void *obj);
};

void SA2_SAO::SetAwareOfObject(void *obj) {
    SA2_AwareFn(&m_awareness, obj);
}
