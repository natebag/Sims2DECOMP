/* TreeSimImpl::ClearError - 0x80147444 (12 bytes) */

class TreeSimImpl {
public:
    char pad[0x34];
    short m_error;
    void ClearError();
};

void TreeSimImpl::ClearError() {
    m_error = 0;
}
