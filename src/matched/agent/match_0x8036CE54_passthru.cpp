/* lseek at 0x8036CE54 (32B) */
// 0x8036CE54 (32 bytes)
extern long PClseek(int fd, long offset, int whence);
long lseek(int fd, long offset, int whence) {
    return PClseek(fd, offset, whence);
}
