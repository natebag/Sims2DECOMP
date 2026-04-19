/* 0x8012B5A0 (52B) cXPersonImpl::InvalidateRoutes(void) */

struct cXPersonImpl {
    char pad[0x40C];
    unsigned int m_routes;
    int m_count;

    void InvalidateRoutes(void);
};

void cXPersonImpl::InvalidateRoutes(void) {
    char* base = (char*)this + 0x40C;
    unsigned int routes = *(unsigned int*)base;
    int count = *(int*)(base + 4);

    if (routes == (unsigned int)count)
        return;

    *(int*)(routes + 0x7C) = 0;
    routes += 0xA4;

    count = *(int*)(base + 4);
    while ((int)routes != count) {
        *(int*)(routes + 0x7C) = 0;
        routes += 0xA4;
        count = *(int*)(base + 4);
    }
}
