/* cXObjectImpl::IsVehicle(void) at 0x800E3050 (68B) */

struct VehicleVt { char pad[0x318]; short m_off; int (*m_fn)(void *); };
struct VehicleInner { char pad[0x04]; VehicleVt *m_vt; };
struct cXObjectImpl_IV { char pad[0x04]; VehicleInner *m_inner; int IsVehicle(void); };

int cXObjectImpl_IV::IsVehicle(void) {
    VehicleInner *inner = m_inner;
    VehicleVt *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    return fn((char *)inner + off) == 0xC;
}
