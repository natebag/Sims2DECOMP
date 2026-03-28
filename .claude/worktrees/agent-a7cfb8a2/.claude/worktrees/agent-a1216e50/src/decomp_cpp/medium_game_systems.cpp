// medium_game_systems.cpp - Game system stubs (101-500 lines)
// MUStates, Objects, IFF, CAS, Passive influence, Logging, Player, PlumbBob, Motives,
// cXObject, cXPerson, cXMTObject, Audio, Memory pools, Camera, State machines, etc.
// Converted from PPC inline asm to portable C++
#include "types.h"

// ============================================================
// Forward declarations
// ============================================================
class ERC;
class EAHeap;
class BString;
class BString2;
class Career;
class CasEvent;
class CasListener;
class EController;
class EAnimController;
class EIStaticModel;
class EMat4;
class EShader;
class EMutex;
class EVec3;
class CTilePt;
class ReconBuffer;
class StringBuffer;
class ObjectDataID;
class ObjectDataBehaviorTree;
class SlotDescriptor;
class WrapperPaneBase;
class BehaviorFinder;
class iResFile;
class ObjSelector;
class CameraDirector;
class Neighbor;
class FAMTarget;
class UIObjectBase;
class CLoadingScreen;
class FlashPiMenu;
class ESimsCam;
class AptViewer;
class cXObject;
class cXObjectImpl;

extern "C" {
    void* memcpy(void*, const void*, unsigned int);
    void* memset(void*, int, unsigned int);
    void* memmove(void*, const void*, unsigned int);
    int strcmp(const char*, const char*);
    unsigned short* wcscpy(unsigned short*, const unsigned short*);
}

extern EAHeap* MainHeap();
extern void* __builtin_new(unsigned int);
extern void __builtin_delete(void*);
extern void* __builtin_vec_new(unsigned int);
extern void __builtin_vec_delete(void*);

// ============================================================
// MU State Machine States
// ============================================================

// --- MUStateMachine / MUWrapper / StateMachine support ---

class StateMachine {
public:
    int m_stateId;               // +0x90 = 144
    void* m_wrapper;             // +0x98 = 152
    void ReturnFromState(int);
    float GetTimeInState() const;
};

class StateMachineState {
public:
    void* m_padding[2];          // +0x00
    StateMachine* m_owner;       // +0x08
    int m_field1C;               // +0x1C = 28
    int m_field20;               // +0x20 = 32
    float m_field24;             // +0x24 = 36
    void OwnerCallState(int);
    void OwnerReturnFromState(int);
    void OwnerSetNextState(int, float);
};

class SimsMemCardWrap;
extern SimsMemCardWrap* g_pSimsMemCardWrap; // global at lis -32696, offset 22744

class MUWrapper {
public:
    void* m_vtable;              // +0x80 = 128
    int m_displayMode;           // +0xAC = 172
    int m_field_C8;              // +0xC8 = 200
    void SetDisplayOkType(int);
    void SetQueryType(int);
    void SetInfoType(int);
    void Reset();
    void CleanUp();
};

class MUStateMachine : public StateMachine {
public:
    void SetupQuitToMainMenu();
};

class StateMachineManager {
public:
    static StateMachine* FindMachineById(int);
};

class SimsMemCardWrap {
public:
    int IsCardInSlot(int, bool&);
    int IsWrongDevice(int, bool&);
    int IsCardDamaged(int, bool&);
    int IsCardCorrupted(int, bool&);
    int IsCardFormatted(int, bool&);
    int HasSavedGame(int, bool&, int);
    int HasInvalidGame(int, bool&, int);
    int IsDifferentCard(int, bool&);
    int HasSpaceForSave(int, bool&, unsigned int*);
    int FormatCard(int);
    int LoadGame(int, int);
    int LoadHouse(int);
    int SaveGame(int, bool, bool, int);
};

// --- MUStatesAutoSaveExisting ---

class MUStatesAutoSaveExisting : public StateMachineState {
public:
    void Update(float);
};

// 0x80092998
void MUStatesAutoSaveExisting::Update(float dt) {
    StateMachine* owner = m_owner;
    int state = owner->m_stateId;
    MUWrapper* wrapper = (MUWrapper*)owner->m_wrapper;

    if (state == 0) {
        OwnerCallState(8);
        m_field1C = 1;
    } else if (state == 1) {
        if (m_field1C == 1) {
            bool cardIn = false;
            g_pSimsMemCardWrap->IsCardInSlot(0, cardIn);
            if (!cardIn) {
                wrapper->m_displayMode = 6;
                wrapper->SetDisplayOkType(18);
            } else {
                m_field20++;
                if (m_field20 > 3) {
                    wrapper->m_displayMode = 5;
                    wrapper->SetQueryType(12);
                    OwnerCallState(14);
                    m_field1C = 3;
                    return;
                } else {
                    wrapper->m_displayMode = 6;
                    wrapper->SetDisplayOkType(7);
                }
            }
            OwnerCallState(14);
            m_field1C = 2;
        } else if (m_field1C == 3) {
            ((MUStateMachine*)m_owner)->SetupQuitToMainMenu();
            m_owner->ReturnFromState(1);
        }
    } else if (state == 2) {
        if (m_field1C == 1) {
            m_owner->ReturnFromState(2);
        } else if (m_field1C == 2 || m_field1C == 3) {
            owner->m_stateId = 0;
        }
    }
}

// --- MUStatesAutoSaveNew ---

class MUStatesAutoSaveNew : public StateMachineState {
public:
    void Update(float);
};

// 0x8009217C
void MUStatesAutoSaveNew::Update(float dt) {
    StateMachine* owner = m_owner;
    int state = owner->m_stateId;

    if (state == 0) {
        // Complex memory card slot initialization logic
        owner->ReturnFromState(2);
    } else if (state == 1) {
        MUWrapper* wrapper = (MUWrapper*)owner->m_wrapper;
        if (m_field1C == 1) {
            OwnerCallState(11);
            m_field1C = 2;
        } else if (m_field1C == 2) {
            wrapper->m_displayMode = state;
            wrapper->SetQueryType(5);
            OwnerCallState(14);
            m_field1C = 3;
        } else if (m_field1C == 3) {
            owner->m_stateId = 0;
        }
    } else if (state == 2) {
        if (m_field1C == 1) {
            // Slot selection logic
            owner->ReturnFromState(2);
        } else if (m_field1C == 2) {
            owner->m_stateId = 0;
        } else if (m_field1C == 3) {
            owner->ReturnFromState(1);
        }
    }
}

// --- MUStatesFormat ---

class MUStatesFormat : public StateMachineState {
public:
    void Reset();
    void Draw(ERC*);
    void Update(float);
};

// 0x800916F8
void MUStatesFormat::Reset() {
    m_field1C = 0;
    m_field20 = 0;
    MUWrapper* wrapper = (MUWrapper*)m_owner->m_wrapper;
    wrapper->m_displayMode = 2;
    wrapper->SetQueryType(17);
    OwnerCallState(14);
    m_field20 = 0;
    m_field1C = 1;
}

// 0x80091764
void MUStatesFormat::Draw(ERC* rc) {
    if (m_field20 == 1) {
        MUWrapper* wrapper = (MUWrapper*)m_owner->m_wrapper;
        // Call vtable draw method via wrapper->m_vtable offset 48/52
        // (indirect virtual call through vtable)
    }
}

