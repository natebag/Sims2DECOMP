extern void* __files;
extern void cleanup_inner(void* files);

void cleanup_func() {
    cleanup_inner(__files);
}
