// 0x803adf2c (52B) SimpleReconObject<ReconStreamVector<SlotDescriptor>>::DoStream(ReconBuffer*, int)
// Forwards to DoContainerStream<vector<SlotDescriptor>, SlotDescriptor>.

struct ReconBuffer;
struct SlotDescriptor;

template <typename T> struct allocator;

template <typename T, typename A = allocator<T> >
struct vector {
    T* m_data;
    char _pad[12];
};

template <typename T>
struct ReconStreamVector {
    vector<T>* m_vec;
    int m_count;
};

template <typename T> struct SimpleReconObjectBase {
    virtual void _vtfiller() = 0;
};

template <typename T>
struct SimpleReconObject : public SimpleReconObjectBase<T> {
    virtual void _vtfiller() {}
    T* m_obj;
    void DoStream(ReconBuffer* buf, int n);
};

template <typename V, typename E>
void DoContainerStream(V& vec, E* data, ReconBuffer* buf, int n);

template <>
void SimpleReconObject<ReconStreamVector<SlotDescriptor> >::DoStream(ReconBuffer* buf, int n)
{
    ReconStreamVector<SlotDescriptor>* stream = m_obj;
    vector<SlotDescriptor>* vec = stream->m_vec;
    SlotDescriptor* data = vec->m_data;
    DoContainerStream(*vec, data, buf, n);
}