// 0x800917AC
void MUStatesFormat::Update(float dt) {
    StateMachine* owner = m_owner;
    int mainState = owner->m_stateId;
    MUWrapper* wrapper = (MUWrapper*)owner->m_wrapper;

    if (mainState == 0) {
        bool cardIn = false;
        g_pSimsMemCardWrap->IsCardInSlot(0, cardIn);
        if (!cardIn) {
            owner->ReturnFromState(1);
            return;
        }
        if (m_field1C == 1) {
            // Already formatted, skip
        } else {
            wrapper->m_displayMode = 4;
            wrapper->SetQueryType(10);
            OwnerCallState(14);
            m_field20 = 0;
            m_field1C = 2;
        }
    } else if (mainState == 1) {
        int sub = m_field1C;
        if (sub == 1 || sub == 2) {
            wrapper->m_displayMode = 3;
            wrapper->SetQueryType(6);
            OwnerCallState(14);
            m_field1C = 3;
        } else if (sub == 3) {
            owner->m_stateId = 0;
        }
    } else if (mainState == 2) {
        if (m_field1C == 1) {
            wrapper->m_displayMode = 4;
            wrapper->SetQueryType(10);
            OwnerCallState(14);
            m_field1C = 2;
            m_field20 = 0;
        } else if (m_field1C == 2) {
            wrapper->m_displayMode = 8;
            wrapper->SetInfoType(4);
            wrapper->Reset();
            m_field1C = 6;
            m_field20 = 1;
        } else if (m_field1C == 6) {
            float t = owner->GetTimeInState();
            // Wait for time threshold, then format
            bool formatOk = false;
            int result = g_pSimsMemCardWrap->FormatCard(0);
            if (result == 1) {
                formatOk = true;
                bool isFormatted = false;
                g_pSimsMemCardWrap->IsCardFormatted(0, isFormatted);
                if (!isFormatted) formatOk = false;
            }
            m_field20 = 0;
            if (formatOk) {
                wrapper->m_displayMode = 6;
                wrapper->SetDisplayOkType(4);
                OwnerCallState(14);
                m_field1C = 5;
            } else {
                wrapper->m_displayMode = 6;
                wrapper->SetDisplayOkType(3);
                OwnerCallState(14);
                m_field1C = 4;
            }
        } else if (m_field1C == 3 || m_field1C == 7) {
            owner->ReturnFromState(1);
        } else if (m_field1C == 5) {
            owner->ReturnFromState(2);
        } else if (m_field1C == 4) {
            owner->ReturnFromState(1);
            owner->m_stateId = 0;
        }
    } else if (mainState == 3) {
        m_field1C = 0;
        owner->m_stateId = 0;
    }
}

// --- MUStatesLoadGame ---

class MUStatesLoadGame : public StateMachineState {
public:
    void Update(float);
};

// 0x80091B88
void MUStatesLoadGame::Update(float dt) {
    StateMachine* owner = m_owner;
    int mainState = owner->m_stateId;
    MUWrapper* wrapper = (MUWrapper*)owner->m_wrapper;

    if (mainState == 0) {
        int sub = m_field1C;
        if (sub == 0 || sub == 12) {
            bool cardIn = false;
            g_pSimsMemCardWrap->IsCardInSlot(0, cardIn);
            if (!cardIn) {
                wrapper->m_displayMode = 6;
                wrapper->SetDisplayOkType(6);
                OwnerCallState(14);
                m_field1C = 1;
                return;
            }
            if (sub == 12) m_field1C = 0;
            // Check for wrong device, damaged, corrupted, formatted, has save, etc.
            bool wrongDevice = false;
            g_pSimsMemCardWrap->IsWrongDevice(0, wrongDevice);
            if (wrongDevice) {
                wrapper->m_displayMode = 9;
                wrapper->SetDisplayOkType(24);
                OwnerCallState(14);
                m_field1C = 10;
                return;
            }
            // Additional card checks...
        } else if (sub == 8) {
            int loadResult = g_pSimsMemCardWrap->LoadGame(0, 0x00AB34EF);
            bool failed = true;
            if (loadResult == 1) failed = false;
            if (failed) {
                wrapper->m_displayMode = 6;
                wrapper->SetDisplayOkType(9);
                OwnerCallState(14);
                m_field1C = 7;
            } else {
                m_field1C = 13;
            }
        } else if (sub == 13) {
            // Timer countdown for load completion
            float* timer = (float*)&m_field20;
            *timer -= dt;
            if (*timer <= 0.0f) {
                owner->ReturnFromState(2);
            }
        }
    } else if (mainState == 2) {
        int sub = m_field1C;
        if ((sub >= 1 && sub <= 6) || sub == 11 || sub == 7) {
            owner->ReturnFromState(1);
        } else if (sub == 10) {
            m_field1C = 0;
            owner->m_stateId = 0;
        }
    }
}

// --- MUStatesLoadHouse ---

class MUStatesLoadHouse : public StateMachineState {
public:
    void Update(float);
};

// 0x8009201C
void MUStatesLoadHouse::Update(float dt) {
    StateMachine* owner = m_owner;
    int mainState = owner->m_stateId;

    if (mainState == 0) {
        int sub = m_field1C;
        if (sub == 0) {
            m_field1C = 8;
            *(float*)&m_field20 = 0.5f; // Load timer
        } else if (sub == 8) {
            float* timer = (float*)&m_field20;
            *timer -= dt;
            if (*timer <= 0.0f) {
                m_field1C = 9;
            }
        } else if (sub == 9) {
            // LoadHouse via SimsMemCardWrap
            m_field1C = 10;
        } else if (sub == 10) {
            float* timer = (float*)&m_field20;
            *timer -= dt;
            if (*timer <= 0.0f) {
                owner->ReturnFromState(2);
            }
        }
    } else if (mainState == 2) {
        int sub = m_field1C;
        if (sub == 1 || sub == 11 || sub == 2 || sub == 3 || sub == 4 ||
            sub == 5 || sub == 6 || sub == 13 || sub == 7) {
            owner->ReturnFromState(1);
        } else if (sub == 12) {
            m_field1C = 0;
            owner->m_stateId = 0;
        }
    }
}

// --- MUStatesProcessRequests ---

class MUStatesProcessRequests : public StateMachineState {
public:
    void Update(float);
};

// 0x80091464
void MUStatesProcessRequests::Update(float dt) {
    StateMachine* owner = m_owner;
    int state = owner->m_stateId;

    if (state == 0) {
        m_field1C = 0;
    } else if (state == 2) {
        if (m_field1C == 1) {
            m_field1C = 0;
        }
        // Reset state and return
        owner->m_stateId = 0;
    } else if (state == 1) {
        if (m_field1C == 1) {
            // Already processed
        }
        // Dispatch to appropriate sub-state based on request type
    }
}

// --- MUStatesSaveExistingGame ---

class MUStatesSaveExistingGame : public StateMachineState {
public:
    void Update(float);
};

