#if 0 // SKIP
// mustates_medium.cpp - MUStates medium functions (65-256 bytes)
// Object file: mustates.obj
// 16 functions

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class ERC;
class ERFont;
class Wrapper;

// External functions
extern "C" {
    void MU_SaveNewGameImpl();                    // 0x8009165c
    void Wrapper_SetItemStyle(void* w, int style);  // 0x80082514
    void MUStates_ChangeState(void* self, int state);  // 0x80095ac8
    void MUStates_TransitionState(void* self, int state);  // 0x80095dfc
    void Wrapper_Shutdown(void* wrapper);         // 0x8007f7bc
    void MUStateMachine_SetUpdateRate(void* self, float rate, int arg);  // 0x80095d78
    void EAString_Init(char* buf, const char* src);  // 0x800a3374
    void Vector_Clear(void* vec, int mode);       // 0x803a0b74
    void operator_delete(void* ptr);              // 0x802d1220
    void SmallBlockAllocator_Free(void* ptr);     // 0x8039be60
}

// External globals
extern void* s_muStateMachinePtr;  // r13 - 22756 (s_muStateMachine at r13-0x58E4)

// Global MU state data
struct MUStateData {
    int m_field00;         // 0x00
    int m_field04;         // 0x04
    int m_field08;         // 0x08
    int m_field0C;         // 0x0C
    void* m_field10;       // 0x10
    void* m_field14;       // 0x14
    void* m_field18;       // 0x18
    void* m_field1C;       // 0x1C
    int m_field20;         // 0x20
    int m_field24;         // 0x24
    int m_field28;         // 0x28
    int m_field2C;         // 0x2C
    int m_field30;         // 0x30
    int m_field34;         // 0x34
    int m_field38;         // 0x38
    int m_field3C;         // 0x3C
    int m_field40;         // 0x40
};

extern MUStateData s_muStateData;  // 0x804858D8

// ============================================================================
// MUStatesFormat
// ============================================================================
struct MUStatesFormat {
    u8 _pad00[0x08];
    void* m_machine;       // 0x08
    u8 _pad0C[0x10];
    int m_field1C;         // 0x1C
    int m_field20;         // 0x20

    void Reset();
    void Draw(ERC* rc);
};

// ============================================================================
// MUStatesSlotSelectSave
// ============================================================================
struct MUStatesSlotSelectSave {
    u8 _pad00[0x08];
    void* m_machine;       // 0x08
    u8 _pad0C[0x84];
    int m_memcardState;    // 0x90

    void Update(float dt);
};

// ============================================================================
// MUStatesSlotSelectSaveNoSkip
// ============================================================================
struct MUStatesSlotSelectSaveNoSkip {
    u8 _pad00[0x08];
    void* m_machine;       // 0x08
    u8 _pad0C[0x84];
    int m_memcardState;    // 0x90

    void Update(float dt);
};

// ============================================================================
// MUStatesSaveNewGame
// ============================================================================
struct MUStatesSaveNewGame {
    int m_field00;         // 0x00
    u8 _pad04[0x04];
    void* m_machine;       // 0x08
    u8 _pad0C[0x10];
    int m_field1C;         // 0x1C

    void Draw(ERC* rc);
    MUStatesSaveNewGame(int arg);
};

// ============================================================================
// MUStatesTransitionSaveExistingGame
// ============================================================================
struct MUStatesTransitionSaveExistingGame {
    u8 _pad00[0x08];
    void* m_machine;       // 0x08
    u8 _pad0C[0x10];
    int m_field1C;         // 0x1C

    void Draw(ERC* rc);
};

// ============================================================================
// MUStatesLoadConfig
// ============================================================================
struct MUStatesLoadConfig {
    u8 _pad00[0x08];
    void* m_machine;       // 0x08
    u8 _pad0C[0x10];
    int m_field1C;         // 0x1C

    void Draw(ERC* rc);
};

// ============================================================================
// MUStatesDisplay
// ============================================================================
struct MUStatesDisplay {
    u8 _pad00[0x08];
    void* m_machine;       // 0x08

