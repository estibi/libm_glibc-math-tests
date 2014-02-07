TESTS=test-double \
	test-idouble \
	test-float \
	test-ifloat \
	test-ldouble \
	test-ildoubl \
	test-fenv

TESTS99 = $(TESTS:%=%.99)

%: %.c
	gcc -m64 -std=gnu99 -o $@ $< -lm

%.99: %.c
	gcc -m64 -std=gnu99 -o $@ $< /usr/lib/64/values-xpg6.o -lm

all: $(TESTS) $(TESTS99)

clobber:
	rm -f $(TESTS) $(TESTS99) *.out

BASELINE=~/fptest/sparcv9/baselinelibm.so.2
UNDER_TEST=/export/home/richlowe/illumos-git/usr/src/lib/libm/sparcv9/libm.so.2

test: all
	-@for elt in $(TESTS) $(TESTS99); do				\
	    LD_PRELOAD=$(BASELINE) ./$$elt > $${elt}-baseline.out;	\
	    LD_PRELOAD=$(UNDER_TEST) ./$$elt > $${elt}-results.out;	\
	    if ! diff -q $${elt}-baseline.out $${elt}-results.out; then	\
	        echo "$$elt results differ, see $${elt}-*.out";		\
	        diff -u $${elt}-baseline.out $${elt}-results.out;	\
	    else							\
	        echo "$$elt PASSED";					\
	    fi;								\
	done

.KEEP_STATE:
