// 0x80016BD4 (96 bytes)
// ESimsCam::SetMode(ESimsCam::CameraMode)

class ESimsCam { public: typedef int CameraMode; void SetMode(CameraMode); };

__attribute__((naked))
void ESimsCam::SetMode(ESimsCam::CameraMode) {
    asm volatile(".long 0x3D208047\n.long 0x80030004\n.long 0x39295DCC\n.long 0x39290118\n.long 0x5400103A\n.long 0x7D29002E\n.long 0x2C090000\n.long 0x41820028\n.long 0x80090160\n.long 0x39200000\n.long 0x2C000000\n.long 0x41820010\n.long 0x2C000008\n.long 0x41820008\n.long 0x39200001\n.long 0x2C090000\n.long 0x4C820020\n.long 0x2C040002\n.long 0x40820008\n.long 0x808303D0\n.long 0x800303CC\n.long 0x908303CC\n.long 0x900303D0\n.long 0x4E800020");
}