// 0x80092B18
void MUStatesSaveExistingGame::Update(float dt) {
    StateMachine* owner = m_owner;
    int mainState = owner->m_stateId;
    MUWrapper* wrapper = (MUWrapper*)owner->m_wrapper;

    if (mainState == 0) {
        int sub = m_field1C;
        if (sub == 0) {
            // Check wrong device
            bool wrongDevice = false;
            g_pSimsMemCardWrap->IsWrongDevice(0, wrongDevice);
            if (wrongDevice) {
                wrapper->m_displayMode = 9;
                wrapper->SetDisplayOkType(24);
                OwnerCallState(14);
                m_field1C = 11;
            } else {
                m_field1C = 8;
            }
        } else if (sub == 8) {
            // Save game
            int result = g_pSimsMemCardWrap->SaveGame(0, false, false, 0x00AB34EF);
            if (result == 1) {
                // Save succeeded - set timer
                m_field1C = 9;
            } else {
                // Save failed
                wrapper->m_displayMode = 6;
                wrapper->SetDisplayOkType(10);
                OwnerCallState(14);
                m_field1C = 7;
            }
        } else if (sub == 9) {
            // Timer countdown
            float* timer = (float*)&m_field20;
            *timer -= dt;
            if (*timer <= 0.0f) {
                owner->ReturnFromState(2);
            }
        }
    } else if (mainState == 1) {
        if (m_field1C == 1) {
            owner->ReturnFromState(1);
        }
    } else if (mainState == 2) {
        int sub = m_field1C;
        if (sub == 1 || sub == 11) {
            m_field1C = 0;
            owner->m_stateId = 0;
        } else if (sub == 2 || sub == 10 || sub == 3 || sub == 4 ||
                   sub == 5 || sub == 6 || sub == 12 || sub == 7) {
            owner->ReturnFromState(1);
        }
    }
}

// --- MUStatesSaveNewGame ---

class MUStatesSaveNewGame : public StateMachineState {
public:
    float m_timer;               // +0x24 = 36
    void Draw(ERC*);
    void Update(float);
};

// 0x800922F4
void MUStatesSaveNewGame::Draw(ERC* rc) {
    int sub = m_field1C;
    if (sub >= 9 && sub <= 11) {
        MUWrapper* wrapper = (MUWrapper*)m_owner->m_wrapper;
        // Call vtable draw method
    }
}

// 0x80092340
void MUStatesSaveNewGame::Update(float dt) {
    StateMachine* owner = m_owner;
    int mainState = owner->m_stateId;
    MUWrapper* wrapper = (MUWrapper*)owner->m_wrapper;

    if (mainState == 0) {
        int sub = m_field1C;
        if (sub == 0) {
            // Card checks and save flow
            bool cardIn = false;
            g_pSimsMemCardWrap->IsCardInSlot(0, cardIn);
            if (!cardIn) {
                wrapper->m_displayMode = 1;
                wrapper->SetQueryType(3);
                OwnerCallState(14);
                m_field1C = 1;
            }
            // More card validation checks...
        }
    } else if (mainState == 1) {
        int sub = m_field1C;
        if (sub == 1 || sub == 4 || sub == 6 || sub == 15 || sub == 5 || sub == 7) {
            owner->ReturnFromState(1);
        }
    } else if (mainState == 2) {
        int sub = m_field1C;
        if (sub == 1 || sub == 5) {
            m_field1C = 0;
            owner->m_stateId = 0;
        } else if (sub == 7) {
            owner->ReturnFromState(1);
        }
        // Additional sub-state handling...
    } else if (mainState == 3) {
        if (m_field1C == 4) {
            wrapper->m_displayMode = 6;
            wrapper->SetDisplayOkType(6);
            OwnerCallState(14);
            m_field1C = 16;
        } else {
            owner->ReturnFromState(1);
        }
    }
}

// --- MUStatesTransitionAutoSaveExisting ---

class MUStatesTransitionAutoSaveExisting : public StateMachineState {
public:
    void Update(float);
};

// 0x80092D54
void MUStatesTransitionAutoSaveExisting::Update(float dt) {
    StateMachine* owner = m_owner;
    int mainState = owner->m_stateId;
    MUWrapper* wrapper = (MUWrapper*)owner->m_wrapper;

    if (mainState == 0) {
        OwnerCallState(10);
        m_field1C = 1;
    } else if (mainState == 1) {
        if (m_field1C == 1) {
            // Find state machine, set flags, check card
            bool cardIn = false;
            wrapper->m_displayMode = 6;
            g_pSimsMemCardWrap->IsCardInSlot(0, cardIn);
            if (!cardIn) {
                wrapper->SetDisplayOkType(18);
            } else {
                m_field20++;
                if (m_field20 > 3) {
                    wrapper->m_displayMode = 5;
                    wrapper->SetQueryType(12);
                    OwnerCallState(14);
                    m_field1C = 3;
                    return;
                }
                wrapper->SetDisplayOkType(7);
            }
            OwnerCallState(14);
            m_field1C = 2;
        } else if (m_field1C == 3) {
            ((MUStateMachine*)m_owner)->SetupQuitToMainMenu();
            owner->ReturnFromState(1);
        }
    } else if (mainState == 2) {
        if (m_field1C == 1) {
            owner->ReturnFromState(2);
        } else if (m_field1C == 2 || m_field1C == 3) {
            owner->m_stateId = 0;
        }
    }
}

// --- MUStatesTransitionSaveExistingGame ---

class MUStatesTransitionSaveExistingGame : public StateMachineState {
public:
    void Draw(ERC*);
    void Update(float);
};

// 0x80092EE4
void MUStatesTransitionSaveExistingGame::Draw(ERC* rc) {
    int sub = m_field1C;
    if (sub == 8 || sub == 9) {
        MUWrapper* wrapper = (MUWrapper*)m_owner->m_wrapper;
        wrapper->m_field_C8 = 0;
        // Call vtable draw
        wrapper->m_field_C8 = 1;
    }
}

// 0x80092F5C
void MUStatesTransitionSaveExistingGame::Update(float dt) {
    StateMachine* owner = m_owner;
    int mainState = owner->m_stateId;
    MUWrapper* wrapper = (MUWrapper*)owner->m_wrapper;

    if (mainState == 0) {
        int sub = m_field1C;
        if (sub == 0) {
            int result = g_pSimsMemCardWrap->SaveGame(0, false, false, 0x00AB34EF);
            if (result == 1) {
                owner->ReturnFromState(2);
            }
        } else if (sub == 8) {
            // Find machine, set flags
            m_field1C = 9;
        } else if (sub == 9) {
            float* timer = (float*)&m_field20;
            *timer -= dt;
            if (*timer <= 0.0f) {
                // Retry save
                int result = g_pSimsMemCardWrap->SaveGame(0, false, false, 0x00AB34EF);
                if (result == 1) {
                    owner->ReturnFromState(2);
                } else {
                    wrapper->m_displayMode = 6;
                    wrapper->SetDisplayOkType(10);
                    OwnerCallState(14);
                    m_field1C = 7;
                }
            }
        }
    } else if (mainState == 2) {
        int sub = m_field1C;
        if (sub == 1 || sub == 11) {
            m_field1C = 0;
            owner->m_stateId = 0;
        } else if (sub == 10 || sub == 2 || sub == 3 || sub == 4 ||
                   sub == 5 || sub == 6 || sub == 12 || sub == 7) {
            owner->ReturnFromState(1);
        }
    }
}

// ============================================================
// Object System
// ============================================================

// --- ObjectList ---

class ObjectList {
public:
    cXObject** m_begin;      // +0x00
    cXObject** m_end;        // +0x04
    int m_field08;           // +0x08
    cXObject** m_capacity;   // +0x0C

    void AddObject(cXObject*);
    void RemoveObject(cXObject*);
    void RemoveAll();
};

