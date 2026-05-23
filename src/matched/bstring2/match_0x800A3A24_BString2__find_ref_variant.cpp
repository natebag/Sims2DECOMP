int BS2_DataFn(void *);
int BS2_FindImpl(void *, void *, int, int);

struct BS2_Inner { void *m_buf; };
struct BS2_FR {
    BS2_Inner *m_data;
    int find(BS2_FR *other, int startIdx);
};

int BS2_FR::find(BS2_FR *other, int startIdx) {
    void *buf;
    if (BS2_DataFn(other) != 0) {
        buf = other->m_data->m_buf;
    } else {
        buf = 0;
    }
    int len = BS2_DataFn(other);
    return BS2_FindImpl(this, buf, startIdx, len);
}
