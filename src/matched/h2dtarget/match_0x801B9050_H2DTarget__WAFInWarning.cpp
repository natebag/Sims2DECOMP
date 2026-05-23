/* H2DTarget::WAFInWarning(int, bool, bool) at 0x801B9050 (56B) */

struct MODTarget_WAF {
    void SetWarning(int id, bool b1, bool b2);
};

struct H2DTarget_WAF {
    char m_pad[136];
    MODTarget_WAF* m_meters[1];
    void WAFInWarning(int idx, bool b1, bool b2);
};

void H2DTarget_WAF::WAFInWarning(int idx, bool b1, bool b2) {
    MODTarget_WAF* p = m_meters[idx];
    if (p) p->SetWarning(4, b1, b2);
}
