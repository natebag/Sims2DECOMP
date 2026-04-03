// 0x8032C534 (8 bytes)
class ENgcAudio {
public:
    float GetMusicPan();
};

float ENgcAudio::GetMusicPan() {
    return *(float*)((char*)this + 0x8);
}
