// 0x800A5A98 (76B) IRect::IsContained(IRect*) const
// Returns true if `this` rect is fully contained within `other`.
// IRect stores (left, top, right, bottom) at offsets (0, 4, 8, 12).
// goto-shared-label: 3 early-exit false conditions, last comparison uses
// preloaded li r3,1 + blelr; falls through to li r3,0; blr.

struct IRect {
    int m_left;   // offset 0
    int m_top;    // offset 4
    int m_right;  // offset 8
    int m_bottom; // offset 12

    bool IsContained(IRect* other) const;
};

bool IRect::IsContained(IRect* other) const {
    if (m_right > other->m_right) goto ret_false;
    if (m_left < other->m_left) goto ret_false;
    if (m_top < other->m_top) goto ret_false;
    if (m_bottom <= other->m_bottom) return true;
ret_false:
    return false;
}
