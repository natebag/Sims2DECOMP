// 0x8032C614 ENgcAudio::FreeVoice(EVoice *) (72B)

struct EVoice { char pad[32]; };

class ENgcAudio {
public:
    virtual ~ENgcAudio();
    virtual void InitAudio();
    virtual void Shutdown();
    virtual void Update();
    virtual void Flush(bool);
    virtual void AddEvent(int, void*, unsigned int);
    virtual void RemoveEvent(int, void*, unsigned int);
    virtual void PlayMusic(void*);
    virtual void StopMusic();
    virtual void PauseMusic();
    virtual void ResumeMusic();
    virtual void SetMusicVolume(float);
    virtual float GetMusicVolume();
    virtual void SetMusicPan(float);
    virtual float GetMusicPan();
    virtual bool IsPlayingMusic();
    virtual EVoice* AudioAllocVoice();
    virtual void FreeVoice(EVoice* voice);
    virtual void AudioBindVoice(EVoice*, unsigned int);
    virtual void UnbindVoice(EVoice*);
};

void ENgcAudio::FreeVoice(EVoice* voice) {
    UnbindVoice(voice);
    delete voice;
}
