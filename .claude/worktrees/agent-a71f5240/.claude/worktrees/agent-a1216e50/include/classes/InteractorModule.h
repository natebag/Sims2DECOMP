#ifndef INTERACTORMODULE_H
#define INTERACTORMODULE_H

#include "types.h"

// InteractorModule - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60C (1548 bytes)
// 98 known fields (7 named), 90 methods

class InteractorModule {
public:
    // Methods
    void Debug_GetNameFromCommand(InteractorModule::InteractorInputManager::InteractorCommand);  // 0x805B6D34 (408B)
    /* ? */ GetPersonPosition(EVec3 *, cXPerson *, bool, bool);  // 0x805CC368 (668B)
    void InitializeInteractorModule(void);  // 0x805CC1B4 (328B)
    void ShutdownInteractorModule(void);  // 0x805CC2FC (108B)
    /* ? */ GetPlumbBob(int);  // 0x805CE434 (84B)
    bool IsCameraDirectorInControl(int);  // 0x805D2050 (152B)
    void RecomputeLightingGrid(cXObject *);  // 0x805CF8F0 (168B)
    bool IsPosOutsideWorld(EVec3 &);  // 0x805CD4D4 (436B)
    /* ? */ GetCameraRelativeStickAngle(EVec2 &, ESimsCam *, float *);  // 0x805CC850 (532B)
    void AllPlayersActiveInputInteractors(int);  // 0x805CE488 (376B)
    void CheckNewSimInSocialMode(unsigned int);  // 0x805D2418 (804B)
    void SetCameraFilter(int);  // 0x805D20E8 (184B)
    void ClampPosToWorld(EVec3 &);  // 0x805CD2AC (552B)
    void ClearCameraFilter(int);  // 0x805D21A0 (168B)
    void MoveCursorOneTileAlongCameraTargetVector(EVec3 &, EVec2 &, ESimsCam *, InteractorModule::IMSnapType);  // 0x805CCF10 (924B)
    void MoveCursorAlongCameraTargetVector(EVec3 &, EVec2 &, ESimsCam *, float);  // 0x805CCA64 (1196B)
    void SnapPositionToTile(EVec3 &, EVec3 &, InteractorModule::IMSnapType);  // 0x805CC6DC (372B)
    /* ? */ GetObjectPosition(EVec3 *, cXObject *);  // 0x805CC604 (216B)
    /* ? */ GetSnapPos(int &, int &, EVec3 &);  // 0x805CD688 (604B)
    /* ? */ GetSnapPosWithOffset(EVec3 &);  // 0x805CD8E4 (224B)
    void CreateObjectFromSelector(ObjSelector *);  // 0x805CD9C4 (324B)
    void CreateObjectFromGUID(unsigned int);  // 0x805CDB08 (380B)
    void DestroyObject(cXObject *);  // 0x805CDC84 (316B)
    bool CanObjectBeDestroyed(cXObject *);  // 0x805CDDC0 (728B)
    /* ? */ GetCursorIntersectionObjects(vector<short, allocator<short> > &, int);  // 0x805CE098 (476B)
    /* ? */ GetObjectFromInt16(short);  // 0x805CE274 (156B)
    /* ? */ GetLeadObjectImpl(cXObject *);  // 0x805CE310 (292B)
    bool IsObjectInRange(cXObject *);  // 0x805CE600 (480B)
    bool IsLegalToPlaceAtLocation(cXObject *, FTilePt &, InteractorModule::PlacementData *);  // 0x805CF220 (476B)
    void FinalUserPlaceObject(cXObject *);  // 0x805CF3FC (780B)
    void ShadeModelToShowValidState(cXObjectImpl *, bool);  // 0x805D001C (1648B)
    void UpdateAllObjectsInWorldAfterFirstPickupOrFinalPlace(cXObject *);  // 0x805CF708 (488B)
    void SetDirection(int, cXObject *);  // 0x805CF998 (868B)
    /* ? */ GetObjectInstancesList(cXObject *, TNodeList<ISimInstance *> &);  // 0x805CFCFC (800B)
    /* ? */ GetVisibleSideOfWall(ESimsCam *, EVec3 &, EVec3 &, EVec3 *);  // 0x805D068C (1024B)
    void ConvertVertsToTiles(EVec3 &, EVec3 &, CTilePt &, CTilePt &);  // 0x805D0A8C (2152B)
    /* ? */ GetAdjacentTileCoordinates(TilePtDir, int, EVec3 &);  // 0x805D12F4 (904B)
    /* ? */ GetRoomIdFromPoint(CTilePt &);  // 0x805D167C (900B)
    void ForcePointDir(CTilePt &, CTilePt &);  // 0x805D1A00 (1036B)
    void EorGetAdjacentTile(TileWallsSegment &, int, DiagonalSideSelector &, CTilePt &, CTilePt &);  // 0x805D1E0C (492B)
    /* ? */ GetInteractorResourceSet(InteractorModule::Interactor *);  // 0x805D1FF8 (88B)
    void IncrementSellCountForPattern(int, vector<InteractorModule::PatternSellCount, allocator<InteractorModule::PatternSellCount> > &);  // 0x805D2248 (236B)
    void IncrementSellCountForObjectGuid(int, vector<InteractorModule::InvStock, allocator<InteractorModule::InvStock> > &);  // 0x805D2334 (228B)
    void CoreIsLegalToPlace(cXObject *, FTilePt &, int &);  // 0x80364EA0 (288B)
    bool IsLegalToPlaceMultiTileAtLocation(cXObject *, FTilePt &);  // 0x80364FC0 (176B)
    bool IsLegalToPlaceSingleTileAtLocation(cXObject *, FTilePt &, InteractorModule::PlacementData *);  // 0x80365070 (1204B)
    void WMNullFunc(...);  // 0x803836BC (4B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_visibleSideOfWall;  // 0x000 [R/W] (CanObjectBeDestroyed, ClampPosToWorld, ConvertVertsToTiles, ...)
    u32 m_field_002;  // 0x002 [R/W] (PlacementObject::CreateGridTile)
    f32 m_bIsLegalToPlaceMultiTileAtLocation;  // 0x004 [R/W] (CanObjectBeDestroyed, CheckNewSimInSocialMode, ClampPosToWorld, ...)
    u8 m_field_007;  // 0x007 [R] (PlacementObject::Rotate)
    f32 m_objectPosition;  // 0x008 [R/W] (ConvertVertsToTiles, DirectInteractor::ExecuteActionMenu, DirectInteractor::InitPlayerPos, ...)
    f32 m_cursorIntersectionObjects;  // 0x00C [R/W] (DirectInteractor::OnCommandPressed, DirectInteractor::UpdateObjectHighlights, FloorPainter::CancelSession, ...)
    f32 m_field_010;  // 0x010 [R/W] (DirectInteractor::CancelQueuedActions, DirectInteractor::InitPlayerPos, DirectInteractor::OnCommandPressed, ...)
    f32 m_field_014;  // 0x014 [R/W] (FloorPainter::OnStart, Interactor::Moved, InteractorInputManager::InstanceData::CloseSession, ...)
    s16 m_field_016;  // 0x016 [R] (ObjectManipulator::Update)
    u8 m_field_017;  // 0x017 [R] (ObjectManipulator::Update)
    f32 m_objectInstancesList;  // 0x018 [R/W] (GetObjectInstancesList, InteractorInputManager::InstanceData::CloseSession, InteractorInputManager::InstanceData::OpenSession, ...)
    u32 m_field_01C;  // 0x01C [R/W] (InteractorInputManager::InstanceData::CloseSession, InteractorInputManager::InstanceData::OpenSession, InteractorInputManager::InstanceData::Update, ...)
    f32 m_field_020;  // 0x020 [R/W] (DirectInteractor::Update, FloorPainter::CurrentSelectionIsValid, FloorPainter::GetSelectedRectPoints, ...)
    f32 m_field_024;  // 0x024 [R/W] (FloorPainter::CurrentSelectionIsValid, FloorPainter::GetSelectedRectPoints, FloorPainter::PaintRoom, ...)
    u32 m_field_028;  // 0x028 [R/W] (InteractorResourceSet::AddTexture, InteractorResourceSet::ClearSet, InteractorResourceSet::GetTexture, ...)
    f32 m_field_02C;  // 0x02C [R/W] (DirectInteractor::InitPlayerPos, DirectInteractor::OnCommandPressed, DirectInteractor::ResetIdleTime, ...)
    f32 m_field_030;  // 0x030 [R/W] (DirectInteractor::ExecuteActionMenu, DirectInteractor::OnCommandPressed, DirectInteractor::OnCommandReleased, ...)
    f32 m_field_034;  // 0x034 [R/W] (DirectInteractor::InterpretFreeMoveInput, DirectInteractor::OnCommandReleased, DirectInteractor::ParseControls, ...)
    f32 m_field_038;  // 0x038 [R/W] (DirectInteractor::OnCommandReleased, DirectInteractor::ParseControls, FloorPainter::OnCommandReleased, ...)
    f32 m_field_03C;  // 0x03C [R/W] (DirectInteractor::OnCommandPressed, DirectInteractor::OnCommandReleased, DirectInteractor::ParseControls, ...)
    f32 m_field_040;  // 0x040 [R/W] (DirectInteractor::OnCommandReleased, DirectInteractor::ParseControls, FloorPainter::OnCommandReleased, ...)
    u32 m_field_044;  // 0x044 [R/W] (DirectInteractor::InterpretFreeMoveInput, DirectInteractor::ParseControls, Interactor::ResetInputState, ...)
    f32 m_field_048;  // 0x048 [R/W] (DirectInteractor::ParseControls, DirectInteractor::ShouldHighlightObject, Interactor::ResetInputState, ...)
    f32 m_field_04C;  // 0x04C [R/W] (DirectInteractor::ShouldHighlightObject, InteractorResourceSet::AddShader, InteractorResourceSet::ClearSet, ...)
    f32 m_field_050;  // 0x050 [W] (FloorPainter::OnCreate, InteractorVisualizer::DrawPreviewOnAffectedWalls, InteractorVisualizer::DrawWallpaperRectPreview, ...)
    f32 m_field_054;  // 0x054 [W] (FloorPainter::OnCreate, ObjectManipulator::OnStart, WallManipulator::OnCreate, ...)
    f32 m_field_058;  // 0x058 [R/W] (DirectInteractor::ResetIdleTime, DirectInteractor::Update)
    u32 m_field_05C;  // 0x05C [R/W] (DirectInteractor::DirectInteractor, DirectInteractor::ExecuteActionMenu, DirectInteractor::ExecuteObjectActionMenu, ...)
    f32 m_field_060;  // 0x060 [R/W] (FloorPainter::CurrentSelectionIsValid, FloorPainter::HandleActionCmdInPlaceMode, FloorPainter::HandleActionCmdInRemoveMode, ...)
    f32 m_field_064;  // 0x064 [R/W] (DirectInteractor::DirectInteractor, DirectInteractor::Update, DirectInteractor::UpdateControlStatus, ...)
    f32 m_field_068;  // 0x068 [R/W] (DirectInteractor::InitPlayerPos, DirectInteractor::OnStart, DirectInteractor::Update, ...)
    u32 m_field_06C;  // 0x06C [R/W] (DirectInteractor::OnCommandPressed, DirectInteractor::OnStart, DirectInteractor::Update, ...)
    f32 m_field_070;  // 0x070 [R/W] (DirectInteractor::CancelQueuedActions, DirectInteractor::DirectInteractor, DirectInteractor::ExecuteActionMenu, ...)
    f32 m_field_074;  // 0x074 [R/W] (DirectInteractor::DirectInteractor, DirectInteractor::ShouldHighlightObject, InteractorVisualizer::Draw, ...)
    u32 m_field_078;  // 0x078 [R/W] (DirectInteractor::DirectInteractor, DirectInteractor::InitPlayerPos, DirectInteractor::OnStart, ...)
    u32 m_field_07C;  // 0x07C [R/W] (DirectInteractor::DirectInteractor, DirectInteractor::InitPlayerPos, FloorPainter::CurrentSelectionIsValid, ...)
    u32 m_field_080;  // 0x080 [R/W] (DirectInteractor::DirectInteractor, DirectInteractor::ExecuteObjectActionMenu, DirectInteractor::ResetIdleTime, ...)
    f32 m_field_084;  // 0x084 [R/W] (FloorPainter::OnStart, WallPainter::AdjustCursorPosition, WallPainter::OnStart, ...)
    u32 m_field_088;  // 0x088 [R/W] (WallManipulator::CommittTransaction, WallManipulator::WallManipulator, WallManipulator::~WallManipulator, ...)
    u8 _pad_08C[4];  // 0x08C
    u32 m_field_090;  // 0x090 [R/W] (FloorPainter::OnStart, FloorPainter::~FloorPainter, WallPainter::CountWallsInRoomSelection, ...)
    u32 m_field_094;  // 0x094 [R/W] (FloorPainter::OnStart, FloorPainter::OnStop, WallPainter::CommittTransaction, ...)
    f32 m_field_098;  // 0x098 [R/W] (FloorPainter::CurrentSelectionIsValid, FloorPainter::OnCommandPressed, FloorPainter::PaintFloor, ...)
    u32 m_field_09C;  // 0x09C [R/W] (FloorPainter::OnCommandPressed, FloorPainter::OnStart, WallPainter::CommittTransaction, ...)
    f32 m_field_0A0;  // 0x0A0 [R/W] (FloorPainter::CancelSession, FloorPainter::HandleActionCmdInRemoveMode, FloorPainter::OnCommandPressed, ...)
    f32 m_field_0A4;  // 0x0A4 [R/W] (FloorPainter::CancelSession, FloorPainter::CurrentSelectionIsValid, FloorPainter::OnCommandPressed, ...)
    u32 m_field_0A8;  // 0x0A8 [R/W] (FloorPainter::FloorPainter, FloorPainter::Update, FloorPainter::~FloorPainter, ...)
    u32 m_field_0AC;  // 0x0AC [W] (GrabManipulator::GrabManipulator, InteractorManager::CreatePlayerInteractorSets, InteractorVisualizer::InteractorOrderTableCallback, ...)
    u32 m_field_0B0;  // 0x0B0 [W] (DirectInteractor::InterpretFreeMoveInput, DirectInteractor::OnCommandPressed, DirectInteractor::ResetIdleTime, ...)
    f32 m_field_0B4;  // 0x0B4 [R/W] (DirectInteractor::InterpretFreeMoveInput, DirectInteractor::SendNeutralFreeMoveInput, InteractorVisualizer::InteractorOrderTableCallback)
    f32 m_field_0B8;  // 0x0B8 [R/W] (DirectInteractor::SetVelocityModifiers, FloorPainter::FloorPainter, FloorPainter::HandleActionCmdInPlaceMode, ...)
    u32 m_field_0BC;  // 0x0BC [R/W] (GrabManipulator::OnStart, PlaceManipulator::StartPlacement, WallPainter::OnStart, ...)
    f32 m_field_0C0;  // 0x0C0 [R/W] (GrabManipulator::OnStart, InteractorVisualizer::Draw, InteractorVisualizer::DrawPreviewOnAffectedWalls, ...)
    f32 m_field_0C4;  // 0x0C4 [R/W] (GrabManipulator::OnStart, InteractorVisualizer::Draw, InteractorVisualizer::DrawPreviewOnAffectedWalls, ...)
    f32 m_field_0C8;  // 0x0C8 [R/W] (DirectInteractor::ExecuteActionMenu, GrabManipulator::GrabManipulator, GrabManipulator::OnStart, ...)
    s16 m_field_0CC;  // 0x0CC [R/W] (PlaceManipulator::StartPlacement, PlaceManipulator::TryPlacingCurrentObject, WallManipulator::ValidateWallSegment, ...)
    u8 _pad_0CE[2];  // 0x0CE
    u32 m_field_0D0;  // 0x0D0 [R/W] (PlaceManipulator::OnCommandPressed, WallManipulator::CheckForAffectedWalls, WallManipulator::CommittTransaction, ...)
    u32 m_field_0D4;  // 0x0D4 [R/W] (WallManipulator::AddWallAtTile, WallManipulator::CanChangeTileAdd, WallManipulator::HandleDeleteLine, ...)
    u32 m_field_0D8;  // 0x0D8 [W] (WallManipulator::OnStart)
    u32 m_field_0DC;  // 0x0DC [W] (WallManipulator::OnStart)
    u32 m_field_0E0;  // 0x0E0 [W] (WallManipulator::WallManipulator)
    u8 _pad_0E4[0xC];  // 0x0E4
    f32 m_field_0F0;  // 0x0F0 [R/W] (InteractorVisualizer::DrawPreviewOnAffectedWalls, InteractorVisualizer::DrawVerticalRect, InteractorVisualizer::DrawWallpaperPreviewOnAffectedWalls, ...)
    u32 m_field_0F4;  // 0x0F4 [R] (WallManipulator::OnStart, WallManipulator::OnStop)
    u32 m_field_0F8;  // 0x0F8 [R] (WallManipulator::OnStart)
    u32 m_field_0FC;  // 0x0FC [R] (WallManipulator::OnStart)
    u32 m_field_100;  // 0x100 [R] (WallManipulator::CommittTransaction, WallManipulator::OnStart)
    u32 m_field_104;  // 0x104 [R/W] (WallManipulator::CommittTransaction, WallManipulator::OnStart)
    u8 _pad_108[4];  // 0x108
    u32 m_field_10C;  // 0x10C [W] (InteractorVisualizer::Draw, InteractorVisualizer::DrawResource, InteractorVisualizer::DrawSimpleResourceSet, ...)
    f32 m_field_110;  // 0x110 [W] (InteractorVisualizer::Draw, InteractorVisualizer::DrawPreviewOnAffectedWalls, InteractorVisualizer::DrawResource, ...)
    f32 m_field_114;  // 0x114 [W] (InteractorVisualizer::DrawPreviewOnAffectedWalls, InteractorVisualizer::DrawWallpaperRectPreview)
    u8 _pad_118[8];  // 0x118
    u32 m_field_120;  // 0x120 [R] (InteractorVisualizer::Draw)
    u8 _pad_124[0x3C];  // 0x124
    u32 m_field_160;  // 0x160 [R] (DirectInteractor::OnCommandPressed, SimInteractor::OnCommandPressed)
    u8 _pad_164[0x18];  // 0x164
    u32 m_field_17C;  // 0x17C [R/W] (SimInteractor::OnStart, SimInteractor::SimInteractor, SimInteractor::Update)
    f32 m_field_180;  // 0x180 [R/W] (SimInteractor::GetBeamScale, SimInteractor::OnStart, SimInteractor::SimInteractor, ...)
    f32 m_field_184;  // 0x184 [W] (SimInteractor::SimInteractor, SimInteractor::Update)
    u32 m_field_188;  // 0x188 [R/W] (SimInteractor::OnCommandPressed, SimInteractor::OnCommandReleased, SimInteractor::OnStart, ...)
    u32 m_field_18C;  // 0x18C [W] (SimInteractor::ImmediatelyCutCursorAndCameraToPos, SimInteractor::SimInteractor)
    u32 m_field_190;  // 0x190 [R/W] (SimInteractor::ReturnPlumbBobToOwner, SimInteractor::SimInteractor)
    u32 m_field_194;  // 0x194 [R/W] (SimInteractor::OnStart, SimInteractor::Update)
    u32 m_field_198;  // 0x198 [W] (SimInteractor::OnStart)
    u32 m_field_19C;  // 0x19C [R/W] (SimInteractor::OnStart, SimInteractor::OnStop, SimInteractor::ReturnPlumbBobToOwner, ...)
    u8 _pad_1A0[0x30];  // 0x1A0
    f32 m_field_1D0;  // 0x1D0 [R/W] (SimInteractor::SimInteractor, SimInteractor::UpdateOverlapIntersection)
    u8 _pad_1D4[4];  // 0x1D4
    f32 m_field_1D8;  // 0x1D8 [R/W] (SimInteractor::Update, SimInteractor::UpdateOverlapIntersection)
    f32 m_field_1DC;  // 0x1DC [R/W] (SimInteractor::SimInteractor, SimInteractor::UpdateOverlapIntersection)
    f32 m_field_1E0;  // 0x1E0 [W] (SimInteractor::SimInteractor, SimInteractor::UpdateOverlapIntersection)
    u8 _pad_1E4[8];  // 0x1E4
    f32 m_field_1EC;  // 0x1EC [R/W] (SimInteractor::SimInteractor, SimInteractor::UpdateOverlapIntersection)
    u8 _pad_1F0[8];  // 0x1F0
    f32 m_field_1F8;  // 0x1F8 [W] (SimInteractor::SimInteractor, SimInteractor::UpdateOverlapIntersection)
    u8 _pad_1FC[8];  // 0x1FC
    f32 m_field_204;  // 0x204 [W] (SimInteractor::SimInteractor)
    u8 _pad_208[0xC];  // 0x208
    u32 m_field_214;  // 0x214 [R/W] (SimInteractor::OnCommandReleased, SimInteractor::OnStart, SimInteractor::Update)
    u32 m_field_218;  // 0x218 [W] (SimInteractor::OnStart)
    u8 _pad_21C[8];  // 0x21C
    u32 m_field_224;  // 0x224 [W] (SimInteractor::OnStart, SimInteractor::SimInteractor, SimInteractor::UpdateOverlapIntersection)
    u32 m_field_228;  // 0x228 [W] (SimInteractor::OnStart, SimInteractor::SimInteractor)
    u8 _pad_22C[0xC];  // 0x22C
    u32 m_field_238;  // 0x238 [R] (DirectInteractor::OnCommandPressed, SimInteractor::OnCommandPressed)
    u8 _pad_23C[0xE4];  // 0x23C
    u32 m_field_320;  // 0x320 [R] (InteractorVisualizer::Draw)
    u8 _pad_324[0x8C];  // 0x324
    u32 m_field_3B0;  // 0x3B0 [W] (WallManipulator::CheckForAffectedWalls)
    u8 _pad_3B4[8];  // 0x3B4
    u32 m_field_3BC;  // 0x3BC [R] (WallManipulator::FinalizePlacement, WallManipulator::FinalizeRoom, WallPainter::FinalizePaperForRoom, ...)
    u8 _pad_3C0[0x58];  // 0x3C0
    f32 m_visibleSideOfWall_418;  // 0x418 [R] (GetCameraRelativeStickAngle, GetVisibleSideOfWall, InteractorVisualizer::DrawResource)
    u8 _pad_41C[0x20];  // 0x41C
    f32 m_visibleSideOfWall_43C;  // 0x43C [R] (FloorPainter::OnStart, GetCameraRelativeStickAngle, GetVisibleSideOfWall, ...)
    u8 _pad_440[0x1C8];  // 0x440
    f32 m_field_608;  // 0x608 [W] (DirectInteractor::InterpretFreeMoveInput, DirectInteractor::SendNeutralFreeMoveInput)
};

#endif // INTERACTORMODULE_H
