// WALL — 1-instruction order swap. ASM-PROCESSOR PERMUTER CANDIDATE.
// 0x80224048 InteractorModule::WallManipulator::GetAffectedWallHeight (24B)
// Session 12 Track C Manipulator pioneer pass — parked by OpusWorker.
//
// DOL order (target):
//   lwz r0,196(r3)
//   andi. r9,r0,256
//   lfs f1,-21092(r13)   ← andi BEFORE lfs
//   bnelr
//   lfs f1,-21096(r13)
//   blr
//
// GCC/SN output (5 forms tried):
//   lwz r0,196(r3)
//   lfs f1,0(0)           ← lfs BEFORE andi (RTL hoisting)
//   andi. r9,r0,256
//   bnelr
//   lfs f1,0(0)
//   blr
//
// Tried:
//   (a) if (flag) return tall; return short;
//   (b) int isTall = flag & bit; float v = tall; if (!isTall) v=short;
//   (c) if (flag & bit) { return tall; } return short;
//   (d) extern volatile float — same mismatch
//   (e) float v = tall; if (isTall) return v; v = short; return v;
//
// All forms: GCC RTL-level hoists lfs above andi regardless of
// -fno-schedule-insns[2] combinations.
//
// Fix candidate: asm-processor permuter (swap adjacent insns 1<->2).

extern float g_wallHeightTall;
extern float g_wallHeightShort;

struct WallManipulator {
    char pad_00[0xC4];
    int m_flags;
};

float InteractorModule_WallManipulator_GetAffectedWallHeight(WallManipulator* self) {
    int isTall = self->m_flags & 0x100;
    float v = g_wallHeightTall;
    if (isTall) return v;
    v = g_wallHeightShort;
    return v;
}
