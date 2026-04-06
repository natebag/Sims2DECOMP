// 0x80325590 EQuickdataManager::SetCurrentLanguage (52b)

extern void EQuickdataManager_ReloadData(void*);

struct EQuickdataManager {
    char pad[0xD20];
    int m_language;
};

void EQuickdataManager_SetCurrentLanguage(EQuickdataManager* self, int lang) {
    EQuickdataManager_ReloadData(self);
    self->m_language = lang;
}
