// asm-processor pioneer input: 0x80224048 WallManipulator::GetAffectedWallHeight (24B).
// The cc1plus scheduler hoists `lfs` above `andi.` (RTL level, survives -fno-schedule-insns[2]).
// Directive swaps the adj pair back into DOL order (andi. before lfs).
//
// ASMPROC_swap_adj: a=lfs b=andi. which=first

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
