// 0x800878B4 IconItem::SetShader(ERShader (8 B)
struct IconItem { char _pad[0x30]; unsigned m_shader; void SetShader(unsigned); };
void IconItem::SetShader(unsigned shader) { m_shader = shader; }
