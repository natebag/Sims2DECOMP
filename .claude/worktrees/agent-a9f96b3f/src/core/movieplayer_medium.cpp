// movieplayer_medium.cpp - MoviePlayer medium functions (65-256 bytes)
// Object file: movieplayer.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "core/movieplayer.h"

// External functions
extern "C" void* StateMachine_GetCurrent(void*);
extern "C" void StateMachine_SetState(void*, int);
extern "C" int StateMachine_IsComplete(void*);
extern "C" void MoviePlayer_StartMovie(int);
extern "C" void MoviePlayer_StopMovie();
extern "C" int MoviePlayer_IsPlaying();

// ============================================================================
// MoviePlayerEndgameMovieState::Update
// movieplayer.obj | 0x8005871C | 92 bytes
// Updates the endgame movie playback state
// ============================================================================
// NON_MATCHING: state machine transition codegen
void MoviePlayerEndgameMovieState::Update(float dt) {
    // Check if movie is still playing
    if (!MoviePlayer_IsPlaying()) {
        // Movie finished, transition to next state
        GotoGame();
    }
}

// ============================================================================
// MoviePlayerEndgameMovieState::GotoGame
// movieplayer.obj | 0x80058778 | 112 bytes
// Transitions from endgame movie to game state
// ============================================================================
// NON_MATCHING: state machine transition
void MoviePlayerEndgameMovieState::GotoGame() {
    MoviePlayer_StopMovie();
    // Transition to main game state
    void* stateMachine = (void*)m_field08;
    if (stateMachine != 0) {
        StateMachine_SetState(stateMachine, 0); // return to game
    }
}
