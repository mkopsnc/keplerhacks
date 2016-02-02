RECIPES = sigsegv atexit dexit python

.PHONY: all

all:
	for RECIPE in ${RECIPES} ; do \
		$(MAKE) -C $${RECIPE} ; \
	done

test:
	for RECIPE in ${RECIPES} ; do \
		$(MAKE) -C $${RECIPE} test ; \
	done

clean:
	for RECIPE in ${RECIPES} ; do \
		$(MAKE) -C $${RECIPE} clean ; \
	done
