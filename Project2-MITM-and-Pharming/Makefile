all:
	sudo sysctl -w net.ipv4.ip_forward=1
	chmod +x mitm_attack pharm_attack mitm_grep.sh
	mkdir -p sslsplit-log
	sudo iptables -t nat -F
	sudo iptables -t nat -A PREROUTING -p tcp --dport 443 -j REDIRECT --to-ports 8443
	touch ~/.rnd
	openssl genrsa -out ca.key 4096
	openssl req -new -x509 -days 1826 -key ca.key -out ca.crt \
		-subj '/C=TW/O=NCTU/CN=sean.taipei'

clean:
	-rm ca.key ca.crt
	-rm -rf sslsplit-log/

pack:
	7z a 0816146.7z Makefile mitm_attack pharm_attack mitm_grep.sh
