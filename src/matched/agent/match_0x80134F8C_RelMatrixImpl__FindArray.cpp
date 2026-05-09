// 0x80134F8C (60B) RelMatrixImpl::FindArray(int)
// Linear search of pointer-array; key compared to *(entry+16); returns iter.

struct RMEntry { char _pad[16]; int m_key; };

class RelMatrixImpl {
public:
    char _pad[4];
    RMEntry** m_begin;
    RMEntry** m_end;
    RMEntry** FindArray(int key);
};

RMEntry** RelMatrixImpl::FindArray(int key)
{
    RMEntry** end = m_end;
    RMEntry** it = m_begin;
    while (it != end) {
        if ((*it)->m_key == key) break;
        ++it;
    }
    return it;
}
