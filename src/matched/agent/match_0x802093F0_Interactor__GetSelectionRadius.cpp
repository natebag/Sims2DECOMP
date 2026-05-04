// FLAGS: -fno-schedule-insns
// 0x802093F0 (100B) — InteractorModule::Interactor::GetSelectionRadius()
//
// Linear-interpolated selection radius based on camera zoom ratio. Returns
// k_radiusDefault when no camera is bound.
//
// Technique: non-SDA float constants via extern char[16] trick — sized > 8 to
// force the compiler to emit ADDR16_HA / ADDR16_LO relocations instead of
// EMB_SDA21 (which would collapse the lis+lfs pair into a single sda lfs).
// `-fno-schedule-insns` pins lis-pair order to (Inner, Outer) matching DOL.
//
// asm_processor: SN cc1plus picks r11 for the post-call k_radiusInner base
// (volatile reg). DOL reuses r30 (saved-set callee-saved already in stmw, dead
// after the bl GetCamera). Two force_reg renames target the lis+lfs pair on
// k_radiusInner, leaving k_radiusOuter's r9 untouched.
//
// ASMPROC_force_reg: match="lis 11,k_radiusInner@ha" from_reg=11 to_reg=30
// ASMPROC_force_reg: match="lfs 13,k_radiusInner@l(11)" from_reg=11 to_reg=30

class ESimsCam;

class CameraManager {
public:
    static CameraManager* GetSingleton();
    ESimsCam* GetCamera(int index);
};

class ESimsCam {
public:
    float GetCurZoomRatio();
};

extern char k_radiusInner[16];
extern char k_radiusOuter[16];
extern char k_radiusDefault[16];

namespace InteractorModule {
class Interactor {
public:
    int m_playerId;
    float GetSelectionRadius();
};
}

float InteractorModule::Interactor::GetSelectionRadius() {
    float result;
    ESimsCam* cam = CameraManager::GetSingleton()->GetCamera(m_playerId);
    if (cam == 0) {
        result = *(float*)k_radiusDefault;
    } else {
        float ratio = cam->GetCurZoomRatio();
        result = *(float*)k_radiusInner + ratio * (*(float*)k_radiusOuter - *(float*)k_radiusInner);
    }
    return result;
}
