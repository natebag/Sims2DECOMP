// OSGetResetSwitchState - Nintendo SDK function
// Returns the state of the reset switch

extern "C" int __OSGetResetSwitchState(void);

extern "C" int OSGetResetSwitchState(void) {
    return __OSGetResetSwitchState();
}
