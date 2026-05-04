// cXObjectImpl::Error(short) at 0x800EBA98 (152B)

struct cXObjectImpl;

struct EVtFull {
    char pad[112];
    struct { short m_off; char _p[2]; void (*m_fn)(void *, int, int); } s112;
    char pad2[808 - 120];
    struct { short m_off; char _p[2]; void *(*m_fn)(void *); } s808;
};
struct EBase1 { char pad[4]; EVtFull *m_vt; };

struct ESlot576 { short m_off; char _p[2]; void (*m_fn)(void *, void *, int, int); };
struct EVt576 { char pad[576]; ESlot576 m_slot; };
struct EBase2 { EVt576 *m_vt; };

struct cXObjectImpl {
    char pad_top[4];
    EBase1 *m_field_4;
    char pad_mid[80];
    EBase2 *m_field_88;
    void Error(short);
};

void cXObjectImpl::Error(short code) {
    EBase1 *b1 = m_field_4;
    b1->m_vt->s112.m_fn((char *)b1 + b1->m_vt->s112.m_off, 256, 1);
    EBase2 *b2 = m_field_88;
    ESlot576 *slot = &b2->m_vt->m_slot;
    char *b2_adj = (char *)b2 + slot->m_off;
    EBase1 *b1b = m_field_4;
    void *r = b1b->m_vt->s808.m_fn((char *)b1b + b1b->m_vt->s808.m_off);
    slot->m_fn(b2_adj, r, 4, 1);
}
