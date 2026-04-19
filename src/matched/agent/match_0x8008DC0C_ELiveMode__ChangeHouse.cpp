/* ELiveMode::ChangeHouse(void) at 0x8008DC0C (52B) */

struct SMachine_CH { void CallState(int state); };
struct SMMgr_CH { SMachine_CH* FindMachineById(int id); };
extern SMMgr_CH* g_smMgr;

struct ELiveMode_CH { void ChangeHouse(); };

void ELiveMode_CH::ChangeHouse() {
    SMachine_CH* sm = g_smMgr->FindMachineById(0x53494D53);
    sm->CallState(19);
}
