/* disable_IRQ(void) at 0x8036C888 (72B) */

extern int g_irqCount;
extern int g_irqState;
extern int OSDisableInterrupts(void);

void disable_IRQ(void) {
    int count = g_irqCount + 1;
    g_irqCount = count;
    if (count == 1) {
        int old = OSDisableInterrupts();
        int enabled = 1;
        if (old == 0) enabled = 0;
        g_irqState = enabled;
    }
}
