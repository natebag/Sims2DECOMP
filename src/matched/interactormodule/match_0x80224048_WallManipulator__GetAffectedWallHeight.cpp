// 0x80224048 InteractorModule::WallManipulator::GetAffectedWallHeight (24B)
// S12 parked as "lfs-vs-andi RTL hoist scheduler wall".
// S13 Track I: cracked via asm-processor swap_adj pioneer (wall #1).
//
// Canonical class hierarchy + ASMPROC routing via verify_match.sh (S13 Blocker 2).
//
// ASMPROC_swap_adj: a=lfs b=andi. which=first

extern float g_wallHeightTall;
extern float g_wallHeightShort;

namespace InteractorModule {

struct WallManipulator {
    char pad_00[0xC4];
    int m_flags;
    float GetAffectedWallHeight();
};

float WallManipulator::GetAffectedWallHeight() {
    int isTall = this->m_flags & 0x100;
    float v = g_wallHeightTall;
    if (isTall) return v;
    v = g_wallHeightShort;
    return v;
}

}
