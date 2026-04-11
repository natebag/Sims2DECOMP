/* PCinit at 0x8023EE40 (8B) */

extern void PCinit_impl(void);

void PCinit(void) {
    PCinit_impl();
}
