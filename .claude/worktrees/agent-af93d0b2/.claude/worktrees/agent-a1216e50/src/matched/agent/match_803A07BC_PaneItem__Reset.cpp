/* 0x803A07BC (12 bytes) - PaneItem::Reset(void) */
class PaneItem { int m_f0; int m_dirty; public: void Reset(); };
void PaneItem::Reset() { m_dirty = 1; }
