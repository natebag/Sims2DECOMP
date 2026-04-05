/* EIObjectMan::IsValidID(unsigned int) at 0x800549F4 (20B) */

struct EIObjectMan {
    static int IsValidID(unsigned int id);
};

int EIObjectMan::IsValidID(unsigned int id) {
    if (id != 0) return 1;
    return 0;
}
