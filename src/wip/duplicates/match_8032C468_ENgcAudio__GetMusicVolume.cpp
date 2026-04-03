// 0x8032C468 (8 bytes)
class ENgcAudio {
public:
    float GetMusicVolume();
};

float ENgcAudio::GetMusicVolume() {
    return *(float*)((char*)this + 0x4);
}
