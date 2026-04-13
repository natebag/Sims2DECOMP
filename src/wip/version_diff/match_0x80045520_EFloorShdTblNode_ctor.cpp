// MATCH: 0x80045520 EFloorShdTblNode::EFloorShdTblNode (36 bytes)
// Raw: 7C 69 1B 78 38 00 00 00 39 69 00 04 39 40 00 01 90 0B 00 04 90 09 00 04 91 4B 00 08 90 09 00 00 4E 80 00 20
// FLAGS: -fno-elide-constructors

struct EFloorShdTblNode {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
};

extern "C" void EFloorShdTblNode_ctor(EFloorShdTblNode* this_) {
    this_->field_0 = 0;
    this_->field_4 = 0;
    this_->field_8 = 1;
    this_->field_c = 0;
}
