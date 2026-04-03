struct TArrayDefaultAllocator;
struct ENLatticePoints;
struct EVec3;

extern void TArray_EVec3_op_assign(void* dst, void* src);

template <typename T, typename Alloc>
class TArray {
public:
    static void Copy(T* __dst, T* __src, int __n);
};

template <>
void TArray<ENLatticePoints, TArrayDefaultAllocator>::Copy(ENLatticePoints* __dst, ENLatticePoints* __src, int __n) {
    int __count = __n - 1;
    if (__n != 0) {
        do {
            TArray_EVec3_op_assign(__dst, __src);
            __src = (ENLatticePoints*)((char*)__src + 12);
            __dst = (ENLatticePoints*)((char*)__dst + 12);
        } while (__count-- != 0);
    }
}
// FLAGS: -fno-schedule-insns
