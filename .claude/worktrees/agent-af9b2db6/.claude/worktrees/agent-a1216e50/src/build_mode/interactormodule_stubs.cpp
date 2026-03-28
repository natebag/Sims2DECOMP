// interactormodule_stubs.cpp - Stub implementations for Interactormodule
// Auto-generated from symbols.json - 310 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

// SKIP COMPILATION: InteractorModule is declared as namespace in interactor.h
// but as class in stub_classes.h. Needs reconciliation.
// For now, exclude from build to unblock linking.
#if 0
#include "types.h"
#include "stub_classes.h"

// 0x800F4544 | 52 bytes
InteractorModule::Interactor::InteractorParams::~InteractorParams(void) { }

// 0x8034E638 | 96 bytes
InteractorModule::DirectInteractor::DirectInteractor(void) { }

// 0x8034E698 | 52 bytes
InteractorModule::DirectInteractor::~DirectInteractor(void) { }

// 0x8034E734 | 688 bytes
void InteractorModule::DirectInteractor::OnStart(int *) { }

// 0x8034E9E4 | 136 bytes
void InteractorModule::DirectInteractor::OnStop(void) { }

// 0x8034EA6C | 112 bytes
void InteractorModule::DirectInteractor::ParseControls(void) { }

// 0x8034EADC | 152 bytes
void InteractorModule::DirectInteractor::GetDesiredAnimState(bool, EVec2) { }

// 0x8034EB74 | 536 bytes
void InteractorModule::DirectInteractor::InitPlayerPos(void) { }

// 0x8034ED8C | 276 bytes
void InteractorModule::DirectInteractor::UpdatePlumbBob(void) { }

// 0x8034EEA0 | 184 bytes
void InteractorModule::DirectInteractor::UpdateControlStatus(void) { }

// 0x8034EF58 | 92 bytes
void InteractorModule::DirectInteractor::SetVelocityModifiers(void) { }

// 0x8034EFB4 | 220 bytes
void InteractorModule::DirectInteractor::SendNeutralFreeMoveInput(void) { }

// 0x8034F090 | 316 bytes
void InteractorModule::DirectInteractor::InterpretFreeMoveInput(void) { }

// 0x8034F1CC | 948 bytes
void InteractorModule::DirectInteractor::Update(float) { }

// 0x8034F580 | 112 bytes
void InteractorModule::DirectInteractor::IsSimulatorPaused(void) { }

// 0x8034F5F0 | 652 bytes
void InteractorModule::DirectInteractor::ShouldHighlightObject(cXObject *, float) { }

// 0x8034F8DC | 156 bytes
void InteractorModule::DirectInteractor::CancelQueuedActions(void) { }

// 0x8034FA0C | 1644 bytes
void InteractorModule::DirectInteractor::OnCommandPressed(int, float) { }

// 0x80350078 | 112 bytes
void InteractorModule::DirectInteractor::OnCommandReleased(int) { }

// 0x80350168 | 924 bytes
void InteractorModule::DirectInteractor::ExecuteActionMenu(void) { }

// 0x80350504 | 516 bytes
void InteractorModule::DirectInteractor::ExecuteObjectActionMenu(cXObject *) { }

// 0x80350740 | 84 bytes
void InteractorModule::DirectInteractor::ChooseAction(Interaction *) { }

// 0x80350794 | 72 bytes
void InteractorModule::DirectInteractor::SetupCamera(void) { }

// 0x803507DC | 872 bytes
void InteractorModule::DirectInteractor::UpdateObjectHighlights(EIObjectMan *) { }

// 0x80350B84 | 212 bytes
void InteractorModule::DirectInteractor::ResetIdleTime(void) { }

// 0x8035227C | 76 bytes
void InteractorModule::DirectInteractor::CameraDirectorPermitsDirectControl(void) { }

// 0x803522C8 | 120 bytes
void InteractorModule::DirectInteractor::UpdateInteractorPos(void) { }

// 0x8035236C | 148 bytes
InteractorModule::FloorPainter::FloorPainter(void) { }

// 0x80352400 | 172 bytes
InteractorModule::FloorPainter::~FloorPainter(void) { }

// 0x803524AC | 116 bytes
void InteractorModule::FloorPainter::OnCreate(void) { }

// 0x80352520 | 76 bytes
void InteractorModule::FloorPainter::OnDestroy(void) { }

// 0x8035256C | 904 bytes
void InteractorModule::FloorPainter::OnStart(int *) { }

// 0x803528F4 | 240 bytes
void InteractorModule::FloorPainter::OnStop(void) { }

// 0x803529E4 | 84 bytes
void InteractorModule::FloorPainter::UpdateStickState(void) { }

// 0x80352A38 | 1576 bytes
void InteractorModule::FloorPainter::Update(float) { }

// 0x80353060 | 196 bytes
void InteractorModule::FloorPainter::SendBuildItemCountChangeEvent(int) { }

// 0x80353124 | 196 bytes
void InteractorModule::FloorPainter::SendSuccessEvent(int) { }

