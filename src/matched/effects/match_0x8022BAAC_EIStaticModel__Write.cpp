// 0x8022BAAC EIStaticModel::Write(EStream&) (100B)

struct EMat4 { float m[16]; };
struct EStream {};
EStream& operator<<(EStream& s, EMat4& m);

struct EStreamDispatch {
    char _pad[56];
    short m_adj;
    char _pad2[2];
    void (*m_fn)(void*, void*, int);
};

struct EStreamIface {
    char _pad[24];
    EStreamDispatch* m_dispatch;
};

class EInstance {
public:
    void Write(EStream& s);
};

class EIStaticModel : public EInstance {
    char _pad0[0x7c];
    EMat4 m_mat;
    char _pad1[0x50];
    unsigned int m_field110;
public:
    void Write(EStream& s);
};

void EIStaticModel::Write(EStream& s) {
    EInstance::Write(s);
    EStreamDispatch* ds = ((EStreamIface*)&s)->m_dispatch;
    unsigned int val = m_field110;
    short adj = ds->m_adj;
    void (*fn)(void*, void*, int) = ds->m_fn;
    fn((char*)&s + adj, &val, 4);
    s << m_mat;
}
