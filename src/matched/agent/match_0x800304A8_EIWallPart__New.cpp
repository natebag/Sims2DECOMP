void *WP_Alloc(int);
void *WP_Init(void *);

void *EIWallPart_New(void) {
    void *p = WP_Alloc(952);
    return WP_Init(p);
}
