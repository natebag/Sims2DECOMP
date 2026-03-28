// 0x80119278 (8 bytes)
class cSampleChannel {
public:
    int Snd();
};

int cSampleChannel::Snd() {
    return *(int*)((char*)(*(int*)((char*)this + 0x0)) + 0x18);
}
