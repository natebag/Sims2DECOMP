/* operator<<(EStream &, EString &) at 0x802D3650 (72B) */

struct SVt { char pad[0x18]; short m_off; char _p[2]; int (*m_fn)(void *, char *); };
struct EStr { char *m_buf; };

struct EStream {
    char pad[0x18];
    SVt *m_sub;
};

EStream *op_shl(EStream *stream, EStr *str) {
    char *data = str->m_buf;
    SVt *sub = stream->m_sub;
    short off = sub->m_off;
    int (*fn)(void *, char *) = sub->m_fn;
    fn((char *)stream + off, data);
    return stream;
}
