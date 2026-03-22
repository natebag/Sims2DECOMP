// loadingscreen.cpp - CLoadingScreen small functions
// From: loadingscreen.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/loadingscreen.h"

// ============================================================================
// External references
// ============================================================================

// MainHeap() - returns the main EAHeap pointer
extern "C" void* MainHeap(void);

// EAHeap memory functions
class EAHeap {
public:
    void* MallocAligned(unsigned int size, unsigned int alignment, unsigned int flags, int extra);
    void Free(void* ptr);
};

// ============================================================================
// CLoadingScreen::operator new(unsigned int)
// 0x80057830 - 64 bytes
// Allocates from MainHeap with 16-byte alignment
// ============================================================================
// NON_MATCHING - Register allocation differs. Original uses stmw r30 / lmw r30
// and r30 for size. GCC uses stw r31 / lwz r31 and r31 for size.
// Also GCC reorders the argument setup differently and uses tail call.
void* CLoadingScreen::operator new(unsigned int size) {
    EAHeap* heap = (EAHeap*)MainHeap();
    return heap->MallocAligned(size, 16, 0, 0);
}

// ============================================================================
// CLoadingScreen::operator delete(void *)
// 0x80057870 - 52 bytes
// Frees via MainHeap
// ============================================================================
// NON_MATCHING - Same register allocation issue as operator new.
// Original uses stmw r30 / lmw r30 with r30, GCC uses r31.
// GCC also uses tail call for Free().
void CLoadingScreen::operator delete(void* ptr) {
    EAHeap* heap = (EAHeap*)MainHeap();
    heap->Free(ptr);
}

// ============================================================================
// CLoadingScreen::GetMode(void) const
// 0x800578a4 - 8 bytes
// lwz r3, 0x354(r3); blr
// ============================================================================
int CLoadingScreen::GetMode(void) const {
    return m_mode;
}

// ============================================================================
// global constructors keyed to CLoadingScreen::CLoadingScreen(...)
// 0x800578ac - 44 bytes
// Compiler-generated thunk: calls __static_initialization_and_destruction_0(1, 0xFFFF)
// Cannot be written manually; emitted by compiler for static global objects.
// ============================================================================

// ============================================================================
// Additional non-small functions in loadingscreen.obj (not decompiled here):
//   CLoadingScreen::CLoadingScreen(eLoadingScreenMode) - 0x80056a64 (large)
//   ... and other functions
// ============================================================================
