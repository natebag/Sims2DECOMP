// 0x80143030 (92 bytes)
// SpriteSlot::SetSprite(ObjSelector *)

class SpriteSlot { public: void SetSprite(ObjSelector *); };

__attribute__((naked))
void SpriteSlot::SetSprite(ObjSelector *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x3BA0FFFF\n.long 0x806DAC48\n.long 0x39200001\n.long 0x909E0028\n.long 0x38000000\n.long 0x93BE0018\n.long 0x7FC4F378\n.long 0x901E0030\n.long 0x913E0034\n.long 0x913E002C\n.long 0x4BEFE679\n.long 0x93BE0040\n.long 0x93BE003C\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
