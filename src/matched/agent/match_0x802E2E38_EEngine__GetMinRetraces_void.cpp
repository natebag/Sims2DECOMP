// FLAGS: -fno-schedule-insns
// 0x802E2E38 EEngine::GetMinRetraces(void) (24B)
// lwz r0,8(3); cmplwi r0,0; li r3,1; beqlr; lwz r3,gMinRetraces(13)
//   m_field8 == 0 ? 1 : gMinRetraces
extern int gMinRetraces;    // -26804(r13)

struct EEngine {
    char pad[8];
    unsigned m_field8;      // 0x8
    int GetMinRetraces();
};

int EEngine::GetMinRetraces() {
    if (m_field8 == 0) return 1;
    return gMinRetraces;
}
