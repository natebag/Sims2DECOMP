// 0x800E324C cXObjectImpl::GetNumTiles (16B)

struct cXObj_GNT {
    void GetNumTiles(int& a, int& b);
};

void cXObj_GNT::GetNumTiles(int& a, int& b) {
    a = 1;
    b = 1;
}
