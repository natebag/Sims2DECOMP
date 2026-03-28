extern void *gDogmaPool;
extern void *DOGMA_Allocate(void *, int);

struct AptValueVector {
    int m_capacity;
    int m_count;
    void *m_data;
    AptValueVector(int capacity);
};

AptValueVector::AptValueVector(int capacity)
{
    m_count = 0;
    m_capacity = capacity;
    m_data = DOGMA_Allocate(gDogmaPool, capacity << 2);
}
