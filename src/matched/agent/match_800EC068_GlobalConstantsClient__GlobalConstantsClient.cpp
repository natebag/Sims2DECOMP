/* GlobalConstantsClient::GlobalConstantsClient(short) - 20 bytes */

struct GlobalConstantsClientVtable;
extern GlobalConstantsClientVtable __vt__21GlobalConstantsClient;

class GlobalConstantsClient {
public:
    GlobalConstantsClientVtable* vtable;
    short m_id;

    GlobalConstantsClient(short id);
};

GlobalConstantsClient::GlobalConstantsClient(short id) {
    m_id = id;
    vtable = &__vt__21GlobalConstantsClient;
}