    void Update(float dt);
    void Draw(ERC* rc);
};

// ============================================================================
// MUStateMachine
// ============================================================================
struct MUStateMachine {
    u8 _pad00[0x18];
    void* m_vtable;        // 0x18
    u8 _pad1C[0x08];
    u8 _pad24[0x30];
    void* m_vec_begin;     // 0x54 - vector begin
    u8 _pad58[0x3C];
    int m_field94;         // 0x94
    void* m_wrapper;       // 0x98

    void SetupQuitToMainMenu();
    void MUWrapperShutdown();
    void Reset();
    ~MUStateMachine();
};

// ============================================================================
// Implementations
// ============================================================================

// 0x800916b4 | 68 bytes
void THREADCALL_MU_SaveNewGame() {
    MU_SaveNewGameImpl();
    // Virtual call through s_muStateMachinePtr vtable
    void* machine = s_muStateMachinePtr;
    void** vtable = *(void***)machine;
    s16 offset = *(s16*)((u8*)vtable + 0x40);
    void* func = *(void**)((u8*)vtable + 0x44);
    void* thisAdj = (void*)((u8*)machine + offset);
    typedef void (*TransitionFn)(void*, int);
    ((TransitionFn)func)(thisAdj, (int)THREADCALL_MU_SaveNewGame);
}

// 0x800916f8 | 108 bytes
void MUStatesFormat::Reset() {
    m_field1C = 0;
    m_field20 = 0;
    // Set wrapper mode
    void* machine = m_machine;
    void* wrapper = *(void**)((u8*)machine + 0x98);
    *(int*)((u8*)wrapper + 0xAC) = 2;
    Wrapper_SetItemStyle(wrapper, 17);
    MUStates_ChangeState(this, 14);
    m_field20 = 0;
    m_field1C = 1;
}

// 0x80091764 | 72 bytes
void MUStatesFormat::Draw(ERC* rc) {
    if (m_field20 == 1) {
        void* machine = m_machine;
        void* wrapper = *(void**)((u8*)machine + 0x98);
        // Virtual draw call
        void** vtable = *(void***)((u8*)wrapper + 0x80);
        s16 offset = *(s16*)((u8*)vtable + 0x30);
        void* func = *(void**)((u8*)vtable + 0x34);
        void* thisAdj = (void*)((u8*)wrapper + offset);
        typedef void (*DrawFn)(void*, ERC*);
        ((DrawFn)func)(thisAdj, rc);
    }
}

// 0x80091a7c | 116 bytes
void MUStatesSlotSelectSave::Update(float dt) {
    void* machine = m_machine;
    int state = *(int*)((u8*)machine + 0x90);
    if (state == 0) {
        s_muStateData.m_field00 = 0;
        s_muStateData.m_field08 = 0;
        MUStates_TransitionState(machine, 2);
    } else if (state == 1) {
        MUStates_TransitionState(machine, 1);
    } else if (state == 2) {
        MUStates_TransitionState(machine, 2);
    }
}

// 0x80091af0 | 136 bytes
void MUStatesSlotSelectSaveNoSkip::Update(float dt) {
    void* machine = m_machine;
    int state = *(int*)((u8*)machine + 0x90);
    if (state == 0) {
        // Setup wrapper with mode 7 and style 9
        void* wrapper = *(void**)((u8*)machine + 0x98);
        *(int*)((u8*)wrapper + 0xAC) = 7;
        Wrapper_SetItemStyle(wrapper, 9);
        MUStates_ChangeState(this, 14);
    } else if (state == 1) {
        MUStates_TransitionState(machine, 1);
    } else if (state == 2) {
        MUStates_TransitionState(machine, 2);
    }
}

