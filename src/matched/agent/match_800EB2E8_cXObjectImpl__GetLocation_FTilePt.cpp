/* cXObjectImpl::GetLocation(FTilePt *) const - 20 bytes */

struct FTilePt {
    int x;
    int y;
};

class cXObjectImpl {
public:
    char pad[0x68];
    FTilePt m_location;

    void GetLocation(FTilePt* pt) const;
};

void cXObjectImpl::GetLocation(FTilePt* pt) const {
    *pt = m_location;
}
