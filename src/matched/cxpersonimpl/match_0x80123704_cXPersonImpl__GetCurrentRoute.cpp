// 0x80123704 (56B) cXPersonImpl::GetCurrentRoute(void)
// Returns &m_begin[count-1] where count = (m_end - m_begin) / sizeof(Route).
// sizeof(Route) = 164 bytes (mulli 164 in epilogue).

struct Route { char _pad[164]; };

class cXPersonImpl {
public:
    char _pad[1036];
    Route* m_begin;   // +1036
    Route* m_end;     // +1040
    Route* GetCurrentRoute();
};

Route* cXPersonImpl::GetCurrentRoute()
{
    int count = m_end - m_begin;
    if (count != 0) {
        --count;
        return &m_begin[count];
    }
    return 0;
}