// 0x80048590
void ObjectList::AddObject(cXObject* obj) {
    // Check if already in list
    for (cXObject** it = m_begin; it != m_end; ++it) {
        if (*it == obj) return;
    }
    // If space available, append
    if (m_end != m_capacity) {
        *m_end = obj;
        m_end++;
        return;
    }
    // Need to grow: reallocate and copy
    int curSize = (int)(m_end - m_begin);
    int growth = (curSize >= 1) ? curSize : 1;
    int newSize = curSize + growth;
    int newBytes = newSize * 4;
    cXObject** newBuf;
    if (newBytes > 0) {
        if (newBytes > 128)
            newBuf = (cXObject**)__builtin_new(newBytes);
        else
            newBuf = (cXObject**)__builtin_new(newBytes); // pool alloc
    } else {
        newBuf = 0;
        newBytes = 0;
    }
    // Copy existing
    cXObject** dst = newBuf;
    if (m_end != m_begin) {
        int copyBytes = (int)((char*)m_end - (char*)m_begin);
        memmove(newBuf, m_begin, copyBytes);
        dst = (cXObject**)((char*)newBuf + copyBytes);
    }
    // Insert new element
    *dst = obj;
    dst++;
    // Free old buffer
    if (m_begin) {
        int oldBytes = (int)((char*)m_capacity - (char*)m_begin);
        if (oldBytes > 128)
            __builtin_delete(m_begin);
    }
    m_begin = newBuf;
    m_capacity = (cXObject**)((char*)newBuf + newBytes);
    m_end = dst;
}

// 0x80048714
void ObjectList::RemoveObject(cXObject* obj) {
    for (cXObject** it = m_begin; it != m_end; ++it) {
        if (*it == obj) {
            cXObject** next = it + 1;
            if (next != m_end) {
                memmove(it, next, (char*)m_end - (char*)next);
            }
            m_end--;
            return;
        }
    }
}

// 0x80048798
void ObjectList::RemoveAll() {
    // Swap with empty list and free
    cXObject** oldBegin = m_begin;
    cXObject** oldEnd = m_end;
    m_begin = 0;
    m_end = 0;
    // Free old buffer
    if (oldBegin) {
        int bytes = (int)((char*)m_capacity - (char*)oldBegin);
        bytes &= ~3;
        if (bytes > 128)
            __builtin_delete(oldBegin);
    }
}

// --- ObjectSlot ---

struct StdHeight { int value; };

class ObjectSlot {
public:
    void* m_vtable;              // +0x00
    short m_field04;             // +0x04
    int m_field08;               // +0x08 height type
    int m_field0C;               // +0x0C
    int m_field10;               // +0x10
    float m_field14;             // +0x14
    float m_field18;             // +0x18
    float m_field1C;             // +0x1C height value

    ObjectSlot();
    ObjectSlot(SlotDescriptor*);
    void SetHeight(int heightType);
};

// Slot base class
class Slot {
public:
    Slot();
    Slot(SlotDescriptor*);
};

// 0x80142C40
ObjectSlot::ObjectSlot() {
    // Call Slot base ctor (implicit)
    m_field1C = 0.0f;
    m_field04 = 0;
    m_field0C = 50;
    m_field08 = 0;
    m_field14 = 0.0f;
    m_field18 = 0.0f;
    m_field10 = 0;
}

// 0x80142D64
void ObjectSlot::SetHeight(int heightType) {
    m_field08 = heightType;
    switch (heightType) {
        case 0:
            if (m_field1C == 0.0f) {
                m_field08 = 1;
            } else {
                m_field08 = 5;
            }
            break;
        case 1:
            m_field1C = 0.0f; // kFloorHeight
            break;
        case 2:
            m_field1C = 3.0f; // kTableHeight
            break;
        case 3:
        case 4:
        case 8:
            m_field1C = 6.0f; // kCounterHeight
            break;
        default:
            break;
    }
}

// --- ObjectDataBehaviorConstants ---

class ObjectDataBehaviorConstants {
public:
    void* m_vtable;              // +0x00
    short m_field04;             // +0x04
    // ObjectDataID at +0x08
    int m_field08;               // +0x08
    int m_field0C;               // +0x0C
    BString* m_names;            // +0x10
    unsigned short* m_values;    // +0x14

    ObjectDataBehaviorConstants();
    ObjectDataBehaviorConstants(ObjectDataBehaviorConstants&);
    ~ObjectDataBehaviorConstants();
    void SetValueCount(int);
    int CountValues() const;
    bool IsTuning() const;
    void SetIsTuning(bool);
};

// 0x80159A2C
ObjectDataBehaviorConstants::ObjectDataBehaviorConstants() {
    m_field04 = 0;
    // ObjectDataID ctor(-1, 0) at +8
    m_values = 0;
    m_names = 0;
}

// 0x80159B5C
ObjectDataBehaviorConstants::~ObjectDataBehaviorConstants() {
    if (m_values) {
        __builtin_vec_delete(m_values);
        m_values = 0;
    }
    if (m_names) {
        // Destruct each BString in reverse
        __builtin_vec_delete(m_names);
        m_names = 0;
    }
}

// --- ObjectDataBehaviorTree ---

class ObjectDataBehaviorTree2 {
public:
    void* m_vtable;              // +0x00
    short m_field04;             // +0x04
    int m_field08;               // +0x08
    char m_resourceName[64];     // +0x14 (StringBuffer at +0x0C)
    void* m_nodeData;            // +0x54
    // ObjectDataID at +0x58

    ObjectDataBehaviorTree2();
    int GetNumParams() const;
    int GetNumLocals() const;
    int GetStructVersion() const;
    void GetResourceName(StringBuffer&) const;
};

// 0x8015A908
ObjectDataBehaviorTree2::ObjectDataBehaviorTree2() {
    m_field08 = 0;
    m_field04 = 0;
    // Init StringBuffer with 64-byte buffer
    // Append default name
    m_nodeData = 0;
    // ObjectDataID(0, 0) at +0x58
}

// ============================================================
// IFF Resource System
// ============================================================

// --- IFFBehavior ---

class Behavior {
public:
    void* m_vtable;
    int m_field04;
    int m_field08;
    int m_field0C;
    int m_refCount;              // +0x10

    Behavior();
    int GetGlobNamespaceID();
    int GetNamespaceID();
    int GetSemiGlobalNamespaceID();
    int GetBaseID(short);
    void GetTree(short, ObjectDataBehaviorTree**, bool);
    void GetTreeName(short, StringBuffer&);
};

class IFFBehavior : public Behavior {
public:
    IFFBehavior();
    int CountTrees(short scope);
    int GetTreeByIndex(int idx, short scope, ObjectDataBehaviorTree** out);
    int GetTreeIDByName(char* name);
    int QueryInterface(unsigned int iid, void** out);
    int Release();
};

// 0x800ACC24
IFFBehavior::IFFBehavior() {
    // Call Behavior base ctor
    m_refCount = 0;
}

// 0x800ACC98
int IFFBehavior::CountTrees(short scope) {
    int nsID = -1;
    switch (scope) {
        case 1: nsID = GetGlobNamespaceID(); break;
        case 2: nsID = GetNamespaceID(); break;
        case 3: nsID = GetSemiGlobalNamespaceID(); break;
        default: break;
    }
    if (nsID == -1) return 0;
    // Look up resource file and count trees
    return 0;
}

// 0x800ACFB0
int IFFBehavior::QueryInterface(unsigned int iid, void** out) {
    if (!out) return 0;
    if (iid == 1 || iid == 0x9F0BC11C) {
        // AddRef
        *out = this;
        return 1;
    }
    return 0;
}

