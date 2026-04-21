#!/bin/bash
for addr in 801acc34 801acfc8 801ad004 801ad568 801ad820 801ad860 801ae1e4 801b8db0 801b8ddc 801b8e08 801b8ec8 801b8f04 801b8fd8 801b9014 801b9050 801b9088 801b91e4 801b9220 801b9260 801b928c 801b92b8 801b92e8 801dcd88 801dcdb4 801dce00; do
  found=$(find src/matched/ -name "*${addr}*" | head -1)
  if [ -z "$found" ]; then
    echo "OPEN:    $addr"
  else
    echo "MATCHED: $addr -> $found"
  fi
done
