/* PSystemDestroy at 0x80303798 (68 bytes) */

typedef unsigned int u32;

extern u32 g_particleManager;

void PSystemDetach(u32);
void PSystemRemove(u32, u32);

struct PSystemHolder {
    u32 m_system;
};

void PSystemDestroy(PSystemHolder* p)
{
    PSystemDetach(p->m_system);
    PSystemRemove(g_particleManager, p->m_system);
    p->m_system = 0;
}