// 0x800AD034
int IFFBehavior::Release() {
    int newCount = m_refCount - 1;
    m_refCount = newCount;
    if (newCount == 0) {
        // Delete via vtable
        return 0;
    }
    return newCount;
}

// --- IFFBehaviorConstants ---

class IFFBehaviorConstants : public ObjectDataBehaviorConstants {
public:
    char m_resNameBuf[64];       // +0x18 (StringBuffer at +0x18)
    int m_refCount;              // +0x60

    IFFBehaviorConstants();
    void LoadData(iResFile*, int*);
    int LoadFromIndex(unsigned int nsID, int resID);
    int LoadFromDataID(ObjectDataID& id);
    int SaveDataByID(ObjectDataID& id);
    int GetResourceName2(StringBuffer& out) const;
    int QueryInterface(unsigned int iid, void** out);
    int Release();
};

// 0x8015A808
IFFBehaviorConstants::IFFBehaviorConstants() {
    // ObjectDataBehaviorConstants base ctor
    // Init StringBuffer at +0x18 with default name
    m_refCount = 0;
}

// 0x8015A5A4
int IFFBehaviorConstants::QueryInterface(unsigned int iid, void** out) {
    if (!out) return 0;
    if (iid == 1 || iid == 0xEBB8CA94) {
        // AddRef
        *out = this;
        return 1;
    }
    return 0;
}

// 0x8015A628
int IFFBehaviorConstants::Release() {
    int newCount = m_refCount - 1;
    m_refCount = newCount;
    if (newCount == 0) {
        // Delete via vtable
        return 0;
    }
    return newCount;
}

// --- IFFBehaviorTree ---

class IFFBehaviorTree : public ObjectDataBehaviorTree2 {
public:
    int m_refCount;              // +0x60

    IFFBehaviorTree();
    IFFBehaviorTree(int numNodes);
    ~IFFBehaviorTree();
    int LoadFromIndex(unsigned int nsID, int resID);
    int LoadFromDataID(ObjectDataID& id);
    int SaveDataByID(ObjectDataID& id);
    int QueryInterface(unsigned int iid, void** out);
    int Release();
};

// 0x8015B2D8
IFFBehaviorTree::IFFBehaviorTree() {
    // ObjectDataBehaviorTree base ctor
    m_refCount = 0;
}

// 0x8015B31C
IFFBehaviorTree::IFFBehaviorTree(int numNodes) {
    // ObjectDataBehaviorTree base ctor
    int allocSize = numNodes * 12;
    m_nodeData = __builtin_vec_new(allocSize + 24);
    m_field08 = 1;
    m_refCount = 0;
}

// 0x8015B37C
IFFBehaviorTree::~IFFBehaviorTree() {
    if (m_field08) {
        if (m_nodeData) {
            __builtin_vec_delete(m_nodeData);
        }
        m_nodeData = 0;
    }
    // ~ObjectDataBehaviorTree base
}

// 0x8015B818
int IFFBehaviorTree::QueryInterface(unsigned int iid, void** out) {
    if (!out) return 0;
    if (iid == 1 || iid == 0x2BEB2426) {
        // AddRef
        *out = this;
        return 1;
    }
    return 0;
}

// 0x8015B89C
int IFFBehaviorTree::Release() {
    int newCount = m_refCount - 1;
    m_refCount = newCount;
    if (newCount == 0) {
        // Delete via vtable
        return 0;
    }
    return newCount;
}

// --- IFFResList ---

class IFFResList {
public:
    void* m_begin;               // +0x00
    void* m_end;                 // +0x04
    void* m_padding[2];          // +0x08
    int m_count;                 // +0x10
    int m_field14;               // +0x14

    void DoStream(ReconBuffer* buf, int version);
    IFFResList(IFFResList& other);
};

// 0x800BCDAC
void IFFResList::DoStream(ReconBuffer* buf, int version) {
    int count = m_count;
    // Recon32 for count
    m_count = count;
    // DoContainerStream for the vector elements
}

// --- ObjResFile ---

class StdResFile {
public:
    StdResFile();
    int Open(StringBuffer&);
};

class SeqResFile : public StdResFile {
public:
    void* m_vtable2;             // +0x0C
    void ClearOpenSpecs();
    void AddOpenSpec(int, char*);
    ~SeqResFile();
};

class ObjResFile : public SeqResFile {
public:
    ObjResFile();
    ~ObjResFile();
    int Open(StringBuffer& name);
};

// 0x80110368
ObjResFile::ObjResFile() {
    // StdResFile base ctor
    // Set vtable
    ClearOpenSpecs();
    AddOpenSpec(2, ".iff");
}

// 0x801103C0
ObjResFile::~ObjResFile() {
    // Set vtable
    // Notify object module
    // ~SeqResFile base
}

// 0x80110424
int ObjResFile::Open(StringBuffer& name) {
    int result = StdResFile::Open(name);
    if (result == 0) {
        // Notify object module of new res file
    }
    return result;
}

// ============================================================
// CAS (Create-A-Sim) System
// ============================================================

// --- CasMediator ---

class CasMediator {
public:
    void* m_treeHeader;          // +0x04
    int m_treeSize;              // +0x08
    bool m_field0C;              // +0x0C
    void* m_field10;             // +0x10
    void* m_field14;             // +0x14
    void* m_field18;             // +0x18
    void* m_field1C;             // +0x1C
    void* m_scene;               // +0x20 (transition source)
    void* m_targetScene;         // +0x24 (transition target)
    void* m_field28;             // +0x28
    void* m_field2C;             // +0x2C

    CasMediator();
    ~CasMediator();
    void AddListener(CasListener& listener);
    void RemoveListener(CasListener& listener);
    void RemoveAllListeners();
    void PostEvent(CasEvent& event);
    bool IsTransitionComplete();
};

// 0x80162298
bool CasMediator::IsTransitionComplete() {
    if (m_scene == 0) return true;
    void* target = m_targetScene;
    if (target == 0) return true;
    // Check animation progress
    // Returns true when animation blending is complete
    return false; // Placeholder
}

// ============================================================
// Camera System
// ============================================================

class GameData;

class CameraManager {
public:
    void* m_directors[2];        // +0x00
    static CameraManager* s_instance;

    void Update();
    static CameraManager* GetSingleton();
    CameraManager();
    void Initialize();
};

// 0x8001EB80
void CameraManager::Update() {
    // Update camera directors for both players
    // Save current director, set player 0's, tick, restore
    if (m_directors[0]) {
        // SetCameraDirector, call Update vtable, get FOV
    }
    if (m_directors[1]) {
        // Check if player 2 connected, update their camera
    }
    // Restore original camera director
}

// 0x8001EC50
CameraManager* CameraManager::GetSingleton() {
    if (!s_instance) {
        s_instance = new CameraManager();
        s_instance->Initialize();
    }
    return s_instance;
}

// --- CameraMotionSystem ---

class CameraMotionSystem {
public:
    int m_field00;               // +0x00
    void* m_field04;             // +0x04
    float m_pos[3];              // +0x08 (EVec3)
    float m_lookAt[3];           // +0x14 (EVec3)
    float m_up[3];               // +0x20 (EVec3)
    float m_targetPos[3];        // +0x2C (EVec3)
    float m_targetLookAt[3];     // +0x38 (EVec3)
    float m_targetUp[3];         // +0x44 (EVec3)
    float m_direction[3];        // +0x50 (EVec3)

