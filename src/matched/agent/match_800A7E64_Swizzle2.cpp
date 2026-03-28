void Swizzle2(void *ptr) {
    char *p = (char *)ptr;
    char tmp = p[0];
    p[0] = p[1];
    p[1] = tmp;
}
