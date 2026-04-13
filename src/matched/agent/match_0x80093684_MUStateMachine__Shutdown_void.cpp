/* MUStateMachine__Shutdown_void at 0x80093684 (60B) — auto-matched [dual_call_sub_60B] */

void f1_80093684(void*);
void f2_80093684(void*);
void f3_80093684(void*);

void func_80093684(char* self) {
    f1_80093684(self);
    f2_80093684(self + 60);
    f3_80093684(self);
}
