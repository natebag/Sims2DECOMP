// 0x801A7070 (100 bytes)
// MakeMoneyString(StringBuffer2 &, int)

class StackString2;
class StringBuffer2;

// GetMoneyString formats an integer to a string with commas
extern void GetMoneyString(int value, StackString2 &output, bool unknown);

void MakeMoneyString(StringBuffer2 &output, int money) {
    // Create a temporary StackString2 with 256 chars
    StackString2 tempStr(256);
    
    // Call the helper to format money
    GetMoneyString(money, tempStr, false);
    
    // Copy the formatted string to output buffer
    output.copy(tempStr.c_str());
}
