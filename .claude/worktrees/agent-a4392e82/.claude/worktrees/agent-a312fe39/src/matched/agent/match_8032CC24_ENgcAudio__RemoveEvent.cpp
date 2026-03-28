// 0x8032CC24 (4 bytes)
typedef int EA_EVENT;
class EMsgQueue;
class ENgcAudio {
public:
    void RemoveEvent(EA_EVENT, EMsgQueue&, unsigned int);
};
void ENgcAudio::RemoveEvent(EA_EVENT, EMsgQueue&, unsigned int) {}
