// eglobal_stubs.cpp - Stub implementations for Eglobal
// Auto-generated from symbols.json - 88 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x80066630 | 40 bytes
EGlobal::~EGlobal(void) { }

// 0x80066658 | 796 bytes
EGlobal::EGlobal(void) { }

// 0x80066974 | 40 bytes
void EGlobal::SetAuthorModeCheats(void) { }

// 0x8006699C | 84 bytes
void EGlobal::CreateAnimator(void) { }

// 0x80066A18 | 576 bytes
void EGlobal::IsObjectInUseByPlayer(int, cXObject *) { }

// 0x80066C58 | 1776 bytes
void EGlobal::LoadIntroRequirements(void) { }

// 0x80067348 | 140 bytes
void EGlobal::LoadPreGlobalRequirements(void) { }

// 0x800673D4 | 1192 bytes
void EGlobal::SetDefaults(void) { }

// 0x8006787C | 4 bytes
void EGlobal::SetupScratchHeap(void) { }

// 0x80067880 | 4 bytes
void EGlobal::FreeScratchHeap(void) { }

// 0x80067884 | 892 bytes
void EGlobal::SetupSubstitutionStrings(void) { }

// 0x800680AC | 136 bytes
void EGlobal::SetCurHouse(int) { }

// 0x80068134 | 68 bytes
void EGlobal::ClearCurHouse(void) { }

// 0x80068178 | 80 bytes
void EGlobal::SelectWin(ERC *) { }

// 0x800681C8 | 24 bytes
void EGlobal::GetWin(void) { }

// 0x800681E0 | 104 bytes
void EGlobal::SetCam(ESimsCam *) { }

// 0x80068248 | 8 bytes
void EGlobal::GetCam(void) { }

// 0x80068250 | 104 bytes
void EGlobal::SetCameraDirector(CameraDirector *) { }

// 0x800682B8 | 128 bytes
void EGlobal::TransformToScreen(EVec3 &, EVec2 &) { }

// 0x80068338 | 80 bytes
void EGlobal::TransformToWorld(EVec2 &, EVec3 &) { }

// 0x80068388 | 16 bytes
void EGlobal::GetLiveModeMenuUIString(char *) { }

// 0x80068398 | 256 bytes
void EGlobal::HouseNameText(char *) { }

// 0x80068498 | 256 bytes
void EGlobal::HouseNameCapsText(char *) { }

// 0x80068598 | 16 bytes
void EGlobal::GetScriptSubstitutionString(char *) { }

// 0x800685A8 | 244 bytes
void EGlobal::GetHouseLevelId(char *) { }

// 0x8006869C | 244 bytes
void EGlobal::GetHouseGrassShaderId(char *) { }

// 0x80068790 | 256 bytes
void EGlobal::GetHUDUIString(char *) { }

// 0x80068890 | 336 bytes
void EGlobal::GetNewUIString(char *) { }

// 0x800689E0 | 256 bytes
void EGlobal::GetPDAString(char *) { }

// 0x80068AE0 | 280 bytes
void EGlobal::GetWantFearCategoryString(int, int) { }

// 0x80068BF8 | 200 bytes
void EGlobal::GetRelationshipTableRow(unsigned int) { }

// 0x80068CC0 | 220 bytes
void EGlobal::GetMessagesTableRow(unsigned int) { }

// 0x80068D9C | 196 bytes
void EGlobal::GetUrbzButtonsRow(unsigned int) { }

// 0x80068E60 | 288 bytes
void EGlobal::GetRepTitleTableRow(unsigned int) { }

// 0x80068F80 | 488 bytes
void EGlobal::GetGoalsLegendRow(unsigned int) { }

// 0x80069168 | 256 bytes
void EGlobal::GetMemCardString(char *) { }

// 0x80069268 | 296 bytes
void EGlobal::GetNghFamilyName(BString2 &) { }

// 0x80069390 | 380 bytes
void EGlobal::GetNghHouseName(BString2 &) { }

// 0x8006950C | 440 bytes
void EGlobal::ConvertUnicodeToShiftJIS(unsigned wchar_t *, unsigned wchar_t *, unsigned int) { }

// 0x800696C4 | 164 bytes
void EGlobal::GetFloorIndex(FloorTile *) { }

// 0x80069768 | 164 bytes
void EGlobal::GetWallIndex(WallTile *) { }

// 0x8006980C | 164 bytes
void EGlobal::GetFenceIndex(FenceData *) { }

// 0x800698B0 | 16 bytes
void EGlobal::GetSelectedPerson(int) { }

// 0x800698C0 | 140 bytes
void EGlobal::SimInUseByOtherPlayer(int, cXPerson *) { }

// 0x8006994C | 508 bytes
void EGlobal::SetSelectedPerson(int, cXPerson *) { }

