// 0x800985F8 (4 bytes)
// TheSimsEnterMainMenuState::Draw(ERC *)

class TheSimsEnterMainMenuState { public: void Draw(ERC *); };

__attribute__((naked))
void TheSimsEnterMainMenuState::Draw(ERC *) {
    asm volatile(".long 0x4E800020");
}
