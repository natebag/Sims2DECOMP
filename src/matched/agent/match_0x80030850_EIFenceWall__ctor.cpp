// EIFenceWall::EIFenceWall(void) at 0x80030850 (72 bytes)
// Default ctor: chains to EIWallPart base ctor, overrides vtable, bumps counter.

class EIWallPart {
public:
    EIWallPart();
    virtual ~EIWallPart();
};

class EIFenceWall : public EIWallPart {
public:
    EIFenceWall();
    virtual ~EIFenceWall();
};

extern int gFenceCount;

EIFenceWall::EIFenceWall() {
    ++gFenceCount;
}
