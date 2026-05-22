// 0x8023BD0C XmlGetNodeValue (68B)
// Copies src into dest until '\0' or '<', max maxLen-1 chars, null-terminates.
// ASMPROC_gpr_relabel: swap="9:11"
// ASMPROC_replace_insn: match="lbzx 0,3,11" replacement="lbzx 9,3,11"
// ASMPROC_inject_before: before="cmpwi 0,0,0" lines="clrlwi 0,9,24"
// ASMPROC_replace_insn: match="stbx 0,4,11" replacement="stbx 9,4,11" which=first

int XmlGetNodeValue(const char* src, char* dest, int maxLen) {
    int i = 0;
    int limit = maxLen - 1;
    unsigned char c;
    while ((c = (unsigned char)src[i]) && c != '<' && i < limit) {
        dest[i] = (char)c;
        i++;
    }
    dest[i] = '\0';
    return i + 1;
}
