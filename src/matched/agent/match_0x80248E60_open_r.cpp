/* _open_r at 0x80248E60 (92B) */

extern int g_errno_open;
extern int sys_open(char *, int, int, ...);

int _open_r(int *reent, char *path, int flags, int mode) {
    g_errno_open = 0;
    int result = sys_open(path, flags, mode);
    if (result == -1) {
        if (g_errno_open != 0) {
            *reent = g_errno_open;
        }
    }
    return result;
}
