/* cXObjectImpl::GetLocation(void) - 8 bytes */

struct CTilePt {
    short x, y;
};

class cXObjectImpl {
public:
    char pad[0x68];
    CTilePt m_location;

    CTilePt* GetLocation(void);
};

CTilePt* cXObjectImpl::GetLocation(void) {
    return &m_location;
}
