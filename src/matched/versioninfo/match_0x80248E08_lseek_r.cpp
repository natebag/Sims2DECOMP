/* _lseek_r at 0x80248E08 (88B) */

extern int g_errno;
extern int sys_lseek(int, int, int);

int _lseek_r(int *reent, int fd, int offset, int whence) {
    g_errno = 0;
    int result = sys_lseek(fd, offset, whence);
    if (result == -1) {
        if (g_errno != 0) {
            *reent = g_errno;
        }
    }
    return result;
}