// 0x803531E8 | 632 bytes
void InteractorModule::FloorPainter::HandleActionCmdInRemoveMode(void) { }

// 0x80353460 | 612 bytes
void InteractorModule::FloorPainter::UpdateStockChanges(int *, int) { }

// 0x803536C4 | 696 bytes
void InteractorModule::FloorPainter::HandleActionCmdInPlaceMode(void) { }

// 0x8035397C | 1176 bytes
void InteractorModule::FloorPainter::OnCommandPressed(int, float) { }

// 0x80353E14 | 188 bytes
void InteractorModule::FloorPainter::OnCommandReleased(int) { }

// 0x80353ED0 | 76 bytes
void InteractorModule::FloorPainter::OnCommandUpdate(int, float) { }

// 0x80353F74 | 208 bytes
void InteractorModule::FloorPainter::IsValidFloorPlacement(CTilePt &, FloorPattern) { }

// 0x80354044 | 508 bytes
void InteractorModule::FloorPainter::SetFloorTile(CTilePt *, FloorPattern, int *) { }

// 0x803544B0 | 592 bytes
void InteractorModule::FloorPainter::RemoveFloorTile(CTilePt *, int *) { }

// 0x80354700 | 172 bytes
void InteractorModule::FloorPainter::GetSelectedRectPoints(int &, int &, int &, int &) { }

// 0x803547AC | 656 bytes
void InteractorModule::FloorPainter::PaintFloor(int *) { }

// 0x80354A3C | 724 bytes
void InteractorModule::FloorPainter::RemoveFloor(int *) { }

// 0x80354D10 | 804 bytes
void InteractorModule::FloorPainter::PaintRoom(int *) { }

// 0x80355034 | 836 bytes
void InteractorModule::FloorPainter::RemoveRoom(int *) { }

// 0x80355378 | 300 bytes
void InteractorModule::FloorPainter::CheckDiagForRoomContainment(Room *, CTilePt &, TileWalls &, DiagonalSideSelector &, DiagonalSideSelector &) { }

// 0x803554A4 | 192 bytes
void InteractorModule::FloorPainter::CancelSession(void) { }

// 0x80355564 | 248 bytes
void InteractorModule::FloorPainter::SwapTools(void) { }

// 0x8035565C | 624 bytes
void InteractorModule::FloorPainter::CurrentSelectionIsValid(int &) { }

// 0x803570D8 | 52 bytes
InteractorModule::Interactor::CallbackData::~CallbackData(void) { }

// 0x80357140 | 52 bytes
InteractorModule::FloorPainter::CallbackData::~CallbackData(void) { }

// 0x80357228 | 196 bytes
InteractorModule::Interactor::Interactor(void) { }

// 0x80357358 | 104 bytes
void InteractorModule::Interactor::OnCommandReleased(int) { }

// 0x803573C0 | 88 bytes
void InteractorModule::Interactor::OnCommandUpdate(int, float) { }

// 0x80357418 | 68 bytes
void InteractorModule::Interactor::ResetInputState(void) { }

// 0x8035745C | 100 bytes
void InteractorModule::Interactor::GetSelectionRadius(void) { }

// 0x80358670 | 52 bytes
InteractorModule::Interactor::~Interactor(void) { }

// 0x8035873C | 72 bytes
void InteractorModule::Interactor::Moved(void) { }

// 0x8035879C | 276 bytes
void InteractorModule::Debug_GetNameFromCommand(int) { }

// 0x803588B0 | 52 bytes
InteractorModule::InteractorInputManager::InstanceData::InstanceData(void) { }

// 0x803588E4 | 152 bytes
InteractorModule::InteractorInputManager::InstanceData::~InstanceData(void) { }

// 0x8035897C | 2260 bytes
void InteractorModule::InteractorInputManager::InstanceData::AddCommandMapping(int, ECTRL_CMD) { }

// 0x80359BB4 | 516 bytes
void InteractorModule::InteractorInputManager::InstanceData::OpenSession(int, int *, int, int *, int, int *, char *) { }

// 0x80359DB8 | 124 bytes
void InteractorModule::InteractorInputManager::InstanceData::CloseSession(void) { }

// 0x80359E34 | 8 bytes
void InteractorModule::InteractorInputManager::InstanceData::GetControllerFilterId(void) const { }

// 0x80359E3C | 900 bytes
void InteractorModule::InteractorInputManager::InstanceData::Update(float) { }

// 0x8035A1C0 | 184 bytes
InteractorModule::InteractorInputManager::InteractorInputManager(int) { }

// 0x8035A278 | 140 bytes
InteractorModule::InteractorInputManager::~InteractorInputManager(void) { }

// 0x8035A304 | 108 bytes
void InteractorModule::InteractorInputManager::Update(float) { }

// 0x8035A370 | 168 bytes
void InteractorModule::InteractorInputManager::OpenSession(int, int *, int, int *, int, int *, char *) { }

