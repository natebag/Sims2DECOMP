// match_0x801a40e0_SimTickSample_copy_ctor.cpp
// Release build version (240 bytes)
// Copy constructor for SimTickSample

struct SimTickSample {
    int tick;
    int tickDuration;
    char pad1[8];
    int data1;
    int data2;
    int data3;
    char pad2[4];
    
    SimTickSample(const SimTickSample &src) {
        tick = src.tick;
        tickDuration = src.tickDuration;
        data1 = src.data1;
        data2 = src.data2;
        data3 = src.data3;
    }
};
