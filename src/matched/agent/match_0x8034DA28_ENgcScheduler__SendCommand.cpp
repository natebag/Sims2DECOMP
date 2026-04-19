/* ENgcScheduler::SendCommand(ESchedCommand *) at 0x8034DA28 (40B) */

struct EMsgQueue_SC {
    void Send(unsigned int msg, int flag);
};

struct ENgcScheduler_SC {
    char pad[840];
    EMsgQueue_SC m_queue;
    void SendCommand(unsigned int cmd);
};

void ENgcScheduler_SC::SendCommand(unsigned int cmd) {
    m_queue.Send(cmd, 1);
}
