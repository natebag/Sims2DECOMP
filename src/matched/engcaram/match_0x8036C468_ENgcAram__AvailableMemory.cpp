// 0x8036C468 (20B) ENgcAram::AvailableMemory(void)

extern int gAramTop;   // SDA r13-25824
extern int gAramBase;  // SDA r13-25828

class ENgcAram {
public:
    static int AvailableMemory();
};

int ENgcAram::AvailableMemory() {
    int adjusted = gAramTop - 0x01000000;
    return gAramBase - adjusted;
}
