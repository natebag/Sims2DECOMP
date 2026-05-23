/* GoalUnlock__ClearGoalsAndUnlocks_void at 0x800B8510 (44B) — auto-matched [param_fwd_44B_addi] */

typedef unsigned char u8;
extern int target_800B8510(int a0, int a1, int a2);

int param_fwd_800B8510(u8 *self, int a1, int a2) {
    return target_800B8510((int)(self + 4), 0, 128);
}
