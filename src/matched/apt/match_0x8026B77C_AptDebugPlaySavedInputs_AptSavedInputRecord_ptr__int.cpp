// FLAGS: -fno-schedule-insns
// 0x8026B77C AptDebugPlaySavedInputs(AptSavedInputRecord *, int) (32b)
struct AptSavedInputRecord;

struct AptSavedInputState {
    AptSavedInputRecord* records;
    AptSavedInputRecord* current;
    int count;
    int pad;
    int index;
};

extern AptSavedInputState g_AptSavedInputState;

void AptDebugPlaySavedInputs(AptSavedInputRecord* records, int count) {
    g_AptSavedInputState.index = 0;
    g_AptSavedInputState.records = records;
    g_AptSavedInputState.current = records;
    g_AptSavedInputState.count = count;
}
