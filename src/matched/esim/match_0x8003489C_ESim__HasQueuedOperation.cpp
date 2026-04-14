/* ESim::HasQueuedOperation(void) - 0x8003489C (28 bytes) */

struct ESim {
    char pad[0x43C];
    int m_queuedCount;
    char pad2[0xE0];
    int m_hasQueued;

    int HasQueuedOperation();
};

int ESim::HasQueuedOperation() {
    if (m_queuedCount > 0) {
        return 1;
    }
    return m_hasQueued;
}
