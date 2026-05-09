// 0x803ad714 (52B) int ReconLoadVector<SlotDescriptor>(vector<SlotDescriptor>&, iResFile*, int, short, int*)
// Thin wrapper: constructs ReconStreamVector<SlotDescriptor> on stack, forwards to ReconLoadObject.

struct iResFile;
struct SlotDescriptor;

template <typename T>
struct vector {
    char _pad[16];
};

template <typename T>
struct ReconStreamVector {
    vector<T>* m_vec;
    int m_count;
    ReconStreamVector(vector<T>* v, int n) : m_vec(v), m_count(n) {}
};

template <typename T>
int ReconLoadObject(T* obj, iResFile* file, int a, short b, int* c);

template <typename T>
int ReconLoadVector(vector<T>& vec, iResFile* file, int a, short b, int* c)
{
    ReconStreamVector<T> stream(&vec, a);
    return ReconLoadObject(&stream, file, a, b, c);
}

template int ReconLoadVector<SlotDescriptor>(vector<SlotDescriptor>&, iResFile*, int, short, int*);
