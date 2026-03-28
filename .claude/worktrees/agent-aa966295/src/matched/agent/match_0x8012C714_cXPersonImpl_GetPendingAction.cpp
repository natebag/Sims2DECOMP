/* cXPersonImpl::GetPendingAction(void) const - 0x8012C714 - 24 bytes */
/* lwz r0, 0x534(r3); li r3, 0; cmpwi r0, 0; beqlr; li r3, 1; blr */

class cXPersonImpl {
public:
    char _pad[0x534];
    int m_pendingAction;

    int GetPendingAction(void) const;
};

int cXPersonImpl::GetPendingAction(void) const {
    if (m_pendingAction == 0) return 0;
    return 1;
}
