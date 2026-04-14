// 0x802941CC (48b)
extern int someFunc(void);
int wrapper() {
    return someFunc() ? 366 : 365;
}
