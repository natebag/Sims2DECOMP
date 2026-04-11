// FLAGS: -fno-schedule-insns
// 0x8007E5F0 DlgWrapper::IsDialogUp (24b)

class DlgWrapper {
public:
    char pad[0xB8];   // padding to offset 0xB8 = 184
    int dialog;       // at offset 0xB8 = 184
};

int DlgWrapper_IsDialogUp(DlgWrapper* this_) {
    int result = 1;
    if (this_->dialog == 0) {
        result = 0;
    }
    return result;
}

extern "C" int _ZN10DlgWrapper10IsDialogUpEv(DlgWrapper* this_) {
    return DlgWrapper_IsDialogUp(this_);
}