// 0x8035A418 | 44 bytes
void InteractorModule::InteractorInputManager::CloseSession(int) { }

// 0x8035A444 | 32 bytes
void InteractorModule::InteractorInputManager::GetSessionData(int) { }

// 0x8035A858 | 120 bytes
InteractorModule::InteractorManager::InteractorManager(void) { }

// 0x8035A8D0 | 408 bytes
InteractorModule::InteractorManager::~InteractorManager(void) { }

// 0x8035AA68 | 664 bytes
void InteractorModule::InteractorManager::Initialize(int &) { }

// 0x8035AD00 | 120 bytes
void InteractorModule::InteractorManager::Shutdown(void) { }

// 0x8035AD78 | 84 bytes
void InteractorModule::InteractorManager::Update(float) { }

// 0x8035ADCC | 136 bytes
void InteractorModule::InteractorManager::ChangeActiveInteractorToNull(int) { }

// 0x8035AE54 | 104 bytes
void InteractorModule::InteractorManager::GetPlayerInteractor(int, int) { }

// 0x8035AEBC | 72 bytes
void InteractorModule::InteractorManager::GetPlayerInteractorInfo(int) const { }

// 0x8035AF58 | 936 bytes
void InteractorModule::InteractorManager::CreatePlayerInteractorSets(void) { }

// 0x8035B300 | 876 bytes
void InteractorModule::InteractorManager::DestroyPlayerInteractorSets(void) { }

// 0x8035B6A4 | 880 bytes
void InteractorModule::InteractorManager::UpdateActivePlayerInteractors(float) { }

// 0x8035EA48 | 176 bytes
InteractorModule::InteractorResourceSet::InteractorResourceSet(void) { }

// 0x8035EAF8 | 520 bytes
InteractorModule::InteractorResourceSet::~InteractorResourceSet(void) { }

// 0x8035ED00 | 2444 bytes
void InteractorModule::InteractorResourceSet::AddModel(unsigned int) { }

// 0x8035F68C | 356 bytes
void InteractorModule::InteractorResourceSet::RemoveModel(unsigned int) { }

// 0x8035F7F0 | 2144 bytes
void InteractorModule::InteractorResourceSet::GetModel(unsigned int) { }

// 0x80360050 | 2452 bytes
void InteractorModule::InteractorResourceSet::AddShader(unsigned int) { }

// 0x803609E4 | 356 bytes
void InteractorModule::InteractorResourceSet::RemoveShader(unsigned int) { }

// 0x80360B48 | 2160 bytes
void InteractorModule::InteractorResourceSet::GetShader(unsigned int) { }

// 0x803613B8 | 2452 bytes
void InteractorModule::InteractorResourceSet::AddTexture(unsigned int) { }

// 0x80361D4C | 356 bytes
void InteractorModule::InteractorResourceSet::RemoveTexture(unsigned int) { }

// 0x80361EB0 | 2160 bytes
void InteractorModule::InteractorResourceSet::GetTexture(unsigned int) { }

// 0x80362720 | 384 bytes
void InteractorModule::InteractorResourceSet::ClearSet(void) { }

// 0x803628A0 | 788 bytes
void InteractorModule::InteractorResourceSet::AddOrderTableData(EOrderTableData &) { }

// 0x80362BB4 | 56 bytes
void InteractorModule::InteractorResourceSet::GetOrderTableData(unsigned int) { }

// 0x80362BEC | 32 bytes
void InteractorModule::InteractorResourceSet::GetOrderTableDataCount(void) { }

// 0x8036335C | 516 bytes
void InteractorModule::InitializeInteractorModule(void) { }

// 0x80363560 | 68 bytes
void InteractorModule::ShutdownInteractorModule(void) { }

// 0x803635A4 | 396 bytes
void InteractorModule::GetPersonPosition(EVec3 *, cXPerson *, bool, bool) { }

// 0x80363730 | 144 bytes
void InteractorModule::GetObjectPosition(EVec3 *, cXObject *) { }

// 0x803637C0 | 320 bytes
void InteractorModule::SnapPositionToTile(EVec3 &, EVec3 &, int) { }

// 0x80363900 | 376 bytes
void InteractorModule::GetCameraRelativeStickAngle(EVec2 &, ESimsCam *, float *) { }

// 0x80363A78 | 792 bytes
void InteractorModule::MoveCursorAlongCameraTargetVector(EVec3 &, EVec2 &, ESimsCam *, float) { }

// 0x80363D90 | 868 bytes
void InteractorModule::MoveCursorOneTileAlongCameraTargetVector(EVec3 &, EVec2 &, ESimsCam *, int) { }

// 0x803640F4 | 280 bytes
void InteractorModule::ClampPosToWorld(EVec3 &) { }

// 0x8036420C | 248 bytes
void InteractorModule::IsPosOutsideWorld(EVec3 &) { }

// 0x80364304 | 244 bytes
void InteractorModule::GetSnapPos(int &, int &, EVec3 &) { }

// 0x803643F8 | 176 bytes
void InteractorModule::GetSnapPosWithOffset(EVec3 &) { }

