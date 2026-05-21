// 0x8039F8E0 TArray<EILight*, TArrayDefaultAllocator>::CopyReverse(EILight**, EILight**, int) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_replace_insn: match="add 4,4,9" replacement="addi 5,5,-1"
// ASMPROC_replace_insn: match="addi 9,5,-1" replacement="add 4,4,9"
// ASMPROC_replace_insn: match="cmpwi 0,9,0" replacement="cmpwi 0,5,0"
// ASMPROC_replace_insn: match="addi 9,9,-1" replacement="addi 5,5,-1"

struct TArrayDefaultAllocator;

template <typename T, typename Alloc>
class TArray {
public:
    static void CopyReverse(T* dst, T* src, int count);
};

template <typename T, typename Alloc>
void TArray<T, Alloc>::CopyReverse(T* dst, T* src, int count) {
    int __offset = count;
    __offset = __offset * sizeof(T) - sizeof(T);
    src = (T*)((char*)src + __offset);
    dst = (T*)((char*)dst + __offset);
    int __count = count - 1;
    if (count == 0) return;
    do {
        int __tmp = *(int*)src;
        src = (T*)((char*)src - sizeof(T));
        *(int*)dst = __tmp;
        dst = (T*)((char*)dst - sizeof(T));
    } while (__count-- != 0);
}

template class TArray<void*, TArrayDefaultAllocator>;
