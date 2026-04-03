// match_0x801a41d0_SimLoopTickSample_copy_ctor.cpp
// Release build version (216 bytes)
// Copy constructor for SimLoopTickSample

struct SimLoopTickSample {
    int loopTick;
    int tick;
    int duration;
    char pad[4];
    
    SimLoopTickSample(const SimLoopTickSample &src) {
        loopTick = src.loopTick;
        tick = src.tick;
        duration = src.duration;
    }
};
