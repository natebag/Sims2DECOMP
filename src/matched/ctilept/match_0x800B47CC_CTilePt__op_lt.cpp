// 0x800B47CC (68B) CTilePt::operator<(CTilePt) const
// Lexicographic < on (m_x, m_y) as signed chars: extsb both then cmpw.
// blt goto_true; bne goto_false pattern for m_x; bge goto_false for m_y.
// goto-shared-label: li r11,0 sentinel; li r11,1 on true; mr r3,r11 at end.

struct CTilePt {
    unsigned char m_x;
    unsigned char m_y;
};

int CTilePt__op_lt(CTilePt* self, CTilePt& o) {
    int r = 0;
    signed char sx = (signed char)self->m_x, ox = (signed char)o.m_x;
    if (sx < ox) { r = 1; goto done; }
    if (sx != ox) goto done;
    if ((signed char)self->m_y < (signed char)o.m_y) r = 1;
done:
    return r;
}
