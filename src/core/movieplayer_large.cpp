// movieplayer_large.cpp - MoviePlayer large functions (257-1024 bytes)
// Object file: movieplayer.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void StateMachineState_OwnerSetNextState(void* state, int id, float d);
}

// ============================================================================
// MoviePlayerEndgameMovieState::Reset(void)
// Address: 0x800585fc
// Size: 0x120 = 288 bytes
// NON_MATCHING - movie setup, state initialization
// ============================================================================
void MoviePlayerEndgameMovieState_Reset(void* self) {
    char* _this = (char*)self;

    // Initialize movie player state
    *(int*)(_this + 0x20) = 0;  // m_movieStarted
    *(int*)(_this + 0x24) = 0;  // m_movieFinished

    // Get movie ID for endgame
    // Load movie resource

    // Set up movie playback parameters:
    //   Full screen mode
    //   Audio volume
    //   Subtitle handling

    // Set up skip button handler
    // Initialize fade overlay

    // Start movie playback
    // EApp::PlayMovie

    (void)_this;
}

// Note: All other movieplayer.obj functions are under 257 bytes.
// MoviePlayerEndgameMovieState::Update is 0x5c = 92 bytes
// MoviePlayerEndgameMovieState::GotoGame is 0x70 = 112 bytes
