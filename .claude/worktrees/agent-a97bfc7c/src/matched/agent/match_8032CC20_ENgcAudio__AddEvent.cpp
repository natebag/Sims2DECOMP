// 0x8032CC20 (4 bytes)
typedef int EA_EVENT;
class EMsgQueue;
class ENgcAudio {
public:
    void AddEvent(EA_EVENT, EMsgQueue&, unsigned int);
};
void ENgcAudio::AddEvent(EA_EVENT, EMsgQueue&, unsigned int) {}
