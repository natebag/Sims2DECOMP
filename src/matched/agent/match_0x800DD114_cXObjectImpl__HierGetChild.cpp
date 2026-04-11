// FLAGS: -fno-elide-constructors
/* cXObjectImpl::HierGetChild(int) at 0x800DD114 (72B) */

struct HCVt { char pad[0x488]; short m_off; char _p[2]; int (*m_fn)(void *, short); };
struct HCInner { char pad[0x04]; HCVt *m_vt; };

struct cXObjHC {
    char pad1[0x04];
    HCInner *m_inner;
    char pad2[0x88];
    char *m_slotArray;

    int HierGetChild(int childIdx);
};

int cXObjHC::HierGetChild(int childIdx) {
    HCInner *inner = m_inner;
    char *slot = m_slotArray + childIdx * 32;
    HCVt *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, short) = vt->m_fn;
    short val = *(short *)(slot + 4);
    return fn((char *)inner + off, val);
}
