/* EQuickdataManager::EQuickdataManager at 0x80325538 (72 bytes) */

extern int EQuickdataManager_vtable[];

void BaseInit_Stream3(void*);

struct EQuickdataManager {
    char _pad_00[0x54];
    int m_field_54;
    char _pad_58[0xCC4];
    int* _vtable_D1C;
    int m_field_D24;
    int m_field_D20;

    EQuickdataManager();
};

EQuickdataManager::EQuickdataManager()
{
    BaseInit_Stream3(this);
    m_field_D24 = 0;
    _vtable_D1C = EQuickdataManager_vtable;
    m_field_D20 = 0;
}
