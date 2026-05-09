// 0x80113F04 (56B) PassiveInfluenceSystem::FlushSystem(void)
// If global current PIS == this and global PIM != 0, call PIM::EmptyMap.
// Two SDA pointer globals: g_currPIS @ -31780 and g_pim @ -31784.

class PassiveInfluenceMap {
public:
    void EmptyMap();
};

class PassiveInfluenceSystem {
public:
    void FlushSystem();
};

extern PassiveInfluenceSystem* g_currPIS;  // SDA @ -31780
extern PassiveInfluenceMap* g_pim;          // SDA @ -31784

void PassiveInfluenceSystem::FlushSystem()
{
    if (g_currPIS == this && g_pim != 0) {
        g_pim->EmptyMap();
    }
}
