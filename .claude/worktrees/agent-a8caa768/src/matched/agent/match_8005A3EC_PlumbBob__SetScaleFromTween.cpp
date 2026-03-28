// 0x8005A3EC (112 bytes)
// PlumbBob::SetScaleFromTween(int, float)

class PlumbBob { public: void SetScaleFromTween(int, float); };

__attribute__((naked))
void PlumbBob::SetScaleFromTween(int, float) {
    asm volatile(".long 0x3D208047\n.long 0x5484103A\n.long 0x39295DCC\n.long 0x39290118\n.long 0x7D69202E\n.long 0x39200000\n.long 0x800B0160\n.long 0x2C000000\n.long 0x41820010\n.long 0x2C000008\n.long 0x41820008\n.long 0x39200001\n.long 0x2C090000\n.long 0x40820028\n.long 0x3D208048\n.long 0x3D60803D\n.long 0xC00955E4\n.long 0xC1AB4214\n.long 0x81230164\n.long 0xEC006828\n.long 0xEC00687A\n.long 0xD0090000\n.long 0x4E800020\n.long 0x3D20803D\n.long 0x81630164\n.long 0xC0094214\n.long 0xD00B0000\n.long 0x4E800020");
}
