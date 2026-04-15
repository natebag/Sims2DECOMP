/* RelMatrixImpl::CountKeys(void) - 0x801354C0 (20 bytes) */
struct KeyPtr { char data[4]; };
class RelMatrixImpl {
public:
    char pad[4];
    KeyPtr* m_begin;
    KeyPtr* m_end;
    int CountKeys(void);
};
int RelMatrixImpl::CountKeys(void) {
    return m_end - m_begin;
}
