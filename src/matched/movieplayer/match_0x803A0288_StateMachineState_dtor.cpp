// 0x803A0288 StateMachineState::~StateMachineState (52b)
// FLAGS: -fno-elide-constructors

extern int SMS_VT[];
void del_fn(void *);
void d_StateMachineState_StateMachineState(char *self, int __in_chrg) {
    *(int **)(self + 24) = SMS_VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
