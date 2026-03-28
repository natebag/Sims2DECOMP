// 0x8007E608 (24 bytes)

class DlgWrapper {
public:
    int DialogAccepted();
};

int DlgWrapper::DialogAccepted() {
    asm volatile(
        "lwz 9, 0xAC(3)\n"
        "lwz 3, 0x34(9)\n"
        "xori 3, 3, 1\n"
        "subfic 0, 3, 0\n"
        "adde 3, 0, 3\n"
        "blr\n"
    );
}
