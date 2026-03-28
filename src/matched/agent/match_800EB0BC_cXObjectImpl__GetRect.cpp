/* cXObjectImpl::GetRect(void) - 8 bytes */

struct SomeRect {
    int x, y, w, h;
};

class cXObjectImpl {
public:
    char pad[0x70];
    SomeRect m_rect;

    SomeRect* GetRect(void);
};

SomeRect* cXObjectImpl::GetRect(void) {
    return &m_rect;
}
