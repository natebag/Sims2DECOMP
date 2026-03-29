// 0x80034860 (60 bytes)
/* ESim::tProcessCommand(unsigned int) */

struct ESim_tProcessCommand {
    void tProcessCommand(unsigned int cmd);
    void initModel(void);
    void ChangeCostume(void);
};

void ESim_tProcessCommand::tProcessCommand(unsigned int cmd) {
    unsigned int c = cmd;
    if (c == 0) goto do_init;
    if (c == 1) goto do_change;
    goto done;
do_init:
    initModel();
    goto done;
do_change:
    ChangeCostume();
done:;
}
