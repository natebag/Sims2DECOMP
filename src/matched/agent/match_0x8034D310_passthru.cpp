/* ENgcSFXStreamer::SetLeftVolume(unsigned int, float) at 0x8034D310 (32B) */
// 0x8034D310 (32 bytes)

class ENgcSFXStreamer {
public:
    void SetLeftVolume(unsigned int id, float vol);
    void SetVolume(unsigned int id, float vol);
};

void ENgcSFXStreamer::SetLeftVolume(unsigned int id, float vol) {
    SetVolume(id, vol);
}
