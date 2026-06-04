// COMPILER: mwcc
// 0x80267200 AISetStreamSampleRate (40B) — Dolphin SDK ai/ai.c
//
// Delegates to AI_set_stream_sample_rate if rate == 1. MWCC schedules mflr early
// (before stwu), then conditional bl to the underlying implementation.

extern "C" void AI_set_stream_sample_rate(unsigned int rate);

extern "C" void AISetStreamSampleRate(unsigned int rate) {
    if (rate == 1)
        AI_set_stream_sample_rate(rate);
}
