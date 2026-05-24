// FLAGS: -fno-schedule-insns
// 0x8021F474 InteractorModule::SocialModeInteractor::GetSelectionRadius (12B)
struct FloatTriple { float x, y, z; };
extern FloatTriple kSocialModeInteractorRadius;

namespace InteractorModule {
struct SocialModeInteractor { float GetSelectionRadius() const; };
float SocialModeInteractor::GetSelectionRadius() const {
    return kSocialModeInteractorRadius.x;
}
}
