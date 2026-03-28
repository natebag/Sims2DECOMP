// 0x80364E58 (96 bytes)
// ERenderSurface::Create(ERenderSurfaceDef &)

class ERenderSurface { public: void Create(ERenderSurfaceDef &); };

__attribute__((naked))
void ERenderSurface::Create(ERenderSurfaceDef &) {
    asm volatile(".long 0x7C691B78\n.long 0x39600018\n.long 0x80040000\n.long 0x356BFFE8\n.long 0x90090000\n.long 0x80040004\n.long 0x90090004\n.long 0x80040008\n.long 0x90090008\n.long 0x8004000C\n.long 0x9009000C\n.long 0x80040010\n.long 0x90090010\n.long 0x80040014\n.long 0x38840018\n.long 0x90090014\n.long 0x39290018\n.long 0x4082FFC4\n.long 0x80040000\n.long 0x38600001\n.long 0x90090000\n.long 0x80040004\n.long 0x90090004\n.long 0x4E800020");
}
