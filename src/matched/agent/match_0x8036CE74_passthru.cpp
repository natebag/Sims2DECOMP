/* read at 0x8036CE74 (32B) */
// 0x8036CE74 (32 bytes)
extern int PCread(int fd, void* buf, unsigned int n);
int read(int fd, void* buf, unsigned int n) {
    return PCread(fd, buf, n);
}
