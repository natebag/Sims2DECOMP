// 0x801B2994 (92 bytes)
// FAMTarget::GetNumberOfChoicesInState(FAMTarget::FAM_STATE)

class FAMTarget { public: void GetNumberOfChoicesInState(FAMTarget::FAM_STATE); };

__attribute__((naked))
void FAMTarget::GetNumberOfChoicesInState(FAMTarget::FAM_STATE) {
    asm volatile(".long 0x2C040002\n.long 0x41820038\n.long 0x41810018\n.long 0x2C040000\n.long 0x41820024\n.long 0x2C040001\n.long 0x41820024\n.long 0x48000038\n.long 0x2C040003\n.long 0x41820020\n.long 0x2C040004\n.long 0x41820020\n.long 0x48000024\n.long 0x80630154\n.long 0x4E800020\n.long 0x38600002\n.long 0x4E800020\n.long 0x38600003\n.long 0x4E800020\n.long 0x80630158\n.long 0x4E800020\n.long 0x3860FFFF\n.long 0x4E800020");
}
