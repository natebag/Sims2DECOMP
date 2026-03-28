/* cXObjectImpl::WaitingForSync(void) - 8 bytes */

class cXObjectImpl {
public:
    char pad[0xE4];
    int m_waitingForSync;

    int WaitingForSync(void);
};

int cXObjectImpl::WaitingForSync(void) {
    return m_waitingForSync;
}
