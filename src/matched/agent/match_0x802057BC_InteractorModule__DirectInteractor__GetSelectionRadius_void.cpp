// FLAGS: -fno-schedule-insns
// 0x802057BC InteractorModule::DirectInteractor::GetSelectionRadius (12B)
// Float in a 12-byte struct escapes -G 8 SDA limit -> forces lis+lfs
struct FloatTriple { float x, y, z; };
extern FloatTriple kDIRRadius;

namespace InteractorModule {
struct DirectInteractor { float GetSelectionRadius() const; };
float DirectInteractor::GetSelectionRadius() const {
    return kDIRRadius.x;
}
}
