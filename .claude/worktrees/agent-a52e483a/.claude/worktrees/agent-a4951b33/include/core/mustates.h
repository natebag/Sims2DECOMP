#ifndef MUSTATES_H
#define MUSTATES_H

#include "types.h"

// Forward declarations
class ERC;
class MUWrapper;

// MUState base struct - all MUStates* classes share this layout
// Layout (from constructor analysis):
//   0x00: int m_smIndex         (set to constructor param)
//   0x04: int m_field04         (set to -1)
//   0x08: int m_field08         (set to 0)
//   0x0C: int m_field0C         (set to -1)
//   0x10: int m_field10         (set to 0)
//   0x14: int m_field14         (set to 1)
//   0x18: void* m_vtable        (vtable pointer)
struct MUStateBase {
    int m_smIndex;       // 0x00
    int m_field04;       // 0x04
    int m_field08;       // 0x08
    int m_field0C;       // 0x0C
    int m_field10;       // 0x10
    int m_field14;       // 0x14
    void* m_vtable;      // 0x18 - vtable ptr
    int m_field1C;       // 0x1C - used by Reset functions
    int m_field20;       // 0x20 - used by some Reset functions
    int m_field24;       // 0x24
    int m_field28;       // 0x28
    int m_field2C;       // 0x2C
    float m_field30;     // 0x30 - used by MUStatesSaveNewGame
    float m_field34;     // 0x34 - used by MUStatesSaveNewGame
};

// MUStateMachine - manages the memory unit state machine
// Layout:
//   0x00-0x3B: StateMachine base (includes states array)
//   0x3C: some data structure
//   0x98: MUWrapper* m_pMUWrapper
class MUStateMachine {
public:
    enum eMURequest {
        // Request values 1-8 based on the cmplwi r0,7 check
    };

    // Sizes are inferred from data access patterns
    u8 _pad00[0x98];
    MUWrapper* m_pMUWrapper;      // 0x98

    MUStateMachine(int param1, int param2);
    ~MUStateMachine();

    void Startup();
    void Shutdown();
    void Reset();
    void Update(float dt);
    void Draw(ERC* rc);

    eMURequest MURequest(eMURequest request);   // 52 bytes - static, uses r13 globals
    eMURequest MUPollForResult(eMURequest request); // 28 bytes - static, uses r13 globals

    void MUWrapperStartup();
    void MUWrapperShutdown();
    void SetupQuitToMainMenu();

    // Simple accessors (all use r13-relative globals)
    static eMURequest GetCurRequest();      // 8 bytes
    static void ClearResult();              // 12 bytes
    static void SetHouseNumber(int num);    // 8 bytes
    static int GetHouseNumber();            // 8 bytes
    MUWrapper* GetMUWrapper();              // 8 bytes - member access
};

// UIObjectBase - forward declare for state machine member
class UIObjectBase {
public:
    u8 _pad[0x08];
    MUStateMachine* m_pStateMachine;  // 0x08
};

// All MUStates* subclasses share the same constructor/destructor/GetWrapper pattern
// The only difference is the vtable pointer loaded in the constructor

class MUStatesProcessRequests {
public:
    MUStatesProcessRequests(int smIndex);
    ~MUStatesProcessRequests();
    MUWrapper* GetWrapper();
    void Update(float dt);
};

class MUStatesFormat {
public:
    MUStatesFormat(int smIndex);
    ~MUStatesFormat();
    MUWrapper* GetWrapper();
    void Reset();
    void Draw(ERC* rc);
    void Update(float dt);
};

class MUStatesSlotSelectSave {
public:
    MUStatesSlotSelectSave(int smIndex);
    ~MUStatesSlotSelectSave();
    MUWrapper* GetWrapper();
    void Update(float dt);
};

class MUStatesSlotSelectSaveNoSkip {
public:
    MUStatesSlotSelectSaveNoSkip(int smIndex);
    ~MUStatesSlotSelectSaveNoSkip();
    MUWrapper* GetWrapper();
    void Update(float dt);
};

class MUStatesLoadGame {
public:
    MUStatesLoadGame(int smIndex);
    ~MUStatesLoadGame();
    MUWrapper* GetWrapper();
    void Reset();
    void Draw(ERC* rc);
    void Update(float dt);
};

class MUStatesLoadHouse {
public:
    MUStatesLoadHouse(int smIndex);
    ~MUStatesLoadHouse();
    MUWrapper* GetWrapper();
    void Reset();
    void Draw(ERC* rc);
    void Update(float dt);
};

class MUStatesAutoSaveNew {
public:
    MUStatesAutoSaveNew(int smIndex);
    ~MUStatesAutoSaveNew();
    MUWrapper* GetWrapper();
    void Update(float dt);
};

class MUStatesSaveNewGame {
public:
    MUStatesSaveNewGame(int smIndex);
    ~MUStatesSaveNewGame();
    MUWrapper* GetWrapper();
    void Reset();
    void Draw(ERC* rc);
    void Update(float dt);
};

class MUStatesAutoSaveExisting {
public:
    MUStatesAutoSaveExisting(int smIndex);
    ~MUStatesAutoSaveExisting();
    MUWrapper* GetWrapper();
    void Reset();
    void Update(float dt);
};

class MUStatesSaveExistingGame {
public:
    MUStatesSaveExistingGame(int smIndex);
    ~MUStatesSaveExistingGame();
    MUWrapper* GetWrapper();
    void Reset();
    void Draw(ERC* rc);
    void Update(float dt);
};

class MUStatesTransitionAutoSaveExisting {
public:
    MUStatesTransitionAutoSaveExisting(int smIndex);
    ~MUStatesTransitionAutoSaveExisting();
    MUWrapper* GetWrapper();
    void Reset();
    void Update(float dt);
};

class MUStatesTransitionSaveExistingGame {
public:
    MUStatesTransitionSaveExistingGame(int smIndex);
    ~MUStatesTransitionSaveExistingGame();
    MUWrapper* GetWrapper();
    void Reset();
    void Draw(ERC* rc);
    void Update(float dt);
};

class MUStatesLoadConfig {
public:
    MUStatesLoadConfig(int smIndex);
    ~MUStatesLoadConfig();
    MUWrapper* GetWrapper();
    void Reset();
    void Update(float dt);
};

class MUStatesDisplay {
public:
    MUStatesDisplay(int smIndex);
    ~MUStatesDisplay();
    MUWrapper* GetWrapper();
    void Startup();
    void Shutdown();
    void Reset();
    void Update(float dt);
    void Draw(ERC* rc);
};

// Thread polling functions
extern "C" {
    int THREADPOLL_MU_IsComplete(void);
    void THREADPOLL_MU_Start(void);
    void THREADPOLL_MU_End(void);
}

// Thread exec function
void THREADEXEC_MU_SaveNewGame(void);

// External functions referenced by mustates
void operator delete(void* ptr);

#endif // MUSTATES_H
