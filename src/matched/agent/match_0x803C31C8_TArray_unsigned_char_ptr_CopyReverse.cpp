// TArray<unsigned char *, TArrayDefaultAllocator>::CopyReverse(unsigned char **, unsigned char **, int)
// Address: 0x803C31C8 | Size: 60 bytes

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

template class TArray<unsigned char*, TArrayDefaultAllocator>;
