/* cXPersonImpl::InvalidateRoutes(void) at 0x8012B5A0 (52B) */

struct Route_IR {
    char m_pad[124];
    int m_flag;
    char m_tail[36];
};

struct RouteList_IR {
    Route_IR* m_begin;
    Route_IR* m_end;
};

struct cXPersonImpl_IR {
    char m_pad1036[1036];
    RouteList_IR m_routes;
    void InvalidateRoutes();
};

void cXPersonImpl_IR::InvalidateRoutes() {
    RouteList_IR* rl = &m_routes;
    Route_IR* cur = rl->m_begin;
    if (cur == rl->m_end) return;
    int zero = 0;
    do {
        cur->m_flag = zero;
        ++cur;
    } while (cur != rl->m_end);
}
