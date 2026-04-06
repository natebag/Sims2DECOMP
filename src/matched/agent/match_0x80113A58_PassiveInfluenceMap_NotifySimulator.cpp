// 0x80113A58 PassiveInfluenceMap::NotifySimulator (52b)

extern char g_simulator[4];
extern int NotifySimulatorTarget(void*);

int PassiveInfluenceMap_NotifySimulator(void* self, void* person, int a, int b) {
    void* p = *(void**)g_simulator;
    if (!p) return 0;
    return NotifySimulatorTarget(p);
}
