#ifndef BOMB_H
#define BOMB_H

#include "types.h"

// Forward declarations
struct EVec4;

// ============================================================================
// Debug assertion / bomb system
// Object file: bomb.obj
// ============================================================================

// Globals
extern int _assertionFailed;    // 0x804FDBA8
extern int _bombed;             // 0x804FDBAC
extern int g_bTreeAssert;       // 0x804FF960
extern char* _assertFile;       // 0x804FF958
extern int _assertLine;         // 0x804FF954
extern char* _assertExpr;       // 0x804FF95C

void DrawFrame(char* msg, EVec4& color, bool waitVSync);
void WaitForControllerButton(bool waitRelease);
void dbAssert(char* file, unsigned int line, char* expr);
void dbBomb(char* fmt, ...);
void dbAssertTrace(bool condition, char* fmt, ...);

#endif // BOMB_H