// 0x803644A8 | 220 bytes
void InteractorModule::CreateObjectFromSelector(ObjSelector *) { }

// 0x80364584 | 212 bytes
void InteractorModule::CreateObjectFromGUID(unsigned int) { }

// 0x80364658 | 184 bytes
void InteractorModule::DestroyObject(cXObject *) { }

// 0x80364710 | 372 bytes
void InteractorModule::CanObjectBeDestroyed(cXObject *) { }

// 0x80364884 | 660 bytes
void InteractorModule::GetCursorIntersectionObjects(vector<short, allocator<short> > &, int) { }

// 0x80364B18 | 88 bytes
void InteractorModule::GetObjectFromInt16(short) { }

// 0x80364B70 | 256 bytes
void InteractorModule::GetLeadObjectImpl(cXObject *) { }

// 0x80364C70 | 44 bytes
void InteractorModule::GetPlumbBob(int) { }

// 0x80364C9C | 212 bytes
void InteractorModule::AllPlayersActiveInputInteractors(int) { }

// 0x80364D70 | 304 bytes
void InteractorModule::IsObjectInRange(cXObject *) { }

// 0x80364EA0 | 288 bytes
void InteractorModule::CoreIsLegalToPlace(cXObject *, FTilePt &, int &) { }

// 0x80364FC0 | 176 bytes
void InteractorModule::IsLegalToPlaceMultiTileAtLocation(cXObject *, FTilePt &) { }

// 0x80365070 | 1204 bytes
void InteractorModule::IsLegalToPlaceSingleTileAtLocation(cXObject *, FTilePt &, int *) { }

// 0x80365524 | 280 bytes
void InteractorModule::IsLegalToPlaceAtLocation(cXObject *, FTilePt &, int *) { }

// 0x8036563C | 520 bytes
void InteractorModule::FinalUserPlaceObject(cXObject *) { }

// 0x80365844 | 324 bytes
void InteractorModule::UpdateAllObjectsInWorldAfterFirstPickupOrFinalPlace(cXObject *) { }

// 0x80365988 | 92 bytes
void InteractorModule::RecomputeLightingGrid(cXObject *) { }

// 0x803659E4 | 472 bytes
void InteractorModule::SetDirection(int, cXObject *) { }

// 0x80365BBC | 464 bytes
void InteractorModule::GetObjectInstancesList(cXObject *, TNodeList<ISimInstance *> &) { }

// 0x80365D8C | 920 bytes
void InteractorModule::ShadeModelToShowValidState(cXObjectImpl *, bool) { }

// 0x80366124 | 652 bytes
void InteractorModule::GetVisibleSideOfWall(ESimsCam *, EVec3 &, EVec3 &, EVec3 *) { }

// 0x803663B0 | 796 bytes
void InteractorModule::ConvertVertsToTiles(EVec3 &, EVec3 &, CTilePt &, CTilePt &) { }

// 0x803666CC | 524 bytes
void InteractorModule::GetAdjacentTileCoordinates(TilePtDir, int, EVec3 &) { }

// 0x803668D8 | 496 bytes
void InteractorModule::GetRoomIdFromPoint(CTilePt &) { }

// 0x80366AC8 | 692 bytes
void InteractorModule::ForcePointDir(CTilePt &, CTilePt &) { }

// 0x80366D7C | 320 bytes
void InteractorModule::EorGetAdjacentTile(TileWallsSegment &, int, DiagonalSideSelector &, CTilePt &, CTilePt &) { }

// 0x80366EBC | 52 bytes
void InteractorModule::GetInteractorResourceSet(int *) { }

// 0x80366EF0 | 76 bytes
void InteractorModule::IsCameraDirectorInControl(int) { }

// 0x80366F3C | 116 bytes
void InteractorModule::SetCameraFilter(int) { }

// 0x80366FB0 | 104 bytes
void InteractorModule::ClearCameraFilter(int) { }

// 0x80367018 | 540 bytes
void InteractorModule::IncrementSellCountForPattern(int, vector<int, allocator<int> > &) { }

// 0x80367234 | 540 bytes
void InteractorModule::IncrementSellCountForObjectGuid(int, vector<int, allocator<int> > &) { }

// 0x80367450 | 300 bytes
void InteractorModule::CheckNewSimInSocialMode(unsigned int) { }

// 0x80368D28 | 84 bytes
InteractorModule::InteractorVisualizer::InteractorVisualizer(void) { }

// 0x80368D7C | 148 bytes
InteractorModule::InteractorVisualizer::~InteractorVisualizer(void) { }

// 0x80368E10 | 224 bytes
void InteractorModule::InteractorVisualizer::Initialize(void) { }

// 0x80368EF0 | 68 bytes
void InteractorModule::InteractorVisualizer::Shutdown(void) { }

// 0x80368F34 | 400 bytes
void InteractorModule::InteractorVisualizer::CreateResources(int &) { }

