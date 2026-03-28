class EResLoadCmd;

class SubQueue {
public:
    void Send(EResLoadCmd*, int);
};

class EResourceLoaderImpl {
    char pad[888];
    SubQueue m_queue;
public:
    void sendCommand(EResLoadCmd*);
};

void EResourceLoaderImpl::sendCommand(EResLoadCmd* cmd) {
    m_queue.Send(cmd, 1);
}
