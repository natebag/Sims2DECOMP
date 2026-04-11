/* ObjectModuleImpl::GetPortal(int) at 0x800F99BC (16B) */

struct Portal;

struct ObjectModuleImpl {
    char pad[0x2068];
    Portal** m_portals;

    Portal* GetPortal(int index);
};

Portal* ObjectModuleImpl::GetPortal(int index) {
    int offset = index << 2;
    return *(Portal**)((char*)m_portals + offset);
}
