// movieplayer.cpp - MoviePlayerEndgameMovieState small functions
// From: movieplayer.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/movieplayer.h"

// ============================================================================
// External references
// ============================================================================

// EApp::IsMoviePlaying(void) at 0x802e2734
class EApp {
public:
    int IsMoviePlaying(void);
};

// GameData::SetUglyGraphicsBackgroundColor(void) at 0x8003d824
extern "C" void GameData_SetUglyGraphicsBackgroundColor(void);

// TheSimsStateMachine::SetFlowStateCurrent(void) at 0x8009981c
class TheSimsStateMachine {
public:
    void SetFlowStateCurrent(void);
};

// External global pointers (resolved from disassembly addresses)
// 0x8046e208 -> lis r3, -32697; addi r3, r3, -7672
// 0x80475b84 -> lis r3, -32697; addi r3, r3, 23428
extern EApp* g_movieApp;                   // at 0x8046e208 (approx)
extern "C" void* g_gameData;              // at 0x80475b84 (approx)

// Vtable for MoviePlayerEndgameMovieState
extern "C" void* MoviePlayerEndgameMovieState_vtable;  // at 0x8045c980

// ============================================================================
// MoviePlayerEndgameMovieState::Draw(ERC *)
// 0x800587e8 - 4 bytes
// No-op (just blr)
// ============================================================================
void MoviePlayerEndgameMovieState::Draw(ERC* rc) {
    // empty
}

// ============================================================================
// MoviePlayerEndgameMovieState::Shutdown(void)
// 0x800587ec - 52 bytes
// Checks if movie is playing, sets background color
// ============================================================================
// NON_MATCHING - Uses hardcoded absolute addresses for global pointers
// which will differ in recompilation. The original loads:
//   lis r3, 0x8047; addi r3, r3, -0x1DF8  (0x8046e208)
//   then calls EApp::IsMoviePlaying
//   lis r3, 0x8047; addi r3, r3, 0x5b84   (0x80475b84)
//   then calls GameData::SetUglyGraphicsBackgroundColor
void MoviePlayerEndgameMovieState::Shutdown(void) {
    // The original accesses globals via absolute addresses.
    // This is a structural approximation.
    // Original: calls IsMoviePlaying on a global EApp ptr, then SetUglyGraphicsBackgroundColor
}

// ============================================================================
// MoviePlayerEndgameMovieState::MoviePlayerEndgameMovieState(int)
// 0x80058820 - 56 bytes
// Constructor: initializes all fields
// ============================================================================
MoviePlayerEndgameMovieState::MoviePlayerEndgameMovieState(int movieId) {
    m_movieId = movieId;
    m_field0C = -1;
    m_field10 = 0;
    m_field14 = 1;
    m_vtable18 = &MoviePlayerEndgameMovieState_vtable;
    m_field04 = -1;
    m_field08 = 0;
}

// ============================================================================
// MoviePlayerEndgameMovieState::SetFlowStateCurrent(void)
// 0x80058858 - 36 bytes
// Loads state machine from field08, calls SetFlowStateCurrent on it
// ============================================================================
void MoviePlayerEndgameMovieState::SetFlowStateCurrent(void) {
    ((TheSimsStateMachine*)m_field08)->SetFlowStateCurrent();
}
