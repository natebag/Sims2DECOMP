/* ObjectModuleImpl::GetNumPortals(void) - 20 bytes */

class ObjectModuleImpl {
public:
    char pad[0x2068];
    char* m_portalsBegin;
    char* m_portalsEnd;

    int GetNumPortals(void);
};

int ObjectModuleImpl::GetNumPortals(void) {
    return ((int)m_portalsEnd - (int)m_portalsBegin) >> 2;
}