// 0x80069B48 | 72 bytes
void EGlobal::IsPlayerInSocialMode(int) { }

// 0x80069B90 | 192 bytes
void EGlobal::GetFamilyIndexOfPerson(ObjectModule *, Family *, cXPerson *) { }

// 0x80069C50 | 488 bytes
void EGlobal::SelectNextInFamily(Family *, int, int) { }

// 0x80069E38 | 436 bytes
void EGlobal::AdvanceSelectedPerson(int) { }

// 0x80069FEC | 492 bytes
void EGlobal::SelectPrevInFamily(Family *, int, int) { }

// 0x8006A1D8 | 428 bytes
void EGlobal::ReverseSelectedPerson(int) { }

// 0x8006A384 | 4 bytes
void EGlobal::PlaceObjectInHouse(cXObject *) { }

// 0x8006A388 | 4 bytes
void EGlobal::PickUpInHouseObject(cXObject *) { }

// 0x8006A38C | 320 bytes
void EGlobal::GetCursorPosAsFtile(FTilePt &) { }

// 0x8006A4CC | 396 bytes
void EGlobal::DestroyInstance(IBaseSimInstance **) { }

// 0x8006A658 | 408 bytes
void EGlobal::AllocInstance(cXObject *) { }

// 0x8006A7F0 | 844 bytes
void EGlobal::AllocPersonInstance(cXPerson *) { }

// 0x8006AB3C | 120 bytes
void EGlobal::AllocSpriteRenderer(cXObject *) { }

// 0x8006ABB4 | 44 bytes
void EGlobal::FreeSpriteRenderer(cXObject *) { }

// 0x8006ABE0 | 120 bytes
void EGlobal::UpdateSpriteRenderer(SpriteSlot *) { }

// 0x8006AC58 | 80 bytes
void EGlobal::ConvertSpriteIdToResId(unsigned int) { }

// 0x8006ACA8 | 48 bytes
void EGlobal::GetCounterModelTable(void) { }

// 0x8006ACD8 | 40 bytes
void EGlobal::LoadSelectorData(ObjSelector *, bool) { }

// 0x8006AD00 | 44 bytes
void EGlobal::UnloadSelectorData(ObjSelector *) { }

// 0x8006AD2C | 128 bytes
void EGlobal::CreateThumbnail(ObjSelector *) { }

// 0x8006AF94 | 32 bytes
void EGlobal::RecalcFloor(void) { }

// 0x8006AFB4 | 32 bytes
void EGlobal::RecalcWalls(void) { }

// 0x8006AFD4 | 48 bytes
void EGlobal::RecalcObjects(void) { }

// 0x8006B004 | 68 bytes
void EGlobal::RecalcHouse(void) { }

// 0x8006B048 | 184 bytes
void EGlobal::BeginSaveGame(void) { }

// 0x8006B100 | 48 bytes
void EGlobal::EndSaveGame(void) { }

// 0x8006B50C | 152 bytes
void EGlobal::CheckForZeroExtentOverride(CTilePt &, cXObject *) { }

// 0x8006B5F0 | 200 bytes
void EGlobal::SetBackgroundColor(float, float, float) { }

// 0x8006B6B8 | 8 bytes
void EGlobal::IsBuildHouseMode(void) { }

// 0x8006B6C0 | 296 bytes
void EGlobal::SwapSelectedSims(void) { }

// 0x8006B7E8 | 8 bytes
void EGlobal::ListenForController(void) { }

// 0x8006B7F0 | 8 bytes
void EGlobal::GetSkillFromName(char *) { }

// 0x8006B7F8 | 340 bytes
void EGlobal::GetNameFromSkill(AnimRef *) { }

// 0x8006B94C | 8 bytes
void EGlobal::GetPropFromName(char *) { }

// 0x8006B954 | 8 bytes
void EGlobal::GetNameFromProp(PropRef *) { }

// 0x8006B95C | 148 bytes
void EGlobal::UseOptionsScreenAdjustXY(void) { }

// 0x8006B9F0 | 24 bytes
void EGlobal::InLevelState(void) { }

// 0x8006BA08 | 32 bytes
void EGlobal::GetPlayerCheats(void) const { }

// 0x8006BA28 | 48 bytes
void EGlobal::IsPlayerCheatOn(int) const { }

// 0x8006BA58 | 288 bytes
void EGlobal::TogglePlayerCheat(int) { }

// 0x8006BB78 | 448 bytes
void EGlobal::InitPlayerCheats(void) { }

// 0x8006BD38 | 260 bytes
void EGlobal::TryAutoMapPlayer(int) { }

// 0x8006BE3C | 244 bytes
void EGlobal::IsSaveGameEnabled(void) { }
