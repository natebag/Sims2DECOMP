/* cFixedWorldImpl::OutOfRoutableExtent(FTilePt &) const - 0x801519D4 (108B) */

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
    int OutOfRoutableExtent(FTilePt& ft) const;
};

int cFixedWorldImpl::OutOfRoutableExtent(FTilePt& ft) const {
    unsigned char* self = (unsigned char*)this;
    unsigned char* vt = *(unsigned char**)self;
    unsigned char* entry = vt + 72;
    short adj = *(short*)entry;
    self += adj;
    CTilePt ct(ft, 1);
    int (*fn)(unsigned char*, CTilePt*) = *(int (**)(unsigned char*, CTilePt*))(entry + 4);
    int result = fn(self, &ct);
    return result;
}
