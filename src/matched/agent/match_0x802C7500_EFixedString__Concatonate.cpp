struct EFixedString;

void EFixedString_ConcatonateInner(EFixedString* self, char* str, short* wc);

void EFixedString_Concatonate(EFixedString* self, char* str, char c) {
    short wc = (short)(c << 8);
    EFixedString_ConcatonateInner(self, str, &wc);
}
