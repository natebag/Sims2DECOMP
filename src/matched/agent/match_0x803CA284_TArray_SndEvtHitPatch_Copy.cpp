// FLAGS: -fno-schedule-insns
// 0x803ca284 (52B) TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>::Copy(SndEvtHitPatch*, SndEvtHitPatch*, int)

struct TArrayERSoundEventAllocator;
struct SndEvtHitPatch { int a, b; };

template <typename T, typename Alloc>
class TArray {
public:
    static void Copy(T* __dst, T* __src, int __n);
};

template <>
void TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>::Copy(SndEvtHitPatch* __dst, SndEvtHitPatch* __src, int __n) {
    register int __count asm("r11") = __n - 1;
    if (__n == 0) return;
    do {
        *__dst = *__src;
        __src = (SndEvtHitPatch*)((char*)__src + 8);
        __dst = (SndEvtHitPatch*)((char*)__dst + 8);
    } while (--__count != -1);
}
