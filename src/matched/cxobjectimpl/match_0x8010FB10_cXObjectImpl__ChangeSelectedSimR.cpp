// 0x8010FB10 (104B) — cXObjectImpl::ChangeSelectedSimR(int) [static]
//
// Twin of ChangeSelectedSimL @ 0x8010FAB0 with two structural deltas:
//  (1) Calls a different EGlobal selector method (forward vs reverse).
//  (2) Adds an outer 2-cond gate BEFORE the cam dispatch — proceed iff
//      *(g_simSlotArray + 0xC4) != 0 AND *(state + 0x2C) == 0.
// No volatile-CSE needed: R only loads the slot pointer once (unlike L).
// Non-SDA addresses via extern char[N] (size>8 forces ADDR16_HA/LO over EMB_SDA21).
// Single callee-saved (r31 = sim_id) since slot computation lives entirely
// after the gate.

class EGlobal {
public:
    void AdvanceSelectedPerson(int sim_id);
};

class ESimsCam {
public:
    void CenterOnSelectedSim();
};

struct SelectedSimState {
    char pad[0x2C];
    int m_busyFlag;
};

extern char g_EGlobal[16];
extern char g_simSlotArray[16384];

class cXObjectImpl {
public:
    static void ChangeSelectedSimR(int sim_id);
};

void cXObjectImpl::ChangeSelectedSimR(int sim_id) {
    ((EGlobal*)g_EGlobal)->AdvanceSelectedPerson(sim_id);
    char* base = (char*)g_simSlotArray;
    SelectedSimState* state = *(SelectedSimState**)(base + 0xC4);
    if (state != 0 && state->m_busyFlag == 0) {
        ESimsCam* cam = *(ESimsCam**)(base + sim_id * 16 + 0x100);
        cam->CenterOnSelectedSim();
    }
}
