// 0x800D05F8 NeighborhoodImpl::GetHouseInfo(NghResFile*, HouseInfo*) (72B) — Tech #47 MI-vcall slot 0x60/0x64

class NghResFile;
struct HouseInfo {
    int m_0;
    int m_4;
    int m_8;
    int m_12;
};

class NeighborhoodImpl {
public:
    void GetHouseInfo(NghResFile* file, HouseInfo* h);
};

void NeighborhoodImpl::GetHouseInfo(NghResFile* file, HouseInfo* h) {
    char* vt = *(char**)this;
    short adj = *(short*)(vt + 0x60);
    void* fn = *(void**)(vt + 0x64);
    ((void(*)(void*, NghResFile*, int*, int*, int*, HouseInfo*))fn)(
        (char*)this + adj, file, &h->m_12, &h->m_4, &h->m_8, h);
}
