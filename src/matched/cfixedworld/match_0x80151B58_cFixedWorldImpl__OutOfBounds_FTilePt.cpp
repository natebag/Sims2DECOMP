/* cFixedWorldImpl::OutOfBounds(FTilePt &) const - 0x80151B58 (108B) */

struct FTilePt;

class CTilePt {
public:
    int m_x;
    int m_y;

    CTilePt(FTilePt& ft, int flag);
    ~CTilePt();
};

class cFixedWorldImpl {
public:
    int OutOfBounds(FTilePt& ft) const;
};

int cFixedWorldImpl::OutOfBounds(FTilePt& ft) const {
    unsigned char* self = (unsigned char*)this;
    unsigned char* vt = *(unsigned char**)self;
    unsigned char* entry = vt + 88;
    short adj = *(short*)entry;
    self += adj;
    CTilePt ct(ft, 1);
    int (*fn)(unsigned char*, CTilePt*) = *(int (**)(unsigned char*, CTilePt*))(entry + 4);
    int result = fn(self, &ct);
    return result;
}
