#ifndef WALLMANIPULATOR_H
#define WALLMANIPULATOR_H

#include "types.h"
#include "build_mode/interactor.h"

namespace InteractorModule {

// WallManipulator (from wallmanipulator.obj)
// Extends Interactor (0x60 bytes base)
class WallManipulator : public Interactor {
public:
    // +0x60 (96): anchor pos (EVec3)
    // +0x6C (108): anchor draw pos (EVec3)
    // ...gap...
    // +0xC4 (196): m_flags (bit field)
    // +0xD8 (216): m_fenceShaderRef pointer

    void OnDestroy();
    void CancelSession();
    void AdjustCursorPosition();
    int GetTexGenMode();
    void PreDraw(InteractorVisualizer& vis);
    void Draw(InteractorVisualizer& vis);
    int IsAnchored();
    int IsValidWallSegment();
    int IsRoomPreview();
    int IsBuyMode();
    int IsSellMode();
    int IsFenceMode();
    int IsDestructMode();
    u32 GetFenceShaderID();
    void SetAnchorPoint(EVec3& pos);
    void SetAnchorPointDrawPos(EVec3& pos);
    EVec3* GetAnchorPos();
    EVec3* GetAnchorDrawPos();
    f32 GetWallHeight();
    f32 GetAffectedWallHeight();
};

// WallPainter (from wallpainter.obj)
void WMNullFunc(...);

class WallPainter : public Interactor {
public:
    // +0x60 (96): anchor pos (EVec3)
    // +0x6C (108): anchor draw pos (EVec3)
    // +0x78 (120): hold pos (EVec3)
    // +0x84 (132): cursor rotation adjustment (f32)
    // +0x88 (136): m_flags
    // +0x90 (144): shader ref pointer
    // +0x9C (156): wall segment data

    static f32 m_paperToolHeight;

    void OnDestroy();
    void OnStop();
    void CancelSession();
    void PreDraw(InteractorVisualizer& vis);
    void Draw(InteractorVisualizer& vis);
    u32 GetShaderID();
    int IsAnchored();
    int IsValidWallSegment();
    int IsRoomPreview();
    int IsBuyMode();
    int IsSellMode();
    f32 GetCursorRotationAdjustment();
    void SetAnchorPoint(EVec3& pos);
    void SetAnchorPointDrawPos(EVec3& pos);
    void SetHoldPos(EVec3& pos);
    EVec3* GetAnchorPos();
    EVec3* GetAnchorDrawPos();
    EVec3* GetHoldPos();
    f32 GetPaperToolHeight();
    f32 GetWallHeight();
    void SaveInHoldPos(EVec3& pos);
};

// FloorPainter (from floorpainter.obj)
class FloorPainter : public Interactor {
public:
    // +0x60 (96): m_state (byte with bit flags)
    // +0x64 (100): anchor pos (EVec3)
    // +0x94 (148): selected floor data (pointer region)
    // +0xA4 (164): m_isPlaceMode (u32: 0=remove, nonzero=place)

    void PreDraw(InteractorVisualizer& vis);
    void Draw(InteractorVisualizer& vis);
    int IsInAnchorState();
    int IsInFreeState();
    int IsInBuildState();
    int IsInRemoveState();
    int IsInFillState();
    int IsInConfirmedState();
    int IsInInvalidState();
    EVec3* GetAnchorPos();
    void* GetSelectedFloorData();
    int IsInPlaceMode();
    int IsInRemoveMode();
};

} // namespace InteractorModule

#endif // WALLMANIPULATOR_H
