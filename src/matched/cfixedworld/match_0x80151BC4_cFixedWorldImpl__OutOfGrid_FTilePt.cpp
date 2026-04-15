/* cFixedWorldImpl::OutOfGrid(FTilePt &) const - 0x80151BC4 (108B) */

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
    int OutOfGrid(FTilePt& ft) const;
};

int cFixedWorldImpl::OutOfGrid(FTilePt& ft) const {
    unsigned char* self = (unsigned char*)this;
    unsigned char* vt = *(unsigned char**)self;
    unsigned char* entry = vt + 96;
    short adj = *(short*)entry;
    self += adj;
    CTilePt ct(ft, 1);
    int (*fn)(unsigned char*, CTilePt*) = *(int (**)(unsigned char*, CTilePt*))(entry + 4);
    int result = fn(self, &ct);
    return result;
}
