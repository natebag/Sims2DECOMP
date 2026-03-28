/* cXObjectImpl::GetNumTiles(int &, int &) - 16 bytes */

class cXObjectImpl {
public:
    void GetNumTiles(int& x, int& y);
};

void cXObjectImpl::GetNumTiles(int& x, int& y) {
    x = 1;
    y = 1;
}
