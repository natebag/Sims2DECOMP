/* KEYTarget::GetName(void) at 0x801F9960 (156b) */

extern const char *UIDB_UIDBGetString(const char *key);
extern const char gKEYNameA[];
extern const char gKEYNameB[];
extern const char gKEYNameC[];
extern const char gKEYNameD[];
extern const char gKEYDefault[];

struct KEYTarget {
    char pad_00[0x8C];
    int m_keyIndex;
};

const char *KEYTarget_GetName(KEYTarget *self) {
    const char *result = 0;
    switch (self->m_keyIndex) {
    case 1:
        result = UIDB_UIDBGetString(gKEYNameA);
        break;
    case 2:
        result = UIDB_UIDBGetString(gKEYNameB);
        break;
    case 3:
        result = UIDB_UIDBGetString(gKEYNameC);
        break;
    case 4:
        result = UIDB_UIDBGetString(gKEYNameD);
        break;
    }
    if (result == 0) {
        result = gKEYDefault;
    }
    return result;
}
