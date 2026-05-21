// 0x800A533C (76B) __static_initialization_and_destruction_0

inline void* operator new(unsigned int, void* p) { return p; }

struct CTGDump {
    CTGDump();
    ~CTGDump();
};

extern char gCTGDump[4];

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority == 0x0000FFFF) {
        if (__initialize_p != 0) {
            new(gCTGDump) CTGDump();
        } else {
            ((CTGDump*)gCTGDump)->~CTGDump();
        }
    }
}
