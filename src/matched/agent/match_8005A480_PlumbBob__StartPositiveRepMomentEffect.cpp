// FLAGS: -fno-elide-constructors
extern char g_repDuration[];
struct PlumbBob { char pad[336]; float m_repTimer; char pad2[12]; int m_repMode; void Start(); };
void PlumbBob::Start() {
    if (m_repMode) return;
    m_repTimer = *(float*)g_repDuration;
    m_repMode = 2;
}
