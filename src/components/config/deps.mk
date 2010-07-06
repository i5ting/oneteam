ifeq "$(MOZ_WIDGET_TOOLKIT)" "gtk2"
	ifeq "$(shell pkg-config --exists libpulse && echo 1)" "1"
		OT_HAS_PULSE_AUDIO=1
		OS_CXXFLAGS += -DOT_HAS_PULSE_AUDIO $(shell pkg-config --cflags libpulse glib-2.0)
		OT_EXTRA_SHARED_LIBS += $(otdir)/src/audio/$(LIB_PREFIX)ot_audio_s.$(LIB_SUFFIX)
		OT_EXTRA_SHARED_OS_LIBS += $(shell pkg-config --libs libpulse glib-2.0)
	endif

	OT_HAS_IDLE_UNIX=1
	OT_HAS_SYSTRAY_UNIX=1
	OT_HAS_DNS_UNIX=1
	OS_CXXFLAGS += -DOT_HAS_IDLE_UNIX -DOT_HAS_SYSTRAY_UNIX -DOT_HAS_DNS_UNIX \
		$(MOZ_GTK2_CFLAGS)
	OT_EXTRA_SHARED_REQS += imglib2 gfx
	OT_EXTRA_SHARED_OS_LIBS += -lX11 -lXss -lresolv -lrt $(MOZ_GTK2_LIBS)
	OT_EXTRA_SHARED_LIBS += \
		$(otdir)/src/idle/$(LIB_PREFIX)ot_idle_s.$(LIB_SUFFIX) \
		$(otdir)/src/systray/$(LIB_PREFIX)ot_systray_s.$(LIB_SUFFIX) \
		$(otdir)/src/dns/$(LIB_PREFIX)ot_dns_s.$(LIB_SUFFIX) \
		$(NULL)
endif

ifeq "$(MOZ_WIDGET_TOOLKIT)" "windows"
	OT_HAS_IDLE_WIN=1
	OT_HAS_SYSTRAY_WIN=1
	OT_HAS_DNS_WIN=1
	OS_CXXFLAGS += -DOT_HAS_IDLE_WIN -DOT_HAS_SYSTRAY_WIN -DOT_HAS_DNS_WIN
	OT_EXTRA_SHARED_LIBS += \
		$(otdir)/src/idle/$(LIB_PREFIX)ot_idle_s.$(LIB_SUFFIX) \
		$(otdir)/src/systray/$(LIB_PREFIX)ot_systray_s.$(LIB_SUFFIX) \
		$(otdir)/src/dns/$(LIB_PREFIX)ot_dns_s.$(LIB_SUFFIX) \
		$(NULL)
	OT_EXTRA_SHARED_OS_LIBS += shell32.lib dnsapi.lib iphlpapi.lib ws2_32.lib ole32.lib
	OT_HAS_WIN_AUDIO=1
	OS_CXXFLAGS += -DOT_HAS_WIN_AUDIO
	OT_EXTRA_SHARED_LIBS += $(otdir)/src/audio/$(LIB_PREFIX)ot_audio_s.$(LIB_SUFFIX)
	OS_CXXFLAGS += -I$(otdir)/libs/libglib/include/glib-2.0 \
		-I$(otdir)/libs/libglib/lib/glib-2.0/include
	OT_LDOPTS += \
		$(otdir)/libs/extra/glib/glib/glib-2.24s.lib \
		$(otdir)/libs/extra/glib/gobject/gobject-2.24s.lib \
		$(otdir)/libs/extra/glib/gthread/gthread-2.24s.lib \
		$(otdir)/libs/extra/intl/intl.lib \
		$(NULL)
endif

ifeq "$(MOZ_WIDGET_TOOLKIT)" "cocoa"
	OT_HAS_DNS_UNIX=1
	OT_HAS_MAC_AUDIO=1
	OT_HAS_OSXBADGE=1
	OS_CXXFLAGS += -DOT_HAS_DNS_UNIX -DOT_HAS_MAC_AUDIO -DOT_HAS_OSXBADGE
	OT_EXTRA_SHARED_OS_LIBS += -lresolv -liconv -lc \
		-framework AudioUnit -framework CoreAudio -framework AudioToolbox \
		-framework AppKit
	OT_EXTRA_SHARED_LIBS += \
		$(otdir)/src/dns/$(LIB_PREFIX)ot_dns_s.$(LIB_SUFFIX) \
		$(otdir)/src/audio/$(LIB_PREFIX)ot_audio_s.$(LIB_SUFFIX) \
		$(otdir)/src/osxbadge/$(LIB_PREFIX)ot_osxbadge_s.$(LIB_SUFFIX) \
		$(NULL)
	OT_LDOPTS += \
		/usr/local/lib/libglib-2.0.a \
		/usr/local/lib/libgobject-2.0.a \
		/usr/local/lib/libgthread-2.0.a \
		/usr/local/lib/libintl.a \
		$(NULL)
endif

OT_EXTRA_SHARED_LIBS += \
	$(otdir)/src/ice/$(LIB_PREFIX)ot_ice_s.$(LIB_SUFFIX) \
	$(otdir)/src/codecs/$(LIB_PREFIX)ot_codecs_s.$(LIB_SUFFIX) \
	$(otdir)/src/rtp/$(LIB_PREFIX)ot_rtp_s.$(LIB_SUFFIX) \
	$(otdir)/src/jnrelay/$(LIB_PREFIX)ot_jnrelay_s.$(LIB_SUFFIX) \
	$(NULL)

OT_LDOPTS += \
	$(otdir)/libs/libnice/build/$(LIB_PREFIX)nice.$(LIB_SUFFIX) \
	$(otdir)/libs/libspeex/build/$(LIB_PREFIX)speex.$(LIB_SUFFIX) \
	$(otdir)/libs/libspeex/build/$(LIB_PREFIX)speexdsp.$(LIB_SUFFIX) \
	$(otdir)/libs/libilbc/$(LIB_PREFIX)ilbc.$(LIB_SUFFIX) \
	$(NULL)

ifdef MOZ_DEBUG
	OT_HAS_DEBUG=1
	OT_EXTRA_SHARED_LIBS += \
		$(otdir)/src/debug/$(LIB_PREFIX)ot_debug_s.$(LIB_SUFFIX)
endif
