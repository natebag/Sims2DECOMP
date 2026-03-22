// person_stubs.cpp - Stub implementations for cXPersonImpl class methods
// Auto-generated from symbols.json - 14 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.
//
// Class: cXPersonImpl

#include "types.h"

// Forward declarations
class FTilePt;
class ObjSelector;
class ObjectModule;
class StackElem;
class XPrimParam;
class XRoute;
class cXObject;
class cXPerson;

// ======================================================================
// cXPersonImpl
// ======================================================================

// 0x801CF578 | 6232 bytes
cXPersonImpl::cXPersonImpl(int, ObjSelector *, ObjectModule *) {
}

// 0x801D0EF0 | 6528 bytes
cXPersonImpl::~cXPersonImpl(void) {
}

// 0x801D2870 | 2872 bytes
void cXPersonImpl::Initialize(void) {
}

// 0x801D3E84 | 3412 bytes
void cXPersonImpl::TryLookTowards(StackElem *, XPrimParam *) {
}

// 0x801D6DB0 | 2236 bytes
void cXPersonImpl::AskOthersToMove(XRoute *) {
}

// 0x801D8618 | 3760 bytes
void cXPersonImpl::InitRoute(XRoute *) {
}

// 0x801DCEAC | 5380 bytes
void cXPersonImpl::TryFindBestAction(StackElem *) {
}

// 0x801DE528 | 76 bytes
void cXPersonImpl::Place(FTilePt &, int, cXObject *, int) {
}

// 0x801DE574 | 4968 bytes
void cXPersonImpl::TrySocialMode(StackElem *, XPrimParam *) {
}

// 0x801DFCFC | 76 bytes
void cXPersonImpl::ForceLocation(void) {
}

// 0x801E055C | 3636 bytes
void cXPersonImpl::Cleanup(cXObject *) {
}

// 0x8020212C | 148 bytes
void cXPersonImpl::GetSimMemory(cXPerson *, int) {
}

// 0x802021C0 | 156 bytes
void cXPersonImpl::SetSimMemory(cXPerson *, int, int) {
}

// 0x8020225C | 148 bytes
void cXPersonImpl::GetDominantMemory(cXPerson *, int) {
}
