// 0x803ad7b4 (52B) int ReconSaveVector<SlotDescriptor>(vector<SlotDescriptor>&, iResFile*, int, short, int)
// Thin wrapper: constructs ReconStreamVector<SlotDescriptor> on stack, forwards to ReconSaveObject.
// Sibling-port from 0x803AD714 ReconLoadVector<SlotDescriptor>.

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
int ReconSaveObject(T* obj, iResFile* file, int a, short b, int c);

template <typename T>
int ReconSaveVector(vector<T>& vec, iResFile* file, int a, short b, int c)
{
    ReconStreamVector<T> stream(&vec, a);
    return ReconSaveObject(&stream, file, a, b, c);
}

template int ReconSaveVector<SlotDescriptor>(vector<SlotDescriptor>&, iResFile*, int, short, int);
