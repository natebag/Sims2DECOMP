#ifndef COMMANDER_H
#define COMMANDER_H

#include "types.h"

// ============================================================================
// Commander - Command dispatch system
// Object file: commander.obj
//
// Layout (from disassembly):
//   +0x00: Commander* m_prev  (linked list previous, = sList before insert)
//   +0x04: int   m_type
//   +0x08: int   m_id
//   +0x0C: void* m_vtable
// Size: 0x10 (16 bytes)
// ============================================================================
class Commander {
public:
    Commander* m_prev;     // +0x00 - linked list (sList head)
    int   m_type;          // +0x04
    int   m_id;            // +0x08
    // vtable at +0x0C

    static Commander* sList;  // 0x804FDBD4 - head of commander list
    static int sId;           // 0x804FDBD8 - id counter

    Commander();
    ~Commander();
    virtual bool DoCommand(short cmd, int param);
    int GetType();
    Commander* GetNext();
};

// Global dispatch functions
bool GlobalDispatch(short cmd, int param);
bool TypedDispatch(int type, short cmd, int param, bool allTypes);

#endif // COMMANDER_H