// 0x800922f4 | 76 bytes
void MUStatesSaveNewGame::Draw(ERC* rc) {
    int state = m_field1C;
    if ((unsigned int)(state - 7) <= 2) {
        // Draw wrapper
        void* machine = m_machine;
        void* wrapper = *(void**)((u8*)machine + 0x98);
        void** vtable = *(void***)((u8*)wrapper + 0x80);
        s16 offset = *(s16*)((u8*)vtable + 0x30);
        void* func = *(void**)((u8*)vtable + 0x34);
        void* thisAdj = (void*)((u8*)wrapper + offset);
        typedef void (*DrawFn)(void*, ERC*);
        ((DrawFn)func)(thisAdj, rc);
    }
}

// 0x800939dc | 84 bytes
// NON_MATCHING - complex SDA global access pattern
void MUStateMachine::SetupQuitToMainMenu() {
    int numPlayers = s_muStateData.m_field30;
    int field04 = s_muStateData.m_field04;
    // Global state setup
    void* globalState = (void*)&s_muStateData;  // lis r11,-32697; addi r10,r11,23428
    *(int*)((u8*)globalState + 0xA4) = 0;
    *(int*)((u8*)globalState + 0xA0) = field04;
    *(int*)((u8*)globalState + 0x9C) = 1;
    if (numPlayers == 2) {
        *(int*)((u8*)globalState + 0xA4) = 1;
    }
    int field34 = s_muStateData.m_field34;
    if (field34 == 2) {
        int val = *(int*)((u8*)globalState + 0xA4);
        *(int*)((u8*)globalState + 0xA4) = val | 2;
    }
}

// 0x80092ee4 | 120 bytes
void MUStatesTransitionSaveExistingGame::Draw(ERC* rc) {
    int state = m_field1C;
    if ((unsigned int)(state - 8) <= 1) {
        void* machine = m_machine;
        void* wrapper = *(void**)((u8*)machine + 0x98);
        // Clear animation flag
        *(int*)((u8*)wrapper + 0xC8) = 0;
        // Draw wrapper
        void** vtable = *(void***)((u8*)wrapper + 0x80);
        s16 offset = *(s16*)((u8*)vtable + 0x30);
        void* func = *(void**)((u8*)vtable + 0x34);
        void* thisAdj = (void*)((u8*)wrapper + offset);
        typedef void (*DrawFn)(void*, ERC*);
        ((DrawFn)func)(thisAdj, rc);
        // Set animation flag
        void* wrapper2 = *(void**)((u8*)m_machine + 0x98);
        *(int*)((u8*)wrapper2 + 0xC8) = 1;
    }
}

// 0x80093124 | 76 bytes
void MUStatesLoadConfig::Draw(ERC* rc) {
    int state = m_field1C;
    if ((unsigned int)(state - 1) <= 1) {
        void* machine = m_machine;
        void* wrapper = *(void**)((u8*)machine + 0x98);
        void** vtable = *(void***)((u8*)wrapper + 0x80);
        s16 offset = *(s16*)((u8*)vtable + 0x30);
        void* func = *(void**)((u8*)vtable + 0x34);
        void* thisAdj = (void*)((u8*)wrapper + offset);
        typedef void (*DrawFn)(void*, ERC*);
        ((DrawFn)func)(thisAdj, rc);
    }
}

// 0x8009320c | 68 bytes
void MUStatesDisplay::Update(float dt) {
    void* machine = m_machine;
    void* wrapper = *(void**)((u8*)machine + 0x98);
    if (wrapper != 0) {
        void** vtable = *(void***)((u8*)wrapper + 0x80);
        s16 offset = *(s16*)((u8*)vtable + 0x28);
        void* func = *(void**)((u8*)vtable + 0x2C);
        void* thisAdj = (void*)((u8*)wrapper + offset);
        typedef void (*UpdateFn)(void*);
        ((UpdateFn)func)(thisAdj);
    }
}

// 0x80093250 | 68 bytes
void MUStatesDisplay::Draw(ERC* rc) {
    void* machine = m_machine;
    void* wrapper = *(void**)((u8*)machine + 0x98);
    if (wrapper != 0) {
        void** vtable = *(void***)((u8*)wrapper + 0x80);
        s16 offset = *(s16*)((u8*)vtable + 0x30);
        void* func = *(void**)((u8*)vtable + 0x34);
        void* thisAdj = (void*)((u8*)wrapper + offset);
        typedef void (*DrawFn)(void*, ERC*);
        ((DrawFn)func)(thisAdj, rc);
    }
}

