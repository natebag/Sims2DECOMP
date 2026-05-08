// ActionQueueHUD::OnUserCancelledAction(unsigned int) @ 0x80184FE0 (136B)

struct AQH_OCA_Item {
    unsigned int m_id;
    unsigned char m_f4;
    unsigned char m_f5;
    char _pad[14];
};

struct AQH_OCA {
    char _pad[0xa8];
    AQH_OCA_Item m_items[8];
    char _pad2[8];
    unsigned int m_count;
    void OnUserCancelledAction(unsigned int action_id);
};

void AQH_OCA::OnUserCancelledAction(unsigned int action_id) {
    unsigned int n = m_count;
    unsigned int i = 0;
    if (i < n) {
        unsigned int cap = n;
        AQH_OCA_Item* p = m_items;
        while (1) {
            unsigned int id = p->m_id;
            p++;
            if (id == action_id) {
                n = m_count;
                goto check;
            }
            i++;
            if (i >= cap) break;
        }
    }
    i = n = m_count;
check:
    if (i >= n) return;
    unsigned char active = 1;
    if (m_items[i].m_f5 == 0) active = 0;
    if (active != 0) return;
    m_items[i].m_f5 = 1;
}
