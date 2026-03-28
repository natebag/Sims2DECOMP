/* EAudioStreamManager::EAudioStreamManager at 0x80323008 (68 bytes) */

extern int EAudioStreamManager_vtable[];

void BaseInit_Stream2(void*);

struct EAudioStreamManager {
    char _pad_00[0x54];
    int m_field_54;
    char _pad_58[0xCC4];
    int* _vtable_D1C;

    EAudioStreamManager();
};

EAudioStreamManager::EAudioStreamManager()
{
    BaseInit_Stream2(this);
    m_field_54 = 1;
    _vtable_D1C = EAudioStreamManager_vtable;
}