    void SnapCamera();
    void RubberBandInterpolate(EVec3* pos, EVec3 target, float dt);
    void RubberBandMove(float dt);
};

// 0x80016110
void CameraMotionSystem::SnapCamera() {
    // Copy target positions to current positions
    m_targetPos[0] = m_pos[0];
    m_targetPos[1] = m_pos[1];
    m_targetPos[2] = m_pos[2];
    m_targetLookAt[0] = m_lookAt[0];
    m_targetLookAt[1] = m_lookAt[1];
    m_targetLookAt[2] = m_lookAt[2];
    m_targetUp[0] = m_up[0];
    m_targetUp[1] = m_up[1];
    m_targetUp[2] = m_up[2];
    // Compute direction = normalize(targetLookAt - targetPos)
    float dx = m_targetLookAt[0] - m_targetPos[0];
    float dy = m_targetLookAt[1] - m_targetPos[1];
    float dz = m_targetLookAt[2] - m_targetPos[2];
    // Normalize direction vector
    m_direction[0] = dx;
    m_direction[1] = dy;
    m_direction[2] = dz;
}

// ============================================================
// PreGame States
// ============================================================

class CreateASimBaseState : public StateMachineState {
public:
    void Reset();
    void Update(float);
    int m_field20_done;          // +0x20 = 32
    int m_field28_accepted;      // +0x28 = 40
    int m_field2C_cancelled;     // +0x2C = 44
};

class PreGameCasPlayer1State : public CreateASimBaseState {
public:
    void Reset();
    void Update(float);
};

// 0x800949EC
void PreGameCasPlayer1State::Reset() {
    CreateASimBaseState::Reset();
    // Get player 0's primary neighbor, init default values
    // Set UIDB sim ID, load CAS
}

// 0x80094A58
void PreGameCasPlayer1State::Update(float dt) {
    CreateASimBaseState::Update(dt);
    // Check if CAS accepted
    if (m_field20_done == 0 && m_field28_accepted != 0) {
        OwnerReturnFromState(2);
        return;
    }
    // Check if CAS cancelled
    if (m_field20_done == 0 && m_field2C_cancelled != 0) {
        OwnerReturnFromState(1);
    }
}

class PreGameCasPlayer2State : public CreateASimBaseState {
public:
    void Startup();
    void Reset();
    void Update(float);
};

// 0x80094AF0
void PreGameCasPlayer2State::Startup() {
    // Check if player 2 controller is assigned
    // Set secondary controller for AptViewer
}

// 0x80094B68
void PreGameCasPlayer2State::Reset() {
    CreateASimBaseState::Reset();
    // Get player 1's primary neighbor, init default values
    // Set UIDB sim ID, load CAS for player 2
}

// 0x80094BD4
void PreGameCasPlayer2State::Update(float dt) {
    CreateASimBaseState::Update(dt);
    if (m_field20_done == 0 && m_field28_accepted != 0) {
        OwnerReturnFromState(2);
        return;
    }
    if (m_field20_done == 0 && m_field2C_cancelled != 0) {
        OwnerReturnFromState(1);
    }
}

// --- PreGameFreeplayState ---

class LoadingScreenStateMachine {
public:
    static int LoadInProgress();
    static void StartingLoad(int mode);
    static void LoadFinishing();
};

class TheSimsStateMachine : public StateMachine {
public:
    int IsFlowStateRequestPending();
    int GetFlowStateRequest();
    void SetFlowStateCurrent();
};

class PreGameFreeplayState : public StateMachineState {
public:
    FAMTarget* m_famTarget;      // +0x1C = 28

    void Startup();
    void Shutdown();
    void Update(float);
};

// 0x80094EEC
void PreGameFreeplayState::Startup() {
    // Load UI strings and set UIDB values
    // Create FAMTarget
    m_famTarget = (FAMTarget*)__builtin_new(368);
    // FAMTarget::FAMTarget()
}

// 0x8009501C
void PreGameFreeplayState::Shutdown() {
    if (m_famTarget) {
        // Destroy FAMTarget via vtable
    }
}

// 0x8009508C
void PreGameFreeplayState::Update(float dt) {
    TheSimsStateMachine* tsm = (TheSimsStateMachine*)m_owner;
    int mainState = tsm->m_stateId;

    if (mainState != 0) {
        tsm->m_stateId = 0;
        LoadingScreenStateMachine::LoadFinishing();
        // Notify FAMTarget of return from create-a-family
    }

    if (tsm->IsFlowStateRequestPending()) {
        int request = tsm->GetFlowStateRequest();
        switch (request) {
            case 6: // Enter house
                if (!LoadingScreenStateMachine::LoadInProgress()) {
                    LoadingScreenStateMachine::StartingLoad(4);
                } else {
                    tsm->SetFlowStateCurrent();
                    // Setup live mode
                    OwnerSetNextState(13, 0.0f);
                }
                break;
            case 4: // Back to CAS
                if (!LoadingScreenStateMachine::LoadInProgress()) {
                    LoadingScreenStateMachine::StartingLoad(3);
                } else {
                    tsm->SetFlowStateCurrent();
                    OwnerCallState(12);
                }
                break;
            case 50: // Quit
                if (!LoadingScreenStateMachine::LoadInProgress()) {
                    LoadingScreenStateMachine::StartingLoad(0);
                } else {
                    tsm->SetFlowStateCurrent();
                    OwnerReturnFromState(1);
                }
                break;
        }
    }
}

// ============================================================
// Player System
// ============================================================

class Player {
public:
    int m_playerID;              // +0x00
    void* m_primaryNeighbor;     // +0x04
    FlashPiMenu* m_piMenu;       // +0x08
    ESimsCam* m_camera;          // +0x0C

    void Reset(int playerID);
    void* GetPrimaryNeighbor();
    void* GetSelectedNeighbor();
};

// 0x8005950C
void Player::Reset(int playerID) {
    m_playerID = playerID;
    if (!m_piMenu) {
        m_piMenu = (FlashPiMenu*)__builtin_new(16);
        // FlashPiMenu::FlashPiMenu(playerID)
    }
    if (!m_camera) {
        void* mem = MainHeap();
        // Alloc aligned 1392 bytes for ESimsCam
        // memset to 0
        // ESimsCam::ESimsCam(playerID)
    }
    // ESimsCam::Init()
}

// --- PlayerCheats ---

class PlayerCheats {
public:
    float m_timer;               // +0x10
    int m_index;                 // +0x14
    int m_cheatActive;           // +0x18
    unsigned short m_btnHistory[16]; // +0x1C

    int Capture(EController* ctrl);
    bool IsSingleButton(unsigned short mask);
    void PurgeBtnMemory();
    int CreateBtnMask();
    void GetNextIndex(int& idx);
};

// 0x80005F84
bool PlayerCheats::IsSingleButton(unsigned short mask) {
    int count = 0;
    for (int i = 0; i < 16; i++) {
        if (mask & (1 << i)) {
            count++;
            if (count > 1) return false;
        }
    }
    return count == 1;
}

// ============================================================
// Motives System
// ============================================================

class Motives {
public:
    float m_values[16];          // +0x00
    float m_deltas[16];          // +0x40
    float m_prevValues[16];      // +0x44...
    void* m_person;              // +0x80

    void Init();
    void Sim();
    void Cleanup();
};