// 0x803690C4 | 32 bytes
void InteractorModule::InteractorVisualizer::DestroyResources(int &) { }

// 0x803690E4 | 200 bytes
void InteractorModule::InteractorVisualizer::PreDraw(int &) { }

// 0x803691AC | 1936 bytes
void InteractorModule::InteractorVisualizer::Draw(int &) { }

// 0x8036993C | 800 bytes
void InteractorModule::InteractorVisualizer::DrawFloorRectPreview(ERC *, EVec3 &, EVec3 &) { }

// 0x80369C5C | 888 bytes
void InteractorModule::InteractorVisualizer::DrawFloorRoomPreview(ERC *, EVec3 &) { }

// 0x8036A464 | 608 bytes
void InteractorModule::InteractorVisualizer::DrawWallpaperRoomPreview(int &) { }

// 0x8036A6C4 | 628 bytes
void InteractorModule::InteractorVisualizer::DrawWallpaperPreviewOnAffectedWalls(int &) { }

// 0x8036AB0C | 1176 bytes
void InteractorModule::InteractorVisualizer::DrawWallpaperRectPreview(ERShader *, EVec2 &, EVec2 &, float) { }

// 0x8036B354 | 224 bytes
void InteractorModule::InteractorVisualizer::DrawWallRectPreview(int &) { }

// 0x8036B434 | 1324 bytes
void InteractorModule::InteractorVisualizer::DrawVerticalRect(ERShader *, EVec2 &, EVec2 &, float, int, float) { }

// 0x8036B960 | 596 bytes
void InteractorModule::InteractorVisualizer::DrawRoomPreview(int &) { }

// 0x8036BBB4 | 1612 bytes
void InteractorModule::InteractorVisualizer::DrawPreviewOnAffectedWalls(int &) { }

// 0x8036C930 | 140 bytes
void InteractorModule::InteractorVisualizer::InteractorOrderTableCallback(ELevelDrawData &, EOrderTableData *) { }

// 0x8036C9BC | 176 bytes
void InteractorModule::InteractorVisualizer::SetupDrawCallback(EHouse *, int) { }

// 0x8036CA6C | 80 bytes
void InteractorModule::InteractorVisualizer::CreateSimpleResourceSet(int &, int) { }

// 0x8036CABC | 272 bytes
void InteractorModule::InteractorVisualizer::DrawSimpleResourceSet(int &, int, EVec3 &, float) { }

// 0x8036CBCC | 292 bytes
void InteractorModule::InteractorVisualizer::SelectShader(int &, int) { }

// 0x8036D30C | 464 bytes
void InteractorModule::InteractorVisualizer::DrawResource(int &, int, EVec3 &, EMat4 *) { }

// 0x8036D4DC | 3544 bytes
void InteractorModule::InteractorVisualizer::CreateResourceSet(int &) { }

// 0x8036E2B4 | 180 bytes
void InteractorModule::InteractorVisualizer::AddModelToResourceSet(int &, int) { }

// 0x8036E368 | 184 bytes
void InteractorModule::InteractorVisualizer::AddOrderTableToResourceSet(int &, EOrderTableData &) { }

// 0x8036E420 | 416 bytes
void InteractorModule::InteractorVisualizer::DestroyResourceSet(int &) { }

// 0x8036E5C0 | 160 bytes
void InteractorModule::InteractorVisualizer::GetInteractorResourceSet(int *) { }

// 0x80371024 | 108 bytes
void InteractorModule::InteractorVisualizer::SetDefaultLights(void) { }

// 0x803710BC | 112 bytes
InteractorModule::ObjectManipulator::ObjectManipulator(void) { }

// 0x8037112C | 96 bytes
InteractorModule::ObjectManipulator::~ObjectManipulator(void) { }

// 0x803711F4 | 564 bytes
void InteractorModule::ObjectManipulator::OnStart(int *) { }

// 0x80371464 | 4 bytes
void InteractorModule::ObjectManipulator::OnCommandPressed(int, float) { }

// 0x80371468 | 184 bytes
void InteractorModule::PlaceManipulator::OnCommandPressed(int, float) { }

// 0x80371520 | 232 bytes
void InteractorModule::GrabManipulator::OnCommandPressed(int, float) { }

// 0x80371608 | 76 bytes
void InteractorModule::ObjectManipulator::OnCommandUpdate(int, float) { }

// 0x80371654 | 108 bytes
void InteractorModule::ObjectManipulator::OnCommandReleased(int) { }

// 0x80371718 | 2368 bytes
void InteractorModule::ObjectManipulator::Update(float) { }

// 0x80372058 | 732 bytes
void InteractorModule::ObjectManipulator::UpdateObjectHighlights(EIObjectMan *) { }

// 0x80372334 | 380 bytes
void InteractorModule::ObjectManipulator::UpdateOverlapIntersection(int *) { }

// 0x80372608 | 348 bytes
void InteractorModule::GrabManipulator::OnStart(int *) { }

// 0x80372824 | 332 bytes
void InteractorModule::PlaceManipulator::StartPlacement(int *) { }

