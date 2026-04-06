// MATCH: 0x8023EE48 PCcreat (8 bytes)
// Raw: 4B FF FF CC 4E 80 00 20
// Branch to 0x8023EE14

extern "C" void fn_8023EE14();

extern "C" void PCcreat() {
    fn_8023EE14();
}
