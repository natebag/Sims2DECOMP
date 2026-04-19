/* EIStaticModel::GetBoundSphere(void) const at 0x8022BB8C (SIZE_MATCH, BYTE_MISMATCH) */
/* VERSION_DIFF: SN ProDG base-pointer ABI gap — cannot match without inline asm.
 *
 * SN ProDG emits:
 *   addi r9, r3, 256        <- precomputes base ptr to m_bound (this+0x100)
 *   lwz  r0, 0(r9)          <- load m_bound.x via r9-relative
 *   lwz  r8, 4(r9)
 *   lfs  f0, 8(r9)          <- float copy via lfs/stfs
 *   ...
 *
 * GCC emits:
 *   lwz  r8, 256(r3)        <- direct this-relative loads
 *   lwz  r0, 260(r3)
 *   lwz  r9, 264(r3)        <- uses lwz for float fields (wrong: should be lfs)
 *   ...
 *
 * Two problems:
 * 1. SN precomputes addi rN, r3, offset for multi-member structs; GCC uses direct offsets.
 * 2. SN uses lfs/stfs for float copy; GCC struct copy generates lwz/stw.
 * Both are compiler backend ABI decisions, not expressible in portable C++.
 * May crack via TU-level compilation or a future scheduler mutator.
 */

struct BoundSphere_EISModel {
    float x, y, z, r;
};

struct EIStaticModel_GBS {
    char _pad[0x100];
    BoundSphere_EISModel m_bound;
    BoundSphere_EISModel GetBoundSphere() const;
};

BoundSphere_EISModel EIStaticModel_GBS::GetBoundSphere() const {
    return m_bound;
}
