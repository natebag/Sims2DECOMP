// 0x80248A6C (32B) lflush
// Thunk to fflush

extern void fflush(void);

void lflush(void) {
    fflush();
}
