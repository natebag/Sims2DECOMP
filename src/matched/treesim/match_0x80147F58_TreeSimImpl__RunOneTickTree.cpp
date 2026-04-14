/* TreeSimImpl::RunOneTickTree(Behavior *) at 0x80147F58 (56B) */

struct RunTickVt { char pad[0xA0]; short m_off; int (*m_fn)(void *, void *); };
struct RunTickMid { char pad[0x18]; RunTickVt *m_vt; };
struct TreeSimImpl_RT { RunTickMid *m_inner; void RunOneTickTree(void *beh); };

void TreeSimImpl_RT::RunOneTickTree(void *beh) {
    RunTickMid *mid = m_inner;
    RunTickVt *vt = mid->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, void *) = vt->m_fn;
    fn((char *)mid + off, beh);
}
