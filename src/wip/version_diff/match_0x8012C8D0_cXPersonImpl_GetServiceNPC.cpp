/* cXPersonImpl::GetServiceNPC(void) - 0x8012C8D0 - 16 bytes */
/* lwz r9, 0(r3); lwz r11, 0x8C(r9); lwz r3, 0x90(r11); blr */

struct ServiceNPCInner {
    char _pad[0x90];
    void* m_serviceNPC;
};

struct PersonData2 {
    char _pad[0x8C];
    ServiceNPCInner* m_inner;
};

class cXPersonImpl {
public:
    PersonData2* m_data;

    void* GetServiceNPC(void);
};

void* cXPersonImpl::GetServiceNPC(void) {
    PersonData2* data = m_data;
    ServiceNPCInner* inner = data->m_inner;
    return inner->m_serviceNPC;
}
