/* ENgcAudioSampleManager::ENgcAudioSampleManager at 0x8032CCF0 (68 bytes) */

extern int ENgcAudioSampleManager_vtable[];

void ENgcAudioSampleManBase_ctor(void*);

struct ENgcAudioSampleManager {
    char _pad_00[0x54];
    int m_field_54;
    char _pad_58[0xCC4];
    int* _vtable_D1C;

    ENgcAudioSampleManager();
};

ENgcAudioSampleManager::ENgcAudioSampleManager()
{
    ENgcAudioSampleManBase_ctor(this);
    m_field_54 = 1;
    _vtable_D1C = ENgcAudioSampleManager_vtable;
}
