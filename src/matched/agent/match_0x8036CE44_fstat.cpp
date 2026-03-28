struct stat_t {
    int st_dev;
    int st_mode;
};
int fstat(int, stat_t *buf);
int fstat(int, stat_t *buf) { buf->st_mode = 0x2000; return 0; }
