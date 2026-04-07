// FLAGS: -fno-schedule-insns
// 0x8012C9D8 cXPersonImpl::GetRouteStackSize (32B)

struct XRoute_RSS { char data[164]; };

struct cXPersonImpl_RSS {
    char _pad[0x40c];
    XRoute_RSS* m_routeStackBegin;
    XRoute_RSS* m_routeStackEnd;
    int GetRouteStackSize();
};

int cXPersonImpl_RSS::GetRouteStackSize() {
    return m_routeStackEnd - m_routeStackBegin;
}
