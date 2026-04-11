// 0x80113F04 PassiveInfluenceSystem::FlushSystem (56b)
// FLAGS: -fno-elide-constructors

class PassiveInfluenceMap {
public:
    void EmptyMap();
};

// SDA globals at r13-31780 and r13-31784
// These need to be linked to the correct SDA offsets
extern PassiveInfluenceMap* g_pPassiveInfluenceMap;
extern int g_passiveInfluenceSystemFlag;

void PassiveInfluenceSystem_FlushSystem() {
    if (g_passiveInfluenceSystemFlag == 0 && g_pPassiveInfluenceMap != 0) {
        g_pPassiveInfluenceMap->EmptyMap();
    }
}
