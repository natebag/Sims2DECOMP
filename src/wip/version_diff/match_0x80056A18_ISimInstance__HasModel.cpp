/* ISimInstance::HasModel(void) at 0x80056A18 (24B) */
/* VERSION_DIFF: Branch prediction hint (y-bit) mismatch.
 * DOL uses BO=4 (bnelr, hint: unlikely) for the early-return-true branch.
 * SN ProDG generates BO=5 (bnelr, hint: likely). One bit differs (bit 21).
 * No C++ coding technique forces a specific y-bit value without inline asm.
 */

struct ISimInstance_HM {
    char _pad[288];
    int m_modelSlot;    // 0x120: non-zero when model exists
    int HasModel();
};

int ISimInstance_HM::HasModel() {
    register int val asm("r0") = m_modelSlot;
    register int ret asm("r3") = 1;
    if (val) return ret;
    return 0;
}
