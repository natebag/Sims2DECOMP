// FLAGS: -msdata=eabi -G 8
#include "types.h"

// ActionQueueHUD class - based on DOL analysis
// Key offsets:
//   0x308 (776): actionCount
//   0x30a (778): opState
//
// The struct needs explicit packing to match DOL layout

struct ActionQueueHUD {
    // First part - unknown size, use explicit offset markers
    unsigned char field_0[0x308];  // padding up to 0x308
    
    // Fields at 0x308+
    unsigned char actionCount;     // 0x308 (776)
    unsigned char field_309;       // 0x309
    unsigned char opState;         // 0x30a (778)
    unsigned char field_30b;       // 0x30b
    unsigned int field_30c;        // 0x30c - need this to align next fields
    // ... more fields
};

// External functions
extern void CompletePendingOperation(ActionQueueHUD* self);
extern void StartPendingOperation(ActionQueueHUD* self);
extern void RunActionQueue(ActionQueueHUD* self);
extern void UpdateVisual(ActionQueueHUD* self);

// 0x80185758 (96B)
// ActionQueueHUD::CatchUpPendingActions(void)
void CatchUpPendingActions(ActionQueueHUD* self) {
    if (self->opState != 0) {
        CompletePendingOperation(self);
    }
    
    while (self->actionCount > 17) {
        StartPendingOperation(self);
        CompletePendingOperation(self);
    }
    
    RunActionQueue(self);
}

// 0x801857B8 (104B)
// ActionQueueHUD::RunActionQueue(void)
void RunActionQueueFunc(ActionQueueHUD* self) {
    unsigned char state = self->opState;
    if (state != 0) {
        unsigned char newState = state - 1;
        self->opState = newState;
        if (newState == 0) {
            CompletePendingOperation(self);
            if (self->actionCount != 0) {
                StartPendingOperation(self);
            }
        }
        UpdateVisual(self);
    }
}
