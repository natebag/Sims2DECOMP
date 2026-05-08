// ActionQueueHUD::ActionQueueItem::SetupItem(char*, unsigned int, ERShader*, unsigned int) @ 0x803B24C8 (100B)
// ASMPROC_replace_insn: match="30,8(31)" replacement="29,12(31)"
// ASMPROC_replace_insn: match="29,12(31)" replacement="30,8(31)" occurrence=1

void EResource_AddRef(void* obj);
void EResource_DelRef(void* obj);

struct AQI_SI {
    char* m_name;
    unsigned int m_id;
    void* m_shader;
    unsigned int m_guid;
    void SetupItem(char* name, unsigned int id, void* shader, unsigned int guid);
};

void AQI_SI::SetupItem(char* name, unsigned int id, void* shader, unsigned int guid) {
    m_name = name;
    m_id = id;
    if (shader) {
        EResource_AddRef(shader);
    }
    if (m_shader) {
        EResource_DelRef(m_shader);
        m_shader = 0;
    }
    m_guid = guid;
    m_shader = shader;
}
