// 0x8032B004 (108 bytes)
// InverseSolarize(short *, short *, int, int, ImageProcessingManager::FilterParams *)

class InverseSolarize(short *, short *, int, int, ImageProcessingManager { public: void FilterParams *)(); };

__attribute__((naked))
void InverseSolarize(short *, short *, int, int, ImageProcessingManager::FilterParams *)() {
    asm volatile(".long 0x7C0531D7\n.long 0x7C0903A6\n.long 0x4C810020\n.long 0x38C00000\n.long 0x7C061AAE\n.long 0xA9070004\n.long 0x540B06FE\n.long 0x540AB6FE\n.long 0x5409DEFE\n.long 0x7C0B4000\n.long 0x40800008\n.long 0x7D6B58F8\n.long 0x7C094000\n.long 0x40800008\n.long 0x7D2948F8\n.long 0x7C0A4000\n.long 0x40800008\n.long 0x7D4A50F8\n.long 0x5540546A\n.long 0x55292DB4\n.long 0x7C004B78\n.long 0x556B06FE\n.long 0x7C005B78\n.long 0x7C06232E\n.long 0x38C60002\n.long 0x4200FFAC\n.long 0x4E800020");
}