// 0x80372970 | 388 bytes
void InteractorModule::GrabManipulator::TryGrabbingWorldObject(void) { }

// 0x80372AF4 | 236 bytes
void InteractorModule::GrabManipulator::TryGrabbingWorldObjectFromId(short) { }

// 0x80372BE0 | 88 bytes
void InteractorModule::GrabManipulator::DestroyObjectInHand(void) { }

// 0x80372C38 | 336 bytes
void InteractorModule::GrabManipulator::DropCurrentObject(void) { }

// 0x80372D88 | 512 bytes
void InteractorModule::GrabManipulator::TryRemoveCurrentObjectFromWorld(void) { }

// 0x80372F88 | 300 bytes
void InteractorModule::GrabManipulator::CancelCurrentGrab(void) { }

// 0x803730B4 | 276 bytes
void InteractorModule::GrabManipulator::CancelSession(void) { }

// 0x803731D0 | 348 bytes
void InteractorModule::PlaceManipulator::TryPlacingCurrentObject(void) { }

// 0x8037332C | 272 bytes
void InteractorModule::PlaceManipulator::CancelSession(void) { }

// 0x80373474 | 152 bytes
InteractorModule::PlacementObject::~PlacementObject(void) { }

// 0x8037350C | 316 bytes
void InteractorModule::PlacementObject::SetObjectColor(cXObject *, unsigned char) { }

// 0x80373648 | 356 bytes
void InteractorModule::PlacementObject::CreateNewPlacementObjectFromGuid(unsigned int, unsigned char) { }

// 0x803737AC | 276 bytes
void InteractorModule::PlacementObject::GrabExistingObjectInstanceFromId(short) { }

// 0x803738C0 | 1032 bytes
void InteractorModule::PlacementObject::CreateGridObject(FTilePt &, cXObject *) { }

// 0x80373CC8 | 2444 bytes
void InteractorModule::PlacementObject::CreateGridTile(ObjSelector *, cXMTObjectImpl *, cXObjectImpl *) { }

// 0x80374654 | 244 bytes
void InteractorModule::PlacementObject::DestroyGridObject(cXMTObjectImpl *&) { }

// 0x80374748 | 100 bytes
void InteractorModule::PlacementObject::InitializeGridObject(cXMTObjectImpl *) { }

// 0x803747AC | 268 bytes
void InteractorModule::PlacementObject::AssignOffsetsToGridObject(cXMTObjectImpl *, cXObjectImpl *) { }

// 0x803748B8 | 216 bytes
void InteractorModule::PlacementObject::Pickup(void) { }

// 0x80374990 | 152 bytes
void InteractorModule::PlacementObject::IsLegalToPlaceAtLocation(FTilePt &, int &) { }

// 0x80374A28 | 544 bytes
void InteractorModule::PlacementObject::Place(FTilePt &, int &) { }

// 0x80374C48 | 352 bytes
void InteractorModule::PlacementObject::Drop(void) { }

// 0x80374DA8 | 280 bytes
void InteractorModule::PlacementObject::Initialize(void) { }

// 0x80374EF4 | 172 bytes
void InteractorModule::PlacementObject::Destroy(void) { }

// 0x80375070 | 68 bytes
void InteractorModule::PlacementObject::SetDirection(int) { }

// 0x803750B4 | 1700 bytes
void InteractorModule::PlacementObject::Rotate(int) { }

// 0x80375758 | 748 bytes
void InteractorModule::PlacementObject::ResetLocation(void) { }

// 0x80375A44 | 172 bytes
void InteractorModule::PlacementObject::SetShaderToValidState(bool) { }

// 0x80377294 | 52 bytes
InteractorModule::GrabManipulator::CallbackData::~CallbackData(void) { }

// 0x803772C8 | 124 bytes
InteractorModule::GrabManipulator::GrabManipulator(void) { }

// 0x80377344 | 56 bytes
InteractorModule::GrabManipulator::~GrabManipulator(void) { }

// 0x8037737C | 52 bytes
InteractorModule::PlaceManipulator::CallbackData::~CallbackData(void) { }

// 0x803773B0 | 56 bytes
InteractorModule::PlaceManipulator::~PlaceManipulator(void) { }

// 0x803778B8 | 276 bytes
InteractorModule::SimInteractor::SimInteractor(void) { }

// 0x803779CC | 144 bytes
InteractorModule::SimInteractor::~SimInteractor(void) { }

// 0x80377AC4 | 712 bytes
void InteractorModule::SimInteractor::OnStart(int *) { }

// 0x80377D8C | 136 bytes
void InteractorModule::SimInteractor::OnStop(void) { }

// 0x80377E14 | 112 bytes
void InteractorModule::SimInteractor::ParseControls(void) { }

// 0x80377E84 | 1980 bytes
void InteractorModule::SimInteractor::Update(float) { }

// 0x80378640 | 116 bytes
void InteractorModule::SimInteractor::GetBeamScale(void) { }

