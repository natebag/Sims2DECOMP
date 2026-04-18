// 0x8017775C (68B) UIAUDIO::Update(void)
struct UIAUDIO {
    void Update();
    void UpdateAudioLoad(int);
};

void UIAUDIO::Update() {
    int i = 0;
    do {
        UpdateAudioLoad(i);
        ++i;
    } while (i <= 4);
}
