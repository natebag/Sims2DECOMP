/* ChangeHouseLoadHouse::DatasetPendingAddRefAsync(void) at 0x8009018C (24B) */
/* VERSION_DIFF: Same bnelr y-bit prediction hint issue as HasModel.
 * DOL: BO=4 (unlikely), SN ProDG: BO=5 (likely). One bit differs.
 */

struct ChangeHouseLoadHouse_DPARA {
    char _pad[28];
    int m_asyncPending;  // 28: 0 = pending
    int DatasetPendingAddRefAsync();
};

int ChangeHouseLoadHouse_DPARA::DatasetPendingAddRefAsync() {
    register int val asm("r0") = m_asyncPending;
    register int ret asm("r3") = 1;
    if (val) return ret;
    return 0;
}
