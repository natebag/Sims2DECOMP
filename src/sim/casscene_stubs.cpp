// casscene_stubs.cpp - Stub implementations for Casscene
// Auto-generated from symbols.json - 18 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8025067C | 612 bytes
CasScene::CasScene(void) { }

// 0x802508E0 | 428 bytes
CasScene::~CasScene(void) { }

// 0x80250B34 | 808 bytes
void CasScene::Reload(void) { }

// 0x80250EB4 | 364 bytes
void CasScene::Draw(ERC *) { }

// 0x802510B0 | 504 bytes
void CasScene::DrawRoomClothing(ERC *, EMat4 &) { }

// 0x802512A8 | 16 bytes
void CasScene::SetCameraParams(float, float, float) { }

// 0x802512B8 | 864 bytes
void CasScene::LoadLights(char *, int) { }

// 0x80251618 | 388 bytes
void CasScene::SetLights(int) { }

// 0x802517E4 | 1008 bytes
void CasScene::RepositionCamera(unsigned int, float, float) { }

// 0x80251BD4 | 376 bytes
void CasScene::InitCamera(unsigned int) { }

// 0x80251D4C | 1268 bytes
void CasScene::UpdateCamera(float) { }

// 0x80252240 | 276 bytes
void CasScene::SetUpWindow(ERC *) { }

// 0x80252354 | 740 bytes
void CasScene::HandleEventChangeFocus(CasEventChangeFocus &) { }

// 0x80254018 | 60 bytes
void CasScene::GetCameraAngle(EVec3 *, EVec3 *) { }

// 0x80254054 | 60 bytes
void CasScene::IsCameraMoving(void) { }

// 0x80254090 | 8 bytes
void CasScene::GetLights(void) { }

// 0x80254098 | 8 bytes
void CasScene::Get3DWindow(void) const { }

// 0x802540A8 | 8 bytes
void CasScene::GetAmbientScoreName(void) const { }
