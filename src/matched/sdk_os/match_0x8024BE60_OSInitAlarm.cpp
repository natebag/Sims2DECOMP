// COMPILER: mwcc
// 0x8024BE60 OSInitAlarm (88B) — Dolphin SDK os/OSAlarm.c
//
// One-time alarm subsystem init: if the decrementer handler isn't ours yet,
// clear the alarm queue, install DecrementerExceptionCallback, and register
// the reset hook. __OSAlarmQueue is SDA (-23688(r13)). MWCC GC-1.2.5n.

struct OSAlarmQueue { void* head; void* tail; };
extern OSAlarmQueue __OSAlarmQueue;
extern "C" void* __OSGetExceptionHandler(int exception);
extern "C" void __OSSetExceptionHandler(int exception, void* handler);
extern "C" void OSRegisterResetFunction(void* info);
extern "C" void DecrementerExceptionCallback();
extern char AlarmResetFunctionInfo[];

extern "C" void OSInitAlarm(void) {
    if (__OSGetExceptionHandler(8) != (void*)DecrementerExceptionCallback) {
        __OSAlarmQueue.tail = 0;
        __OSAlarmQueue.head = 0;
        __OSSetExceptionHandler(8, (void*)DecrementerExceptionCallback);
        OSRegisterResetFunction(AlarmResetFunctionInfo);
    }
}
