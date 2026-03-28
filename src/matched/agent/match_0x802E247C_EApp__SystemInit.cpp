/* EApp::SystemInit(void) at 0x802E247C (52B) */

struct AppInitVt { char pad[0xA0]; short m_off; int (*m_fn)(void *); };
struct EApp_SI { char pad[0x338]; AppInitVt *m_innerVt; void SystemInit(void); };

void EApp_SI::SystemInit(void) {
    AppInitVt *vt = m_innerVt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    fn((char *)this + off);
}
