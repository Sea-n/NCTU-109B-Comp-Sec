#!/usr/bin/env bash
cd "$(dirname "$0")" || exit 1

(
echo "a"
echo "n"
echo "<6A;"
sleep 1
) | nc 140.113.207.240 8833

echo

# FLAG{7h1s-1s-th3-Fl4g, y0u alr3ady-l3arn3d-0ur-14nguage!}
