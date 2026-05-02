// 0x8035CA0C (84B) ENCamera::ENCamera(void)
// Vtable-at-+0x54 SI ctor + TArray<ENCameraPoint>::TArray member init.

struct TArrayENCameraPoint {
    int* m_begin;
    int* m_end;
    int* m_alloc;
    TArrayENCameraPoint();
};

class ENCameraBase {
public:
    char m_byte0;
    char pad1_3F[0x3F];
    int m_field40;
    int m_field44;
};

class ENCamera : public ENCameraBase {
public:
    TArrayENCameraPoint m_arr;
    virtual ~ENCamera();
    ENCamera();
};

ENCamera::ENCamera() {
    m_byte0 = 0;
    m_field40 = 0;
    m_field44 = 0;
}
