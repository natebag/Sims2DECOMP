// 0x8007E5F0 DlgWrapper::IsDialogUp (24 bytes)
// DOL:
//   lwz r0, 184(r3)
//   li r3, 1
//   cmpwi r0, 0
//   bgtlr            ; return 1 if dialog > 0
//   li r3, 0
//   blr

class DlgWrapper {
public:
    char pad[184];
    int m_dialog;     // offset 184
};

int DlgWrapper_IsDialogUp(DlgWrapper* this_) {
    if (this_->m_dialog > 0) return 1;
    return 0;
}