// 0x803786B4 | 36 bytes
void InteractorModule::SimInteractor::GetInteractorInfo(int &) { }

// 0x80378730 | 1116 bytes
void InteractorModule::SimInteractor::OnCommandPressed(int, float) { }

// 0x80378B8C | 204 bytes
void InteractorModule::SimInteractor::OnCommandReleased(int) { }

// 0x80378CD0 | 208 bytes
void InteractorModule::SimInteractor::ReturnPlumbBobToOwner(void) { }

// 0x80378DA0 | 76 bytes
void InteractorModule::SimInteractor::ImmediatelyCutCursorAndCameraToPos(EVec3 &) { }

// 0x80378DEC | 356 bytes
void InteractorModule::SimInteractor::TryCutToSim(void) { }

// 0x80378FA8 | 496 bytes
void InteractorModule::SimInteractor::UpdateOverlapIntersection(int *) { }

// 0x80379198 | 784 bytes
void InteractorModule::SimInteractor::ExecuteActionMenu(void) { }

// 0x803794B4 | 112 bytes
void InteractorModule::SimInteractor::IsSimulatorPaused(void) { }

// 0x80379524 | 752 bytes
void InteractorModule::SimInteractor::UpdateObjectHighlights(EIObjectMan *) { }

// 0x80379814 | 68 bytes
void InteractorModule::SimInteractor::SetupCamera(void) { }

// 0x80379858 | 104 bytes
void InteractorModule::SimInteractor::ChooseAction(Interaction *) { }

// 0x8037AF1C | 76 bytes
InteractorModule::SocialModeInteractor::SocialModeInteractor(void) { }

// 0x8037AF68 | 52 bytes
InteractorModule::SocialModeInteractor::~SocialModeInteractor(void) { }

// 0x8037B00C | 276 bytes
void InteractorModule::SocialModeInteractor::OnStart(int *) { }

// 0x8037B120 | 128 bytes
void InteractorModule::SocialModeInteractor::OnStop(void) { }

// 0x8037B1A0 | 136 bytes
void InteractorModule::SocialModeInteractor::Update(float) { }

// 0x8037B228 | 4 bytes
void InteractorModule::SocialModeInteractor::GetInteractorInfo(int &) { }

// 0x8037B22C | 4 bytes
void InteractorModule::SocialModeInteractor::OnCommandPressed(int, float) { }

// 0x8037B234 | 4 bytes
void InteractorModule::SocialModeInteractor::OnCommandUpdate(int, float) { }

// 0x8037B2D0 | 380 bytes
void InteractorModule::SocialModeInteractor::SetupInteractionMenu(cXObject *, InteractionList &) { }

// 0x8037CA20 | 176 bytes
InteractorModule::WallManipulator::WallManipulator(void) { }

// 0x8037CAD0 | 372 bytes
InteractorModule::WallManipulator::~WallManipulator(void) { }

// 0x8037CC44 | 76 bytes
void InteractorModule::WallManipulator::OnCreate(void) { }

// 0x8037CCC4 | 1028 bytes
void InteractorModule::WallManipulator::OnStart(int *) { }

// 0x8037D0C8 | 188 bytes
void InteractorModule::WallManipulator::OnStop(void) { }

// 0x8037D1A8 | 1884 bytes
void InteractorModule::WallManipulator::CommittTransaction(int) { }

// 0x8037D904 | 688 bytes
void InteractorModule::WallManipulator::FinalizePlacement(void) { }

// 0x8037DBB4 | 976 bytes
void InteractorModule::WallManipulator::FinalizeWallDel(void) { }

// 0x8037DF84 | 492 bytes
void InteractorModule::WallManipulator::CountWallsInRoomSelection(void) { }

// 0x8037E170 | 1376 bytes
void InteractorModule::WallManipulator::FinalizeRoom(void) { }

// 0x8037E6D0 | 816 bytes
void InteractorModule::WallManipulator::HandleFinalizeRequest(void) { }

// 0x8037EA00 | 132 bytes
void InteractorModule::WallManipulator::HandleSwapRequest(void) { }

// 0x8037EA84 | 128 bytes
void InteractorModule::WallManipulator::HandleExitRequest(void) { }

// 0x8037EB30 | 764 bytes
void InteractorModule::WallManipulator::ValidateWallSegment(void) { }

// 0x8037EE2C | 84 bytes
void InteractorModule::WallManipulator::UpdateStickState(void) { }

// 0x8037EE80 | 96 bytes
void InteractorModule::WallManipulator::ClearWallFadeOffList(void) { }

// 0x8037EEE0 | 580 bytes
void InteractorModule::WallManipulator::Update(float) { }

// 0x8037F124 | 292 bytes
void InteractorModule::WallManipulator::OnCommandPressed(int, float) { }

// 0x8037F248 | 132 bytes
void InteractorModule::WallManipulator::OnCommandReleased(int) { }

// 0x8037F2CC | 76 bytes
void InteractorModule::WallManipulator::OnCommandUpdate(int, float) { }