// 0x800C27FC
void Motives::Init() {
    // Initialize motive constants if not done
    // Set all 16 motives to default value (100.0)
    for (int i = 0; i < 16; i++) {
        m_values[i] = 100.0f;
    }
    // Set prev values to default
    // Clear update counter
}

// 0x800C2C10
void Motives::Cleanup() {
    // Clamp all motive values to valid range [min, max]
    for (int i = 0; i < 16; i++) {
        // Check if motive is active
        // Clamp to range [-100, 100]
        if (m_values[i] > 100.0f) m_values[i] = 100.0f;
        if (m_values[i] < -100.0f) m_values[i] = -100.0f;
        // Copy to prev values
    }
}

// ============================================================
// Core X-System Objects
// ============================================================

// --- cXObject ---

class TreeSim {
public:
    TreeSim();
    ~TreeSim();
};

class InfluenceMap {
public:
    int ValidateMissing(cXObject*);
    void RemoveObjectFromMap(cXObject*);
};

class cXObject2 {
public:
    void* m_treeSim;             // +0x00
    void* m_vtable2;             // +0x04 (cXObject vtable)

    cXObject2(int createTreeSim);
    ~cXObject2();
    void SetFreeWill(bool val);
    void* GetWallBlockFlagsAtTile(CTilePt& tile, int direction);
    void* CAST_IMPL();
};

// 0x800DB954
void cXObject2::SetFreeWill(bool val) {
    // Store self in global, call vtable method on person
    // to set attribute 30 = val
}

// 0x800EA9BC
void* cXObject2::CAST_IMPL() {
    if (!this) return 0;
    // Call vtable method to get casted interface
    return 0;
}

// --- cXPerson ---

class cXPerson2 : public cXObject2 {
public:
    cXPerson2(int createTreeSim);
    ~cXPerson2();
    void* CAST_IMPL();
};

// 0x8012C698
void* cXPerson2::CAST_IMPL() {
    if (!this) return 0;
    // Call vtable method to get casted person interface
    return 0;
}

// ============================================================
// Memory Pool System
// ============================================================

// --- FastAllocPool ---

class FastAllocPool {
public:
    void* m_base;                // +0x00
    void* m_freeList;            // +0x04
    int m_count;                 // +0x08
    int m_elemSize;              // +0x0C
    void* m_aligned;             // +0x10
    void* m_vtable;              // +0x14

    FastAllocPool(char* name, void* mem, int count, int elemSize);
    void Init(void* mem, int elemSize, int count);
    int Valid();
    void* Alloc();
    void Free(void* ptr);
    ~FastAllocPool();
};

// 0x802D6F7C
FastAllocPool::FastAllocPool(char* name, void* mem, int count, int elemSize) {
    m_freeList = 0;
    m_base = 0;
    m_freeList = 0;
    m_count = 0;
    m_elemSize = 0;
    m_aligned = 0;
    if (mem && count && elemSize) {
        Init(mem, elemSize, count);
    }
}

// 0x802D7024
void FastAllocPool::Init(void* mem, int elemSize, int count) {
    m_freeList = 0;
    // Align memory pointer
    unsigned int addr = (unsigned int)(uintptr_t)mem;
    unsigned int mask = addr | elemSize;
    unsigned int aligned = mask & (~mask + 1); // Round to alignment
    m_aligned = (void*)aligned;
    m_base = mem;
    m_count = count;
    m_elemSize = elemSize;

    // Build free list
    char* p = (char*)mem;
    for (unsigned int i = 0; i < (unsigned int)count; i++) {
        if (p) {
            *(unsigned int*)p = 0x45564156; // Magic "EVAV"
            *(void**)(p + 4) = m_freeList;
            m_freeList = p;
        }
        p += elemSize;
    }
}

// 0x802D7094
int FastAllocPool::Valid() {
    // Validate free list pointers are within pool bounds
    void* node = m_freeList;
    if (node) {
        char* base = (char*)m_base;
        char* end = base + m_elemSize * m_count;
        if ((char*)node < base || (char*)node >= end) {
            // Invalid pointer - crash in debug
            return 0;
        }
    }
    // Walk free list validating each node
    void* curr = m_freeList;
    while (curr) {
        void* next = *(void**)((char*)curr + 4);
        if (next) {
            char* base = (char*)m_base;
            char* end = base + m_elemSize * m_count;
            if ((char*)next < base || (char*)next >= end) {
                return 0;
            }
        }
        curr = next;
    }
    return 1;
}

// --- ProtectedAllocPool ---

class ProtectedAllocPool : public FastAllocPool {
public:
    EMutex* m_mutex;             // +0x18

    ProtectedAllocPool(char* name, void* mem, int count, int elemSize);
    ~ProtectedAllocPool();
    void* Alloc();
    void Free(void* ptr);
};

// 0x802D718C
ProtectedAllocPool::ProtectedAllocPool(char* name, void* mem, int count, int elemSize)
    : FastAllocPool(name, mem, count, elemSize) {
    // EMutex::EMutex() on m_mutex
}

// 0x802D71D0
ProtectedAllocPool::~ProtectedAllocPool() {
    // EMutex::~EMutex()
    // FastAllocPool::~FastAllocPool()
}

// 0x802D7250
void* ProtectedAllocPool::Alloc() {
    // Lock mutex
    void* result = FastAllocPool::Alloc();
    // Unlock mutex
    return result;
}

// 0x802D72C8
void ProtectedAllocPool::Free(void* ptr) {
    // Lock mutex
    FastAllocPool::Free(ptr);
    // Unlock mutex
}

// ============================================================
// Careers System
// ============================================================

class Careers {
public:
    virtual ~Careers();
};

class CareersImpl : public Careers {
public:
    void* m_vtable;              // +0x00
    void* m_resource;            // +0x04
    void* m_table;               // +0x08
    void* m_jobPerfRow;          // +0x0C
    void* m_salaryRow;           // +0x10
    short m_field14;             // +0x14
    void* m_listHead;            // +0x18
    void* m_listTail;            // +0x1C

    void Load();
    void TearDown();
    void* GetCareerByID(int id);
    void* GetJobPerformance(int score);
    void GetOfferDialogText(unsigned short* out, Career& career, int level, bool isPromotion);
    int GetBehCareerData(Career& career, int level, int dataType, short* out);
    ~CareersImpl();

    static void operator delete(void*);
};

// 0x800B15F8
void CareersImpl::TearDown() {
    if (m_resource) {
        // EResource::DelRef
        m_salaryRow = 0;
        m_resource = 0;
        m_table = 0;
        m_jobPerfRow = 0;
    }
}

// 0x800B1644
void* CareersImpl::GetCareerByID(int id) {
    void* table = m_table;
    if (!table) return 0;
    // Linear search through career table (stride 20)
    return 0;
}

// 0x800B1B7C
CareersImpl::~CareersImpl() {
    TearDown();
    // Call base Careers::~Careers()
}

// ============================================================
// Wrapper / UI System
// ============================================================

class Wrapper2 {
public:
    void* m_vtable;              // +0x80 = 128
    void* m_handler;             // +0x84 = 132
    void* m_msgHandler;          // +0x88 = 136
    void** m_panes;              // +0x8C = 140 (vector begin)
    void** m_panesEnd;           // +0x90 = 144 (vector end)
    void** m_panesCap;           // +0x94 = 148 (vector capacity)
    int m_drawMarkers;           // +0xA0 = 160

