struct TArrayDefaultAllocator;
struct ENLatticePoints;
struct EVec3;

extern void TArray_EVec3_dtor(void* p, int flags);

template <typename T, typename Alloc>
class TArray {
public:
    static void Destruct(T* __p, int __n);
};

template <>
void TArray<ENLatticePoints, TArrayDefaultAllocator>::Destruct(ENLatticePoints* __p, int __n) {
    int __count = __n - 1;
    if (__n != 0) {
        do {
            TArray_EVec3_dtor(__p, 2);
            __p = (ENLatticePoints*)((char*)__p + 12);
        } while (__count-- != 0);
    }
}
// FLAGS: -fno-schedule-insns
