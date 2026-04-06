// MATCH: 0x8023EE50 PCopen (8 bytes)
// Raw: 4B FF FF C4 4E 80 00 20
// Branch to 0x8023EE14

extern "C" void fn_8023EE14();

extern "C" void PCopen() {
    fn_8023EE14();
}
