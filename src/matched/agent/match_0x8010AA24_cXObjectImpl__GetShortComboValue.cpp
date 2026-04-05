/* cXObjectImpl::GetShortComboValue(signed char, short *, short *) - 0x8010AA24 - 128 bytes */
/* Maps a signed char combo index to a (dataSource, subIndex) pair */

class cXObjectImpl {
public:
    void GetShortComboValue(signed char param, short *out1, short *out2);
};

void cXObjectImpl::GetShortComboValue(signed char param, short *out1, short *out2) {
    if (!param) {
        *out1 = 3;
        *out2 = 11;
    } else if (param == 1) {
        *out1 = 10;
        *out2 = 0;
    } else if ((unsigned char)(param - 2) <= 7) {
        *out1 = 8;
        *out2 = param - 2;
    } else if ((unsigned char)(param - 10) <= 7) {
        *out1 = 25;
        *out2 = param - 10;
    } else if ((unsigned char)(param - 18) <= 7) {
        *out1 = 9;
        *out2 = param - 18;
    } else {
        *out1 = 7;
        *out2 = param - 126;
    }
}
