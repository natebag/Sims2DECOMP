// Decompiled small functions (<=64 bytes) from:
// - wallmanipulator.obj (WallManipulator)
// - wallpainter.obj (WallPainter, WMNullFunc)
// - floorpainter.obj (FloorPainter)

#include "build_mode/wallmanipulator.h"

static const float s_floatZero = 0.0f;

// ============================================================================
// InteractorModule::WallManipulator (wallmanipulator.obj)
// ============================================================================

// 0x8021F808 - 52 bytes
// NON_MATCHING - calls GetVisualizer(), unregisters
void InteractorModule::WallManipulator::OnDestroy() {
}

// 0x8021FB80 - 36 bytes
// NON_MATCHING - calls internal SetState(3)
void InteractorModule::WallManipulator::CancelSession() {
}

// 0x80221394 - 44 bytes
// NON_MATCHING - calls external AdjustCursor with cursor/adjusted pos ptrs
void InteractorModule::WallManipulator::AdjustCursorPosition() {
}

// 0x80221B54 - 40 bytes
// Checks flags at +0xC4 for bit 7 (0x80) and bit 2 (0x04)
int InteractorModule::WallManipulator::GetTexGenMode() {
    u32 flags = *(u32*)((u8*)this + 0xC4);
    if (flags & 0x80) {
        if (!(flags & 0x04)) {
            return 0;
        }
        return 2;
    }
    return 0;
}

// 0x80221B7C - 44 bytes
// NON_MATCHING - swaps this/vis, calls external PreDraw
void InteractorModule::WallManipulator::PreDraw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x80221BA8 - 44 bytes
// NON_MATCHING - swaps this/vis, calls external Draw
void InteractorModule::WallManipulator::Draw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x80223F70 - 24 bytes
// Tests bit 0 of flags at +0xC4
int InteractorModule::WallManipulator::IsAnchored() {
    u32 flags = *(u32*)((u8*)this + 0xC4);
    if (!(flags & 0x01)) return 0;
    return 1;
}

// 0x80223F88 - 12 bytes: lwz r3,196(r3); rlwinm r3,r3,25,31,31; blr
int InteractorModule::WallManipulator::IsValidWallSegment() {
    u32 flags = *(u32*)((u8*)this + 0xC4);
    return (flags >> 7) & 1;
}

// 0x80223F94 - 12 bytes: lwz r3,196(r3); rlwinm r3,r3,28,31,31; blr
int InteractorModule::WallManipulator::IsRoomPreview() {
    u32 flags = *(u32*)((u8*)this + 0xC4);
    return (flags >> 4) & 1;
}

// 0x80223FA0 - 12 bytes: lwz r3,196(r3); rlwinm r3,r3,30,31,31; blr
int InteractorModule::WallManipulator::IsBuyMode() {
    u32 flags = *(u32*)((u8*)this + 0xC4);
    return (flags >> 2) & 1;
}

// 0x80223FAC - 12 bytes: lwz r3,196(r3); rlwinm r3,r3,29,31,31; blr
int InteractorModule::WallManipulator::IsSellMode() {
    u32 flags = *(u32*)((u8*)this + 0xC4);
    return (flags >> 3) & 1;
}

// 0x80223FB8 - 12 bytes: lwz r3,196(r3); rlwinm r3,r3,24,31,31; blr
int InteractorModule::WallManipulator::IsFenceMode() {
    u32 flags = *(u32*)((u8*)this + 0xC4);
    return (flags >> 8) & 1;
}

// 0x80223FC4 - 12 bytes: lwz r3,196(r3); rlwinm r3,r3,23,31,31; blr
int InteractorModule::WallManipulator::IsDestructMode() {
    u32 flags = *(u32*)((u8*)this + 0xC4);
    return (flags >> 9) & 1;
}

// 0x80223FD0 - 32 bytes
// Checks flag bit 8 (0x100), if set loads shader ID from indirect ptr
u32 InteractorModule::WallManipulator::GetFenceShaderID() {
    u32 flags = *(u32*)((u8*)this + 0xC4);
    if (flags & 0x100) {
        u32* ref = *(u32**)((u8*)this + 0xD8);
        return ref[0];
    }
    return 0;
}

