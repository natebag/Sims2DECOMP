void SB_Init(void *);

struct SB_Ctor {
    void *m_ptr;
    int m_size;

    SB_Ctor *ctor(void *ptr, int size);
};

SB_Ctor *SB_Ctor::ctor(void *ptr, int size) {
    m_ptr = ptr;
    m_size = size;
    SB_Init(this);
    return this;
}
