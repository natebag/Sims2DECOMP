/* PlayerFamilyImpl::GetResfileStorageId(short) - 0x8012D1A4 - 8 bytes */
/* ori r3, r4, 0x4000; blr */

class PlayerFamilyImpl {
public:
    short GetResfileStorageId(short id);
};

short PlayerFamilyImpl::GetResfileStorageId(short id) {
    return id | 0x4000;
}
