#ifndef MOVIEPLAYER_H
#define MOVIEPLAYER_H

#include "types.h"

// Forward declarations
class ERC;
class TheSimsStateMachine;

// MoviePlayerEndgameMovieState - State for playing endgame FMV
// From: movieplayer.obj
// Size: at least 0x1C bytes
// Layout:
//   0x00: int m_movieId
//   0x04: int m_field04 (init to -1)
//   0x08: int m_field08 (init to 0, holds state machine ptr)
//   0x0C: int m_field0C (init to -1)
//   0x10: int m_field10 (init to 0)
//   0x14: int m_field14 (init to 1)
//   0x18: void* m_vtable (set to vtable ptr)
class MoviePlayerEndgameMovieState {
public:
    MoviePlayerEndgameMovieState(int movieId);

    void Update(float dt);
    void GotoGame();
    void Draw(ERC* rc);
    void Shutdown(void);
    void SetFlowStateCurrent(void);

private:
    int m_movieId;       // 0x00
    int m_field04;       // 0x04
    int m_field08;       // 0x08 - TheSimsStateMachine*
    int m_field0C;       // 0x0C
    int m_field10;       // 0x10
    int m_field14;       // 0x14
    void* m_vtable18;    // 0x18
};

#endif // MOVIEPLAYER_H
