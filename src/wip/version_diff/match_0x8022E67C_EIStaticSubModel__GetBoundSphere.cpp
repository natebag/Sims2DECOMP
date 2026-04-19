/* EIStaticSubModel::GetBoundSphere(void) const at 0x8022E67C (SIZE_MATCH, BYTE_MISMATCH) */
/* VERSION_DIFF: SN ProDG base-pointer ABI gap — cannot match without inline asm.
 *
 * Same issue as EIStaticModel::GetBoundSphere (0x8022BB8C).
 * SN ProDG emits:
 *   addi r9, r3, 0x80       <- precomputes base ptr to m_bound (this+0x80)
 *   lfs  f0, 0(r9)          <- float copy via lfs
 *   ...
 *
 * GCC emits:
 *   lwz  r0, 0x80(r3)       <- direct this-relative loads with wrong float insns
 *   ...
 *
 * May crack via TU-level compilation or a future scheduler mutator.
 */

struct BoundSphere_EISSubModel {
    float x, y, z, r;
};

struct EIStaticSubModel_GBS {
    char _pad[0x80];
    BoundSphere_EISSubModel m_bound;
    BoundSphere_EISSubModel GetBoundSphere() const;
};

BoundSphere_EISSubModel EIStaticSubModel_GBS::GetBoundSphere() const {
    return m_bound;
}
