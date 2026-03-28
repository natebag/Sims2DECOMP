// 0x80003FE4 (8 bytes)
class ESimsApp {
public:
    void SetStartLot(int lot);
};

void ESimsApp::SetStartLot(int lot) {
    register char *sda_base __asm__("r13");
    *(int *)(sda_base - 0x7FF0) = lot;
}
