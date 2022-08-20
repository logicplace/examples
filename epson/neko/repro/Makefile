# Run with mk88
name := neko

# Defines
is_$(MAKE) := true
ifdef is_mk88
RM := $(PRODDIR)\..\rm.bat
SREC_CAT := $(PRODDIR)\..\srec_cat.bat
else
PRODDIR := ../../c88tools
SREC_CAT := srec_cat
endif

CCFLAGS := -Md -I"$(PRODDIR)\..\include" -v -d pokemini -Tc-v -Tlc"-e -M -f2"
ASFLAGS = $(CCFLAGS)

# Phony steps
all: $(name).min

.PHONY: all, clean

$(name).min: $(name).sre
	$(SREC_CAT) $! -o $@ -binary

$(name).sre: isr.obj startup.obj main.obj gfx.obj
	$(CC) $(CCFLAGS) -o $@ $!

isr.obj: isr.c neko.h
	$(CC) -c -o $@ $(CCFLAGS) $!

main.obj: main.c neko.h
	$(CC) -c -o $@ $(CCFLAGS) main.c

gfx.obj: gfx.c neko.h
	$(CC) -c -o $@ $(CCFLAGS) gfx.c


# Debugging build steps
.c.src:
	$(CC) $(CCFLAGS) -cs -Tc"-o $@" $<

clean:
	$(RM) *.obj *.src $(name).sre $(name).map $(name).min
