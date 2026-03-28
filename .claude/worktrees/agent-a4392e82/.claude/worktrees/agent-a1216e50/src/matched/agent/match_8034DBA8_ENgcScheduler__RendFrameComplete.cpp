// 0x8034DBA8 (4 bytes)
typedef void ESchedCommand;
class ENgcScheduler {
public:
    void RendFrameComplete(ESchedCommand*);
};
void ENgcScheduler::RendFrameComplete(ESchedCommand*) {}
