struct ESimsApp {
    char pad[0x450];
    int m_audioDisabled;
};

extern int gSoundManager;
extern int gAudioSystem;

void SoundManagerUpdate(void* mgr);
void* SimsAlloc(int size);
void* AudioSystemInit(void*);
void AudioSystemUpdate(void*);

void ESimsApp_UpdateAudio(ESimsApp* self) {
    if (self->m_audioDisabled == 0) {
        if (gSoundManager != 0) {
            SoundManagerUpdate((void*)gSoundManager);
        }
    }
    if (gAudioSystem == 0) {
        void* mem = SimsAlloc(120);
        gAudioSystem = (int)AudioSystemInit(mem);
    }
    AudioSystemUpdate((void*)gAudioSystem);
}
