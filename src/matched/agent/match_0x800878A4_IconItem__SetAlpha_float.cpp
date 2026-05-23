// 0x800878A4 IconItem::SetAlpha(float) (8 B)
struct IconItem { char _pad[0x2c]; float m_alpha; void SetAlpha(float); };
void IconItem::SetAlpha(float val) { m_alpha = val; }