    void WrapperShutdown();
    void WrapperDraw(ERC* rc);
    void AddPane(WrapperPaneBase* pane);
    void ReleasePaneBackgrounds();
    ~Wrapper2();
    void* FindPane(WrapperPaneBase* pane);
};

// 0x80086C84
void Wrapper2::ReleasePaneBackgrounds() {
    void** it = m_panes;
    while (it != m_panesEnd) {
        WrapperPaneBase* pane = (WrapperPaneBase*)*it;
        // pane->ReleaseBackgroundShader();
        it++;
    }
}

// ============================================================
// ObjectSave Tables
// ============================================================

class ObjectSaveIDTable {
public:
    void* m_data;                // +0x00

    void DoStream(ReconBuffer* buf, int version);
    void* findHRSel(short sel) const;
};

// 0x8004516C
void* ObjectSaveIDTable::findHRSel(short sel) const {
    // Linear search through save ID table entries (stride 28)
    // comparing halfword at offset 12
    return 0;
}

class ObjectSaveTypeTable {
public:
    void* m_objModule;           // +0x00
    void DoStream(ReconBuffer* buf, int version);
};

class ObjectSaveTypeTable2 {
public:
    void DoStream(ReconBuffer* buf, int version);
};

class ObjectSaveTypeTable3 {
public:
    void DoStream(ReconBuffer* buf, int version);
};

// ============================================================
// Object Iterator
// ============================================================

class ObjectIterator {
public:
    void* m_root;                // +0x00
    void* m_current;             // +0x04
    int m_iterType;              // +0x08

    void init(CTilePt& tile, int iterType);
    void operator++();
};

// 0x800F29F8
void ObjectIterator::init(CTilePt& tile, int iterType) {
    // Get room manager, find tile's room, get first object
    m_iterType = iterType;
    // m_current = first object at tile
    // m_root = m_current
}

// ============================================================
// Passive Influence System
// ============================================================

class PassiveInfluenceObject {
public:
    void* m_vtable;
    // Object influence data
};

class PassiveInfluencePerson {
public:
    void* m_vtable;
    // Person influence data
};

class PassiveInfluenceTarget {
public:
    void* m_vtable;
    // Target influence data
};

// ============================================================
// Logging System
// ============================================================

class LogInteraction {
public:
    void* m_vtable;
    // Interaction log data
};

class LogInteractionSample {
public:
    void* m_vtable;
    // Interaction sample data
};

class LogPersonState {
public:
    void* m_vtable;
    // Person state log data
};

class LogPersonTracker {
public:
    void* m_vtable;
    // Person tracking data
};

// ============================================================
// Misc Game Systems (Geometry, Math, etc.)
// ============================================================

// --- IRect ---

class IRect {
public:
    int left;                    // +0x00
    int top;                     // +0x04
    int right;                   // +0x08
    int bottom;                  // +0x0C

    bool IsContained(IRect* other) const;
    void Intersect(IRect* a, IRect* b);
};

// 0x800A5A98
bool IRect::IsContained(IRect* other) const {
    if (right > other->right) return false;
    if (left < other->left) return false;
    if (top < other->top) return false;
    if (bottom > other->bottom) return false;
    return true;
}

// --- PlumbBob ---

class PlumbBobModel {
public:
    void* m_vtable;
    // PlumbBob rendering data
};

class PlumbBobParms {
public:
    // PlumbBob tuning parameters
};

// ============================================================
// Misc Stubs (StackElem, TGA_INFO, etc.)
// ============================================================

class StackElem2 {
public:
    void* m_field00;
    void* m_field04;
    void* m_field08;
    void* m_field0C;
    void* m_behavior;            // +0x10

    void GetTreeName(StringBuffer& out);
    void ReconStream(ReconBuffer* buf, int version, BehaviorFinder* finder);
    void Setup(StackElem2* parent, short* data);
};

// 0x8014754C
void StackElem2::GetTreeName(StringBuffer& out) {
    if (m_behavior) {
        // Get tree ID, then look up name via Behavior
    } else {
        // Copy "(none)" to output
    }
}

// ============================================================
// Audio System Stubs
// ============================================================

class cAudioInfo {
public:
    // Audio configuration data
};

class cSamplePatch {
public:
    // Sample patch data
};

class cSampleChannel {
public:
    // Sample channel data
};

class cSoundCacheItem {
public:
    // Sound cache entry
};

// ============================================================
// Neighborhood / Level Data
// ============================================================

class NeighborhoodConstants {
public:
    // Neighborhood tuning constants
};

class LevelLightingTuning {
public:
    // Level lighting parameters
};

class HouseRecon {
public:
    // House reconstruction buffer
};

class HouseStats {
public:
    // House statistics
};

// ============================================================
// Miscellaneous Game Data
// ============================================================

class GlobalSkillTables {
public:
    // Skill progression tables
};

class IngredientManager {
public:
    // Cooking ingredient data
};

class InteractionHelper {
public:
    // Interaction system helpers
};

class InteractionList {
public:
    // List of available interactions
};

class RelationsCmp {
public:
    // Relationship comparison
};

class RepTitleSupport {
public:
    // Reputation title system
};

class ResourceBehavior {
public:
    // Resource-based behavior data
};

class RoomScoreConstants {
public:
    // Room scoring parameters
};

class RoutingSlot {
public:
    // Routing slot data
};

class SimsCameraParameters {
public:
    // Camera tuning parameters
};

class SlotDescriptor2 {
public:
    // Slot description data
};

class TGA_INFO {
public:
    // TGA image header
};

class TTabScratchEntry {
public:
    // Tree table scratch space
};

class TileList {
public:
    // Tile collection
};

class TreeTableAdScratch {
public:
    // Tree table ad scratch data
};

class XObjLang {
public:
    // Cross-object language data
};

class iResFile2 {
public:
    // Resource file interface
};

class AutonomyConstantsClient {
public:
    // Autonomy system constants
};

class CDirtyXmlNode {
public:
    // XML node for dirty tracking
};

// ============================================================
// State Machine States (misc)
// ============================================================

class LiveModeChangeHouseStateMachine {
public:
    // Live mode -> change house flow
};

class UrbzModeNewGameState {
public:
    // Urbz new game entry
};

class TheSimsEAMovieState {
public:
    // EA intro movie state
};

class TheSimsMemCardCheckState {
public:
    // Memory card check state
};

class TheSimsNGCLicenseState {
public:
    // NGC license display state
};

class TheSimsSimsIntroMovieState {
public:
    // Sims intro movie state
};

class MoviePlayerEndgameMovieState {
public:
    // Endgame movie state
};

// ============================================================
// Misc helpers
// ============================================================

class SimRenderer2 {
public:
    void Render(ERC* rc, EIStaticModel** models, EShader* shader, EMat4* mat, unsigned int flags, bool ghosted);
    void Render(ERC* rc, EIStaticModel** models, EAnimController* anim, EShader* shader, EMat4& mat, bool ghosted);
    void MorphParts(EIStaticModel** models, bool flag);
    void RenderGhosted(ERC* rc, EIStaticModel** models, EMat4* mat, unsigned int flags, bool flag);
};

class PiecewiseFn {
public:
    // Piecewise linear function
};

class MotiveCurveSet {
public:
    // Motive decay curves
};

class MotiveEffects {
public:
    // Motive effect modifiers
};

class NewControlParms {
public:
    // Controller input parameters
};

class PlayerFamilyImpl {
public:
    // Player family data
};

class StdResFile2 {
public:
    // Standard resource file
};
