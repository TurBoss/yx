# Tools.
GNUC		=	gcc
GNUCFLAGS	=	-I.
CC		=	sdcc
CFLAGS		=	-mz80 --no-std-crt0 -D DEBUG
AS		=	sdasz80
ASFLAGS		=	-xlos -g
LD		=	sdcc
LDFLAGS		=	-mz80 --no-std-crt0 --code-loc 0xc01f \
			--data-loc 0x5b00 -Wl -b_HEADER=0xbfff -Wl -b_IM2=0xfff0
# Deps.
CSRCS		=	$(wildcard *.c)
SSRCS		=	$(wildcard *.s)
OBJS		=	$(patsubst %.c,%.rel,$(CSRCS)) $(patsubst %.s,%.rel,$(SSRCS))

# Rules.
.PHONY:		all clean

all:		depend yx.bin

depend:		$(CSRCS)
		rm --force .depend
		$(GNUC) $(GNUCFLAGS) $(CSRCS) -MM >> .depend

-include 	.depend

yx.bin:		crt0.rel $(OBJS)
		$(LD) $(LDFLAGS) $^
		makezxbin <crt0.ihx >yx.bin
		appmake +zx --binfile ./yx.bin --org 49151
		fuse-gtk --tape ./yx.tap \
			--interface1 --interface2 \
			--kempston --kempston-mouse \
			--machine 48 --graphics-filter hq2x \
			#--debugger-command "br 0xD25B"

%.rel:		%.s
		$(AS) $(ASFLAGS) $(basename $*).rel $*.s

%.rel: 		%.c
		$(CC) -c -o $@ $< $(CFLAGS)

clean:		
		rm -f core *~ \#* *.cdb *.rel *.hex *.ihx *.lst *.asm *.map *.rel \
			*.rst *.sym *.lib *.bin *.mem *.lib kernel.s *.rom *.lnk \
			*.noi *.lk *.tap a.out
