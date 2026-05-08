// ActionQueueHUD::SelectPriorAction(void) @ 0x80184CDC (100B)

struct AQH_SPA {
    char _pad[0x319];
    signed char m_selectedAction;
    void SelectAction(signed char idx);
    void SelectPriorAction();
};

void AQH_SPA::SelectPriorAction() {
    signed char i = (signed char)(m_selectedAction - 1);
    goto cond;
update:
    i = (signed char)(i - 1);
cond:
    if (i < 0) return;
    {
        int cont = 1;
        if (*(unsigned char*)((char*)this + (int)i * 20 + 0xAD) == 0)
            cont = 0;
        if (cont) goto update;
        SelectAction(i);
    }
}
