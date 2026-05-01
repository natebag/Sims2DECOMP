// 0x8013896C (44B) PenaltyRect::PenaltyRect(IRect *, int)
// Copy 16-byte IRect from arg into m_rect, then store priority.

class IRect {
public:
    int x, y, w, h;
};

class PenaltyRect {
public:
    IRect m_rect;
    int   m_priority;

    PenaltyRect(IRect* r, int p);
};

PenaltyRect::PenaltyRect(IRect* r, int p) {
    m_rect = *r;
    m_priority = p;
}
