/* cXPersonImpl::EORDrawStickFigure(int) at 0x8011AD64 (56B) */

struct EORVt { char pad[0x18]; short m_off; int (*m_fn)(void *, int); };
struct EORObj { EORVt *m_vt; };
struct cXPersonImpl_EOR { char pad[0x3F4]; EORObj *m_inner; void EORDrawStickFigure(int mode); };

void cXPersonImpl_EOR::EORDrawStickFigure(int mode) {
    EORObj *inner = m_inner;
    EORVt *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, int) = vt->m_fn;
    fn((char *)inner + off, mode);
}
