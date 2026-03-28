// 0x8009ADCC (76 bytes)
// TheSimsNGCLicenseState::TheSimsNGCLicenseState(int)

class TheSimsNGCLicenseState { public: void TheSimsNGCLicenseState(int); };

__attribute__((naked))
void TheSimsNGCLicenseState::TheSimsNGCLicenseState(int) {
    asm volatile(".long 0x3D60803E\n.long 0x3D408046\n.long 0xC00B8DFC\n.long 0x7C691B78\n.long 0x38000000\n.long 0x3900FFFF\n.long 0x394AE418\n.long 0x39600001\n.long 0x90890000\n.long 0x9109000C\n.long 0x91690014\n.long 0x91490018\n.long 0xD009004C\n.long 0xB0090020\n.long 0x91090004\n.long 0x90090008\n.long 0x90090010\n.long 0x9009001C\n.long 0x4E800020");
}
