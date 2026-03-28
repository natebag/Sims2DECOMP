// 0x8034D9E4 (4 bytes)
typedef void ESchedCommand;
class ENgcScheduler {
public:
    void RenderingComplete(ESchedCommand*);
};
void ENgcScheduler::RenderingComplete(ESchedCommand*) {}
