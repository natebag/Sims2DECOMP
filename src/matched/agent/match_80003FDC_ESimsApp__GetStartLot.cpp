// 0x80003FDC (8 bytes)
class ESimsApp {
public:
    static int GetStartLot();
};

int ESimsApp::GetStartLot() {
    register char *sda_base __asm__("r13");
    return *(int *)(sda_base - 0x7FF0);
}
