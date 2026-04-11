// 0x8001E6B8 CameraDirector::IsForceDisableHud (36B)
// DOL:
//   lwz r0, 364(r3)
//   li r3, 0                ; pre-set return (scheduled before cmpwi)
//   cmpwi r0, 1
//   bnelr                   ; return 0 if flags != 1
//   lis r9, hi(g_var)
//   lwz r0, lo(g_var)(r9)   ; non-SDA load (2 insns)
//   subfic r9, r0, 0        ; carry trick: r9 = -r0, ca = (r0 == 0)
//   adde r3, r9, r0         ; r3 = -r0 + r0 + ca = (r0 == 0)
//   blr

// Larger declaration to defeat -G 8 SDA threshold
extern int g_disableHudArr[16];

struct CameraDirector {
    char pad[364];
    int m_flags;          // offset 364
};

int CameraDirector_IsForceDisableHud(CameraDirector* this_) {
    if (this_->m_flags != 1) return 0;
    return g_disableHudArr[0] == 0;
}