// 0x80223FF0 - 32 bytes
// Stores EVec3 components into +0x60 as u32 triple
void InteractorModule::WallManipulator::SetAnchorPoint(EVec3& pos) {
    u32* dst = (u32*)((u8*)this + 0x60);
    u32* src = (u32*)&pos;
    dst[0] = src[0]; // x
    dst[2] = src[2]; // z
    dst[1] = src[1]; // y
}

// 0x80224010 - 32 bytes
// Stores EVec3 components into +0x6C as u32 triple
void InteractorModule::WallManipulator::SetAnchorPointDrawPos(EVec3& pos) {
    u32* dst = (u32*)((u8*)this + 0x6C);
    u32* src = (u32*)&pos;
    dst[0] = src[0];
    dst[2] = src[2];
    dst[1] = src[1];
}

// 0x80224030 - 8 bytes: addi r3, r3, 96; blr
EVec3* InteractorModule::WallManipulator::GetAnchorPos() {
    return (EVec3*)((u8*)this + 0x60);
}

// 0x80224038 - 8 bytes: addi r3, r3, 108; blr
EVec3* InteractorModule::WallManipulator::GetAnchorDrawPos() {
    return (EVec3*)((u8*)this + 0x6C);
}

// 0x80224040 - 8 bytes
// NON_MATCHING - loads float from SDA: lfs f1, -21100(r13); blr
f32 InteractorModule::WallManipulator::GetWallHeight() {
    return s_floatZero; // SDA ref
}

// 0x80224048 - 24 bytes
// NON_MATCHING - checks flag 0x100, loads different SDA floats
f32 InteractorModule::WallManipulator::GetAffectedWallHeight() {
    u32 flags = *(u32*)((u8*)this + 0xC4);
    (void)flags;
    return s_floatZero; // SDA ref conditional
}

// ============================================================================
// InteractorModule::WMNullFunc (wallpainter.obj)
// ============================================================================

// 0x80224060 - 4 bytes: blr
void InteractorModule::WMNullFunc(...) {
}

// ============================================================================
// InteractorModule::WallPainter (wallpainter.obj)
// ============================================================================

// 0x802241CC - 52 bytes
// NON_MATCHING - calls GetVisualizer(), unregisters
void InteractorModule::WallPainter::OnDestroy() {
}

// 0x8022448C - 60 bytes
// NON_MATCHING - calls external cleanup functions
void InteractorModule::WallPainter::OnStop() {
}

// 0x802244C8 - 36 bytes
// NON_MATCHING - calls internal SetState(3)
void InteractorModule::WallPainter::CancelSession() {
}

// 0x802256A4 - 44 bytes
// NON_MATCHING - swaps this/vis, calls external PreDraw
void InteractorModule::WallPainter::PreDraw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x802256D0 - 44 bytes
// NON_MATCHING - swaps this/vis, calls external Draw
void InteractorModule::WallPainter::Draw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x80226830 - 12 bytes: lwz r9,144(r3); lwz r3,8(r9); blr
u32 InteractorModule::WallPainter::GetShaderID() {
    u32* ref = *(u32**)((u8*)this + 0x90);
    return ref[2];
}

// 0x80226948 - 24 bytes
// Tests bit 0 of flags at +0x88
int InteractorModule::WallPainter::IsAnchored() {
    u32 flags = *(u32*)((u8*)this + 0x88);
    if (!(flags & 0x01)) return 0;
    return 1;
}

// 0x80226960 - 12 bytes: lwz r3,136(r3); rlwinm r3,r3,25,31,31; blr
int InteractorModule::WallPainter::IsValidWallSegment() {
    u32 flags = *(u32*)((u8*)this + 0x88);
    return (flags >> 7) & 1;
}

// 0x8022696C - 12 bytes: lwz r3,136(r3); rlwinm r3,r3,28,31,31; blr
int InteractorModule::WallPainter::IsRoomPreview() {
    u32 flags = *(u32*)((u8*)this + 0x88);
    return (flags >> 4) & 1;
}

