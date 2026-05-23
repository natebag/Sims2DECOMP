// 0x801E19BC SKLTarget::IsSkillsActive(void) (8 B)
struct SKLTarget { char _pad[0x88]; unsigned m_field; unsigned IsSkillsActive(); };
unsigned SKLTarget::IsSkillsActive() { return m_field; }
