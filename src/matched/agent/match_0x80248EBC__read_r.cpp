/* _read_r at 0x80248EBC (88B) */

extern int g_errno__read_r;
extern int sys_read(int fd, void *buf, int count);

int _read_r(int *reent, int fd, void *buf, int count) {
    g_errno__read_r = 0;
    int result = sys_read(fd, buf, count);
    if (result == -1) {
        if (g_errno__read_r != 0) {
            *reent = g_errno__read_r;
        }
    }
    return result;
}
