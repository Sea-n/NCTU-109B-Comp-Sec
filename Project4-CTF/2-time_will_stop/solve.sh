#!/usr/bin/env bash
cd "$(dirname "$0")" || exit 1

strings time_will_stop \
| grep FLAG

# FLAG{Bin4RyANaly515_S0_EZZZZZZzzzzz}