// 0x8037F398 | 532 bytes
void InteractorModule::WallManipulator::GetWallLineCost(EVec3 &, EVec3 &, bool &, bool, bool) { }

// 0x8037F5AC | 400 bytes
void InteractorModule::WallManipulator::SubmitLine(EVec3 &, EVec3 &, int &, bool, bool) { }

// 0x8037F73C | 1196 bytes
void InteractorModule::WallManipulator::DoesNotConflictWithExistingArchitecture(CTilePt &, TileWallsSegment) { }

// 0x8037FBE8 | 332 bytes
void InteractorModule::WallManipulator::CanChangeTileAdd(CTilePt &, TileWallsSegment) { }

// 0x8037FD34 | 1480 bytes
void InteractorModule::WallManipulator::CanChangeTileDelete(CTilePt &, TileWallsSegment) { }

// 0x803802FC | 1036 bytes
void InteractorModule::WallManipulator::HandleDeleteLine(CTilePt &, CTilePt &, TilePtDir &, int) { }

// 0x80380708 | 664 bytes
void InteractorModule::WallManipulator::HandleAddLine(CTilePt, CTilePt, TilePtDir &, int) { }

// 0x803809A0 | 716 bytes
void InteractorModule::WallManipulator::LegalWallTile(CTilePt &, TileWallsSegment) { }

// 0x80380C6C | 384 bytes
void InteractorModule::WallManipulator::AddWallAtTile(CTilePt &, TileWalls &, TileWallsSegment) { }

// 0x80380DEC | 176 bytes
void InteractorModule::WallManipulator::PreviewNRooms(void) { }

// 0x80380E9C | 540 bytes
void InteractorModule::WallManipulator::IncrementSellCountForStyle(WallStyle) { }

// 0x803810B8 | 1840 bytes
void InteractorModule::WallManipulator::CheckForAffectedWalls(EVec3 &, EVec3 &) { }

// 0x803817E8 | 224 bytes
void InteractorModule::WallManipulator::SendBuildItemCountChangeEvent(int) { }

// 0x803833E0 | 300 bytes
InteractorModule::WallManipulator::CallbackData::~CallbackData(void) { }

// 0x8038350C | 88 bytes
InteractorModule::WallManipulator::CallbackData::CallbackData(void) { }

// 0x803836C0 | 112 bytes
InteractorModule::WallPainter::WallPainter(void) { }

// 0x80383730 | 172 bytes
InteractorModule::WallPainter::~WallPainter(void) { }

// 0x803837DC | 76 bytes
void InteractorModule::WallPainter::OnCreate(void) { }

// 0x8038385C | 936 bytes
void InteractorModule::WallPainter::OnStart(int *) { }

// 0x80383C64 | 908 bytes
void InteractorModule::WallPainter::CommittTransaction(int) { }

// 0x80383FF0 | 432 bytes
void InteractorModule::WallPainter::HandleFinalizeRequest(void) { }

// 0x803841A0 | 132 bytes
void InteractorModule::WallPainter::HandleSwapRequest(void) { }

// 0x80384224 | 112 bytes
void InteractorModule::WallPainter::HandleExitRequest(void) { }

// 0x80384294 | 268 bytes
void InteractorModule::WallPainter::AdjustCursorPosition(void) { }

// 0x803843A0 | 1172 bytes
void InteractorModule::WallPainter::ValidateWallSegment(void) { }

// 0x80384834 | 84 bytes
void InteractorModule::WallPainter::UpdateStickState(void) { }

// 0x80384888 | 1088 bytes
void InteractorModule::WallPainter::Update(float) { }

// 0x80384CC8 | 348 bytes
void InteractorModule::WallPainter::OnCommandPressed(int, float) { }

// 0x80384E24 | 196 bytes
void InteractorModule::WallPainter::OnCommandReleased(int) { }

// 0x80384EE8 | 76 bytes
void InteractorModule::WallPainter::OnCommandUpdate(int, float) { }

// 0x80384F8C | 1656 bytes
void InteractorModule::WallPainter::CountWallsInRoomSelection(void) { }

// 0x80385604 | 1356 bytes
void InteractorModule::WallPainter::FinalizePaperForRoom(void) { }

// 0x80385B50 | 216 bytes
void InteractorModule::WallPainter::FinalizePaperForLine(void) { }

// 0x80385C28 | 200 bytes
void InteractorModule::WallPainter::FinalizeSellPaperForLine(void) { }

// 0x80385CF0 | 1052 bytes
void InteractorModule::WallPainter::SubmitPaperLine(EVec2 &, EVec2 &, WallPattern, int) { }

// 0x80386118 | 284 bytes
void InteractorModule::WallPainter::SendBuildItemCountChangeEvent(int) { }

// 0x80387CB0 | 148 bytes
InteractorModule::WallPainter::CallbackData::~CallbackData(void) { }

// 0x80387EF4 | 212 bytes
void InteractorModule::WallPainter::RestoreFromHoldPos(EVec3 &) { }
#endif
