/* _close_r at 0x80248D60 (80B) */
// FLAGS: -fno-elide-constructors

extern int g_errno_close;
extern int sys_close(int);

int _close_r(int *reent, int fd) {
    g_errno_close = 0;
    int result = sys_close(fd);
    if (result == -1) {
        if (g_errno_close != 0) {
            *reent = g_errno_close;
        }
    }
    return result;
}