// 0x80093958 | 104 bytes
void MUStateMachine::MUWrapperShutdown() {
    void* wrapper = m_wrapper;
    if (wrapper != 0) {
        Wrapper_Shutdown(wrapper);
        // Virtual call to destroy wrapper
        if (wrapper != 0) {
            void** vtable = *(void***)((u8*)wrapper + 0x80);
            s16 offset = *(s16*)((u8*)vtable + 0x08);
            void* func = *(void**)((u8*)vtable + 0x0C);
            void* thisAdj = (void*)((u8*)wrapper + offset);
            typedef void (*DestroyFn)(void*, int);
            ((DestroyFn)func)(thisAdj, 3);
        }
        m_wrapper = 0;
    }
}

// 0x800936c0 | 216 bytes
// NON_MATCHING - complex initialization with multiple globals
void MUStateMachine::Reset() {
    s_muStateData.m_field00 = 0;
    s_muStateData.m_field3C = 0;
    s_muStateData.m_field34 = 1;
    s_muStateData.m_field04 = 0;
    s_muStateData.m_field08 = 0;
    s_muStateData.m_field0C = 1;
    s_muStateData.m_field28 = 0;
    s_muStateData.m_field2C = 0;
    s_muStateData.m_field30 = 1;
    s_muStateData.m_field38 = 0;
    // Clear fields 0x24 down through 0x20 (small loop)
    s_muStateData.m_field24 = 0;
    s_muStateData.m_field20 = 0;

    s_muStateData.m_field40 = 0;
    // Init string buffers
    static const char emptyStr[] = "";
    EAString_Init((char*)&s_muStateData.m_field10, emptyStr);
    EAString_Init((char*)&s_muStateData.m_field14, emptyStr);
    EAString_Init((char*)&s_muStateData.m_field18, emptyStr);
    EAString_Init((char*)&s_muStateData.m_field1C, emptyStr);
    // Set update rate
    MUStateMachine_SetUpdateRate(this, 0.0f, 0);
    // Clear global flag
    // stw r28, -21360(r13) => s_muResetFlag = 0
}

// 0x80093b3c | 144 bytes
MUStateMachine::~MUStateMachine() {
    // Set vtable to MUStateMachine's vtable
    *(void**)((u8*)this + 0x18) = (void*)0x8045E100;  // approximate vtable addr
    // Clear vector
    Vector_Clear((u8*)this + 0x54, 2);
    // Free vector buffer
    void* begin = *(void**)((u8*)this + 0x2C);
    if (begin != 0) {
        void* end = *(void**)((u8*)this + 0x2C + 0x0C);
        int size = (int)((u8*)end - (u8*)begin);
        size &= ~3;  // align to 4
        if (size > 128) {
            operator_delete(begin);
        } else {
            SmallBlockAllocator_Free(begin);
        }
    }
    // Set base vtable
    *(void**)((u8*)this + 0x18) = (void*)0x8045C9C8;  // base vtable
    // If flag set, delete self
    // (destructor flag handling)
}

// 0x80093f24 | 72 bytes
MUStatesSaveNewGame::MUStatesSaveNewGame(int arg) {
    m_field00 = arg;
    // Initialize fields
    *(int*)((u8*)this + 0x0C) = -1;
    *(int*)((u8*)this + 0x10) = 0;
    *(int*)((u8*)this + 0x14) = 1;
    *(void**)((u8*)this + 0x18) = (void*)0x8045DC38;  // vtable
    *(int*)((u8*)this + 0x04) = -1;
    *(int*)((u8*)this + 0x08) = 0;
    // Load float constant
    *(float*)((u8*)this + 0x34) = 0.0f;
    *(float*)((u8*)this + 0x30) = 0.0f;
}
#endif
