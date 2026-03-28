/* cXPersonImpl::GetSimDescription(void) - 0x8012C8C0 - 16 bytes */
/* lwz r9, 0(r3); lwz r11, 0x8C(r9); lwz r3, 0x8C(r11); blr */

struct SimDescInner {
    char _pad[0x8C];
    void* m_simDescription;
};

struct PersonData {
    char _pad[0x8C];
    SimDescInner* m_inner;
};

class cXPersonImpl {
public:
    PersonData* m_data;

    void* GetSimDescription(void);
};

void* cXPersonImpl::GetSimDescription(void) {
    PersonData* data = m_data;
    SimDescInner* inner = data->m_inner;
    return inner->m_simDescription;
}
