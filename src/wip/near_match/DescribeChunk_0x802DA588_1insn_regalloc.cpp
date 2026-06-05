// NEAR-MATCH (1 instruction): 0x802DA588 GeneralAllocator::DescribeChunk (352B)
// 87/88 instructions byte-identical. Sole gap: DOL preserves the flag word via 'mr r11,r0'
// (loads flags into r0); GCC from this clean source loads flags into r4 and needs no copy.
// Pure register-allocation coloring wall — see docs/tracking/walls.md. Re-test on a
// different SN point-version. Verify: bash tools/verify_match.sh --strict <file> 0x802DA588 352
//
namespace EA { namespace Allocator {
extern "C" void* memset(void* pDest, int c, ...);
extern "C" int SnprintfLocal(char* pDest, unsigned int n, const char* pFormat, ...);
struct GeneralAllocator {
    struct Chunk { unsigned int mPrevSize; unsigned int mnSize; };
    char mPad0[0x484];
    unsigned char mDescChar;
    unsigned int GetDataPreview(const void* pData, unsigned int nDataSize, char* pBuffer, wchar_t* pUnused, unsigned int nBufferLength) const;
    unsigned int DescribeChunk(Chunk* pChunk, char* pBuffer, unsigned int nSize);
};
unsigned int GeneralAllocator::DescribeChunk(Chunk* pChunk, char* pBuffer, unsigned int nSize) {
    char bufferA[257];
    char bufferB[514];
    unsigned int dataSize = (pChunk->mnSize & ~7u) - 8;
    char* pBufA = bufferA;
    char* pBufB = bufferB;
    memset(pBufA, 0, 257);
    memset(pBufB, 0, 514);
    void* pData = (char*)pChunk + 8;
    GetDataPreview(pData, dataSize, pBufA, (wchar_t*)pBufB, 256);
    int n = SnprintfLocal(pBuffer, nSize, "addr: 0x%08x%csize: %10u (%8x)%cdata: %s%c",
                          pData, mDescChar, dataSize, dataSize, mDescChar, pBufA, mDescChar);
    if (n > 0) {
        unsigned int flags = pChunk->mnSize;
        unsigned int isInternal = flags & 4;
        if (isInternal || (flags & 2)) {
            pBuffer += n; nSize -= n;
            const char* s1 = isInternal ? "internal" : "mapped";
            const char* s2 = (flags & 2) ? "fenced" : "mapped";
            int n2 = SnprintfLocal(pBuffer, nSize, "attr: %s %s%c", s1, s2, mDescChar);
            if (n2 > 0) n += n2;
        }
    }
    if (n > 0) return (unsigned int)n;
    return 0;
}
}}