// 0x80226978 - 12 bytes: lwz r3,136(r3); rlwinm r3,r3,30,31,31; blr
int InteractorModule::WallPainter::IsBuyMode() {
    u32 flags = *(u32*)((u8*)this + 0x88);
    return (flags >> 2) & 1;
}

// 0x80226984 - 12 bytes: lwz r3,136(r3); rlwinm r3,r3,29,31,31; blr
int InteractorModule::WallPainter::IsSellMode() {
    u32 flags = *(u32*)((u8*)this + 0x88);
    return (flags >> 3) & 1;
}

// 0x80226990 - 8 bytes: lfs f1, 132(r3); blr
f32 InteractorModule::WallPainter::GetCursorRotationAdjustment() {
    return *(f32*)((u8*)this + 0x84);
}

// 0x80226998 - 32 bytes
// Stores EVec3 components into +0x60 as u32 triple
void InteractorModule::WallPainter::SetAnchorPoint(EVec3& pos) {
    u32* dst = (u32*)((u8*)this + 0x60);
    u32* src = (u32*)&pos;
    dst[0] = src[0];
    dst[2] = src[2];
    dst[1] = src[1];
}

// 0x802269B8 - 32 bytes
void InteractorModule::WallPainter::SetAnchorPointDrawPos(EVec3& pos) {
    u32* dst = (u32*)((u8*)this + 0x6C);
    u32* src = (u32*)&pos;
    dst[0] = src[0];
    dst[2] = src[2];
    dst[1] = src[1];
}

// 0x802269D8 - 32 bytes
void InteractorModule::WallPainter::SetHoldPos(EVec3& pos) {
    u32* dst = (u32*)((u8*)this + 0x78);
    u32* src = (u32*)&pos;
    dst[0] = src[0];
    dst[2] = src[2];
    dst[1] = src[1];
}

// 0x802269F8 - 8 bytes: addi r3, r3, 96; blr
EVec3* InteractorModule::WallPainter::GetAnchorPos() {
    return (EVec3*)((u8*)this + 0x60);
}

// 0x80226A00 - 8 bytes: addi r3, r3, 108; blr
EVec3* InteractorModule::WallPainter::GetAnchorDrawPos() {
    return (EVec3*)((u8*)this + 0x6C);
}

// 0x80226A08 - 8 bytes: addi r3, r3, 120; blr
EVec3* InteractorModule::WallPainter::GetHoldPos() {
    return (EVec3*)((u8*)this + 0x78);
}

// 0x80226A10 - 8 bytes
// NON_MATCHING - loads float from SDA: lfs f1, -21084(r13); blr
f32 InteractorModule::WallPainter::GetPaperToolHeight() {
    return s_floatZero; // SDA ref
}

// 0x80226A18 - 8 bytes
// NON_MATCHING - loads float from SDA: lfs f1, -21080(r13); blr
f32 InteractorModule::WallPainter::GetWallHeight() {
    return s_floatZero; // SDA ref
}

// 0x80226A20 - 56 bytes
// Checks flag 0x1000, if not set copies pos to hold and sets flag
void InteractorModule::WallPainter::SaveInHoldPos(EVec3& pos) {
    u32 flags = *(u32*)((u8*)this + 0x88);
    if (flags & 0x1000) return;
    u32* dst = (u32*)((u8*)this + 0x78);
    u32* src = (u32*)&pos;
    dst[0] = src[0];
    dst[2] = src[2];
    dst[1] = src[1];
    *(u32*)((u8*)this + 0x88) = flags | 0x1000;
}

// ============================================================================
// InteractorModule::FloorPainter (floorpainter.obj)
// ============================================================================

