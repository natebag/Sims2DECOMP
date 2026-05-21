// 0x802D93F8 EA::Allocator::GeneralAllocator::SetFencepostAfterChunk(Chunk*, unsigned int) (32B)
//
// Sets allocator-fencepost markers at the end of a chunk: stores `size` at
// the chunk-end (the fencepost), then sets fields 4/8/12 of the NEXT chunk
// to {8, 8, 9} respectively.
//
// Recipe: volatile-on-last-3-stores + gpr_relabel 0:9 + 2x replace_insn
// to swap two li instructions on either side of the `add r3, r3, r4` that
// computes the next-chunk pointer.
//   - volatile-on-stores: enforces DOL's (12, 8, 4) store order.
//   - gpr_relabel 0:9: GCC chose r9/r0 for the 9 and 8 constants; DOL
//     chose r0/r9. Swap globally.
//   - 2x replace_insn: GCC emits `li r0, 9` BEFORE the add (then later
//     `li r9, 8`); DOL emits `li r9, 8` BEFORE the add (then later
//     `li r0, 9`). The two li's surround a non-li instruction (add), so
//     swap_adj cannot reach them directly. Use occurrence-indexed
//     replace_insn to rename the FIRST `li 0,9` to `li 9,8` and the
//     SECOND occurrence of `li 9,8` (which is now the trailing one)
//     back to `li 0,9`. Net effect: the two li's swap positions.
//
// ASMPROC_gpr_relabel: swap=0:9
// ASMPROC_replace_insn: match="li 0,9" replacement="li 9,8" occurrence=0
// ASMPROC_replace_insn: match="li 9,8" replacement="li 0,9" occurrence=1

namespace EA { namespace Allocator {

struct GeneralAllocator {
    struct Chunk {};
    static void SetFencepostAfterChunk(Chunk* chunk, unsigned int size);
};

void GeneralAllocator::SetFencepostAfterChunk(Chunk* chunk, unsigned int size) {
    *(unsigned int*)((char*)chunk + size) = size;
    chunk = (Chunk*)((char*)chunk + size);
    *(volatile unsigned int*)((char*)chunk + 12) = 9;
    *(volatile unsigned int*)((char*)chunk + 8) = 8;
    *(volatile unsigned int*)((char*)chunk + 4) = 8;
}

}}
