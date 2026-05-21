// 0x8015230C ValidateTheWorld() (80B)

class InfluenceMap {
public:
    void Validate();
};

class PassiveInfluenceMap {
public:
    void Validate();
};

class World {
public:
    char pad[60];
    InfluenceMap* m_60;
    PassiveInfluenceMap* m_64;
};

extern World* g_worldMgr_SDA;

void ValidateTheWorld() {
    World* w = g_worldMgr_SDA;
    if (w == 0) return;
    if (w->m_60 != 0) w->m_60->Validate();
    if (w->m_64 != 0) w->m_64->Validate();
}
