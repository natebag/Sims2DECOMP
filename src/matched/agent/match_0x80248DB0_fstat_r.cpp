/* _fstat_r at 0x80248DB0 (88B) */

extern int g_errno_fstat;
extern int sys_fstat(int, void *, ...);

int _fstat_r(int *reent, int fd, void *buf) {
    g_errno_fstat = 0;
    int result = sys_fstat(fd, buf);
    if (result == -1) {
        if (g_errno_fstat != 0) {
            *reent = g_errno_fstat;
        }
    }
    return result;
}
