// filter_wallpaper(WallTile *) - 0x801D4F88 (64B) — Tech #73 WALL
//
// SIZE: mine 56B vs DOL 64B (-2 instructions, 1 return block fewer).
//
// DOL emits THREE return blocks:
//   1. null-false inline @ 0x08-0x0C (li r3,0; blr)
//   2. global-true inline @ 0x20-0x24 (li r3,1; blr)
//   3. field-tail with bnelr @ 0x30-0x3C (li r3,1; cmpwi; bnelr; li r3,0; blr)
//
// Mine merges to TWO tail blocks (one false, one true). Tested 2 source variants:
//   v1: if (!wall) return false; if (_globals.m_f3c0) return true;
//       if (wall->m_field_10) return true; return false;
//   v2: if (wall == 0) ...; explicit != 0; local var for field load
//   → identical compiled bytes, identical mismatch.
//
// Conclusion: Tech #73 source-coax recipe is INSUFFICIENT for 3+ unequal-return
// patterns. GCC 2.95.3 tail-merges all `return false` returns regardless of
// source ordering or expression form. The DOL's split-tail layout requires
// either:
//   (a) Track-I instruction-emit mutator (anti_tail_merge directive), OR
//   (b) compile-time decision differing from clean GCC heuristic
//
// Tech #73 status: works for 2-return-path predicates (EBitArray::Get N=1,
// __cmpdi2 N=2). 3-path with mixed inline/bnelr layout is OUT OF SCOPE.
//
// MutatorSmith handoff: anti_tail_merge directive instance candidate.
// Suggested directive (untested):
//   ASMPROC_anti_tail_merge: tail_label=.L1 anchor_branch="bc 12,2,.L1"
//                            also_retarget="bc 12,1,.L2"
// where .L1 is the false-tail and .L2 is the true-tail. Would force inline
// FALSE block emission after each test rather than tail-merge.
//
// FLAGS: -msdata=eabi -G 8

struct WallTile {
    char pad_0[0x10];
    unsigned char m_field_10;
};

struct EGlobal_FW {
    char pad_0[0x3c0];
    int m_f3c0;
};

extern EGlobal_FW _globals;

bool filter_wallpaper(WallTile* wall) {
    if (!wall) return false;
    if (_globals.m_f3c0) return true;
    if (wall->m_field_10) return true;
    return false;
}