// 0x802079B8 - 44 bytes
// NON_MATCHING - swaps this/vis, calls external PreDraw
void InteractorModule::FloorPainter::PreDraw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x802079E4 - 44 bytes
// NON_MATCHING - swaps this/vis, calls external Draw
void InteractorModule::FloorPainter::Draw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x8020913C - 12 bytes: lbz r3,96(r3); clrlwi r3,r3,31; blr
int InteractorModule::FloorPainter::IsInAnchorState() {
    u8 state = *(u8*)((u8*)this + 0x60);
    return state & 1;
}

// 0x80209148 - 16 bytes: lbz r3,96(r3); subfic r0,r3,0; adde r3,r0,r3; blr
// Returns 1 if state==0 (free), 0 otherwise
int InteractorModule::FloorPainter::IsInFreeState() {
    u8 state = *(u8*)((u8*)this + 0x60);
    return (state == 0) ? 1 : 0;
}

// 0x80209158 - 12 bytes: lbz r3,96(r3); rlwinm r3,r3,30,31,31; blr
int InteractorModule::FloorPainter::IsInBuildState() {
    u8 state = *(u8*)((u8*)this + 0x60);
    return (state >> 2) & 1;
}

// 0x80209164 - 12 bytes: lbz r3,96(r3); rlwinm r3,r3,29,31,31; blr
int InteractorModule::FloorPainter::IsInRemoveState() {
    u8 state = *(u8*)((u8*)this + 0x60);
    return (state >> 3) & 1;
}

// 0x80209170 - 12 bytes: lbz r3,96(r3); rlwinm r3,r3,31,31,31; blr
int InteractorModule::FloorPainter::IsInFillState() {
    u8 state = *(u8*)((u8*)this + 0x60);
    return (state >> 1) & 1;
}

// 0x8020917C - 12 bytes: lbz r3,96(r3); rlwinm r3,r3,28,31,31; blr
int InteractorModule::FloorPainter::IsInConfirmedState() {
    u8 state = *(u8*)((u8*)this + 0x60);
    return (state >> 4) & 1;
}

// 0x80209188 - 12 bytes: lbz r3,96(r3); rlwinm r3,r3,27,31,31; blr
int InteractorModule::FloorPainter::IsInInvalidState() {
    u8 state = *(u8*)((u8*)this + 0x60);
    return (state >> 5) & 1;
}

// 0x80209194 - 8 bytes: addi r3, r3, 100; blr
EVec3* InteractorModule::FloorPainter::GetAnchorPos() {
    return (EVec3*)((u8*)this + 0x64);
}

// 0x8020919C - 8 bytes: addi r3, r3, 148; blr
void* InteractorModule::FloorPainter::GetSelectedFloorData() {
    return (void*)((u8*)this + 0x94);
}

// 0x802091A4 - 8 bytes: lwz r3, 164(r3); blr
int InteractorModule::FloorPainter::IsInPlaceMode() {
    return *(u32*)((u8*)this + 0xA4);
}

// 0x802091AC - 16 bytes: lwz r3,164(r3); subfic r0,r3,0; adde r3,r0,r3; blr
// Returns 1 if IsInPlaceMode==0, 0 otherwise
int InteractorModule::FloorPainter::IsInRemoveMode() {
    u32 mode = *(u32*)((u8*)this + 0xA4);
    return (mode == 0) ? 1 : 0;
}

// ============================================================================
// WallPainter static initializers (NON_MATCHING)
// ============================================================================

// 0x80226914 - 52 bytes
// NON_MATCHING - __static_initialization_and_destruction_0 for wallpainter
// Writes float values to static data if __initialize_p == 1 && __priority == 0xFFFF
static void __static_initialization_and_destruction_0_wp(int __initialize_p, int __priority) {
    (void)__initialize_p; (void)__priority;
    // Stores initial float values (paper tool height * some multiplier) to SDA
}

// 0x80226ACC - 44 bytes
// NON_MATCHING - global constructors keyed to InteractorModule::WallPainter::m_paperToolHeight
// Calls __static_initialization_and_destruction_0 with args (1, 0xFFFF)
static void _GLOBAL__I_m_paperToolHeight() {
    // li r4, 0; li r3, 1; ori r4, r4, 0xFFFF
    // bl __static_initialization_and_destruction_0
}
