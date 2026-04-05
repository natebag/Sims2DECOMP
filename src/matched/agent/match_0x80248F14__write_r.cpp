/* _write_r at 0x80248F14 (88B) */
// FLAGS: -fno-elide-constructors

extern int g_errno__write_r;
extern int sys_write(int fd, void *buf, int count);

int _write_r(int *reent, int fd, void *buf, int count) {
    g_errno__write_r = 0;
    int result = sys_write(fd, buf, count);
    if (result == -1) {
        if (g_errno__write_r != 0) {
            *reent = g_errno__write_r;
        }
    }
    return result;
}
