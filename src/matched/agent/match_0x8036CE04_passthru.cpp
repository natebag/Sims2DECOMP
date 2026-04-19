/* write at 0x8036CE04 (32B) */
// 0x8036CE04 (32 bytes)
extern int _write(int fd, const void* buf, unsigned int n);
int write(int fd, const void* buf, unsigned int n) {
    return _write(fd, buf, n);
}
