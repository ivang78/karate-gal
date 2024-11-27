all:
	zcc +gal -create-app  -pragma-redirect:fputc_cons=fputc_cons_generic -o karate-gal karate-gal.c
