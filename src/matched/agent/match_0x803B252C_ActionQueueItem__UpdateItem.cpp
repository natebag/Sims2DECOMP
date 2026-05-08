// ActionQueueHUD::ActionQueueItem::UpdateItem(ActionQueueItem*) @ 0x803B252C (108B)

void EResource_AddRef(void* obj);
void EResource_DelRef(void* obj);

struct AQI_UI {
    char* m_name;
    unsigned int m_id;
    void* m_shader;
    unsigned int m_guid;
    void UpdateItem(AQI_UI* src);
};

void AQI_UI::UpdateItem(AQI_UI* src) {
    m_name = src->m_name;
    m_id = src->m_id;
    if (src->m_shader) {
        EResource_AddRef(src->m_shader);
    }
    if (m_shader) {
        EResource_DelRef(m_shader);
    }
    m_shader = src->m_shader;
    m_guid = src->m_guid;
}
