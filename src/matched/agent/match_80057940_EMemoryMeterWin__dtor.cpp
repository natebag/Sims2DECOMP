/* EMemoryMeterWin::~EMemoryMeterWin(void) at 0x80057940 (88B) */

extern int EMemoryMeterWin_vtable[];
extern int EMemoryMeterWin_base_vtable[];

void EMemoryMeterWin_Reset(void *self);
void __builtin_delete(void *ptr);

void EMemoryMeterWin_dtor(void *self, int delFlag) {
    *(int *)((char *)self + 4) = (int)EMemoryMeterWin_vtable;
    EMemoryMeterWin_Reset(self);
    *(int *)((char *)self + 4) = (int)EMemoryMeterWin_base_vtable;
    if (delFlag & 1) {
        __builtin_delete(self);
    }
}
