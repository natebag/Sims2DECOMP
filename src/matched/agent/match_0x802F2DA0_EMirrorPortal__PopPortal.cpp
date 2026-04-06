// 0x802F2DA0 EMirrorPortal::PopPortal (44b)

struct EMirrorPortal {
    char pad[60];
    int numPortals;
};

extern void PopPortalImpl(void*, int);

void EMirrorPortal_PopPortal(EMirrorPortal* self, void* window) {
    int n = self->numPortals;
    PopPortalImpl(window, n);
}
