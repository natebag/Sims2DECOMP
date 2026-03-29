/* ESim::tProcessCommand(unsigned int) at 0x80034860 (60B) */
/* DOL: mr. r4,r4; beq initModel; cmpwi r4,1; beq ChangeCostume; b done */
/* block order: initModel, ChangeCostume, done */

struct ESim {
    void tProcessCommand(unsigned int cmd);
    void initModel(void);
    void ChangeCostume(void);
};

void ESim::tProcessCommand(unsigned int cmd)
{
    unsigned int c = cmd;
    if (c == 0)
        goto do_init;
    if (c == 1)
        goto do_costume;
    goto done;
do_init:
    initModel();
    goto done;
do_costume:
    ChangeCostume();
done:;
}
