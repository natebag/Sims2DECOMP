// 0x801BE548 K2YTarget::IsModeValid(void) (36B)
//
// Range check: returns 1 if 2 <= gv_K2YTarget_GetModevoid <= 8, else 0.
//
// WALL CLASS: cror-canonicalize (m >= N idiom divergence) + branch organization.
//   SN ProDG emits the `(m >= 2)` test using the CR-bit OR idiom:
//     cmpwi cr7, m, 2;  cror cr7.so = cr7.eq | cr7.gt;  mfcr;  clrlwi rD, rD, 31
//   GCC canonicalizes `>= 2` to `> 1` and emits:
//     cmpwi cr7, m, 1;  mfcr;  rlwinm rD, rD, 30, 31, 31    (extract cr7.gt bit)
//   Net: DOL = 4 insns / 16B; GCC = 3 insns / 12B for that subblock.
//
// Source-coax fix (structural early-return): goto-shared-label pattern
//   forces GCC to pre-load `r = 0`, then emit `bgtlr` on the (m > 8) early
//   return — matching DOL's li-then-bgtlr layout.
//
// Recipe = 3 existing-mutator directives (no new mutator needed):
//   1. cmpwi 7,0,1 → cmpwi 7,0,2          (rewrite immediate to undo `>= N` canonicalization)
//   2. inject `cror 31,30,29` before mfcr (synthesize the cr.so = cr.eq|cr.gt fusion)
//   3. rlwinm 3,3,30,1 → rlwinm 3,3,0,1   (change SH from 30 to 0; same mask=bit31;
//                                          extracts cr7.so instead of cr7.gt — i.e. clrlwi 3,3,31)
//
// Parked by OpusWorker 2026-05-21 with diff_func.sh output. Resolved without
// authoring `cror_ge_canonicalize` mutator — the 3-directive recipe is the
// generic fix for this wall class.
//
// ASMPROC_replace_insn: match="cmpwi 7,0,1" replacement="cmpwi 7,0,2"
// ASMPROC_inject_before: before="mfcr" lines="cror 4*cr7+so,4*cr7+eq,4*cr7+gt"
// ASMPROC_replace_insn: match="rlwinm 3,3,30,1" replacement="rlwinm 3,3,0,1"

extern int gv_K2YTarget_GetModevoid;

int gf_K2YTarget_IsModeValidvoid() {
    int m = gv_K2YTarget_GetModevoid;
    int r = 0;
    if (m > 8) goto end;
    r = (m >= 2) ? 1 : 0;
end:
    return r;
}
