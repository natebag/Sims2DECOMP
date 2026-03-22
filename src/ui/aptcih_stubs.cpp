// aptcih_stubs.cpp - Stub implementations for Aptcih
// Auto-generated from symbols.json - 44 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8040E8D8 | 192 bytes
AptCIH::~AptCIH(void) { }

// 0x8040E998 | 292 bytes
void AptCIH::Remove(void) { }

// 0x8040EABC | 80 bytes
void AptCIH::PreDestroy(void) { }

// 0x8040EB0C | 156 bytes
void AptCIH::DestroyGCPointers(void) { }

// 0x8040EBA8 | 1280 bytes
void AptCIH::ClearCIH(bool) { }

// 0x8040F0A8 | 236 bytes
void AptCIH::RegisterReferences(void) const { }

// 0x8040F194 | 124 bytes
void AptCIH::getNativeHash(void) const { }

// 0x8040F2F4 | 820 bytes
void AptCIH::ensureStringAllocated(AptCIH *) { }

// 0x8040F628 | 264 bytes
void AptCIH::deallocAssetStringRecursive(void) { }

// 0x8040F730 | 1840 bytes
void AptCIH::render(AptRenderingContext *, AptMath::ClipTransform_t *, AptMaskRenderOperation) { }

// 0x8040FE60 | 448 bytes
void AptCIH::_getBoundingRect(AptRenderingContext *, AptRect *) { }

// 0x80410020 | 172 bytes
void AptCIH::getBoundingRect(AptRect *) { }

// 0x804100CC | 184 bytes
void AptCIH::getGlobalBoundingRect(AptRect *) { }

// 0x80410184 | 172 bytes
void AptCIH::getGlobalTranslation(float *, float *) { }

// 0x80410230 | 976 bytes
void AptCIH::GetProceduralProperty(AptProceduralProperty) { }

// 0x80410600 | 1784 bytes
void AptCIH::setProceduralProperty(AptProceduralProperty, float, bool) { }

// 0x80410CF8 | 212 bytes
void AptCIH::FindAndSetEvents(void) { }

// 0x80410DCC | 1468 bytes
void AptCIH::associateInstToClass(void) { }

// 0x80411388 | 220 bytes
void AptCIH::gotoState(AptCharacterButtonRecordState) { }

// 0x80411464 | 452 bytes
void AptCIH::jumpToFrame(int) { }

// 0x80411628 | 76 bytes
void AptCIH::SetEventHandler(int) { }

// 0x80411674 | 76 bytes
void AptCIH::RemoveEventHandler(int) { }

// 0x804116C0 | 164 bytes
void AptCIH::HasEvent(int) { }

// 0x80411764 | 1172 bytes
void AptCIH::queueClipEvents(int, unsigned int, int) { }

// 0x80411BF8 | 544 bytes
void AptCIH::tick(void) { }

// 0x80411E18 | 152 bytes
void AptCIH::checkIfHigher(AptCIH *) { }

// 0x80411ED4 | 100 bytes
void AptCIH::getDepthOfParentAt(int) { }

// 0x80411F38 | 104 bytes
void AptCIH::isVisiable(void) { }

// 0x80411FF8 | 140 bytes
void AptCIH::getRootAnimation(void) { }

// 0x804120C0 | 348 bytes
void AptCIH::hasRenderData(void) { }

// 0x8041221C | 364 bytes
void AptCIH::GetMovieclipInfo(AptMovieclipInformation *) { }

// 0x804124B8 | 288 bytes
AptCIH::AptCIH(AptVirtualFunctionTable_Indices, AptCharacterInst *, AptCIH *) { }

// 0x80412620 | 92 bytes
void AptCIH::isSpriteInst(bool) const { }

// 0x8041267C | 92 bytes
void AptCIH::isCharacterInst(void) const { }

// 0x804126D8 | 92 bytes
void AptCIH::isButtonInst(bool) const { }

// 0x80412734 | 76 bytes
void AptCIH::isShapeInst(void) const { }

// 0x80412780 | 76 bytes
void AptCIH::isTextInst(void) const { }

// 0x804127CC | 76 bytes
void AptCIH::isStaticTextInst(void) const { }

// 0x80412818 | 76 bytes
void AptCIH::isMorphInst(void) const { }

// 0x80412864 | 92 bytes
void AptCIH::isAnimationInst(bool) const { }

// 0x804128C0 | 76 bytes
void AptCIH::isLevelInst(void) const { }

// 0x8041290C | 164 bytes
void AptCIH::isSpriteInstBase(bool) const { }

// 0x804129B0 | 100 bytes
void AptCIH::GetCosAngle(AptMatrix *) { }

// 0x80412A14 | 88 bytes
void AptCIH::GetVectorLength(AptMatrix *) { }
