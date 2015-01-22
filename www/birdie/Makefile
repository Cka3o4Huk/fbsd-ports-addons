# Created by: Michael Zhilin <mizhka@gmail.com>
# $FreeBSD$

PORTNAME=	birdie
PORTVERSION=	2.0.beta.0.9
CATEGORIES=	www
MASTER_SITES=	GH

MAINTAINER=	mizhka@gmail.com
COMMENT=	Twitter client based on python / Gtk & GLib.

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	Cka3o4Huk
GH_PROJECT=	birdie
GH_COMMIT=	d492046
GH_TAGNAME=	${GH_COMMIT}

BUILD_DEPENDS=  gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		yelp.m4:${PORTSDIR}/textproc/yelp-tools \
		intltool>=0.25:${PORTSDIR}/textproc/intltool \
		itstool:${PORTSDIR}/textproc/itstool \
		nls.m4:${PORTSDIR}/devel/gettext-tools \
		automake>=1.11.2:${PORTSDIR}/devel/automake \
		req:${PORTSDIR}/www/py-requests-oauthlib \
		gtksourceview3:${PORTSDIR}/x11-toolkits/gtksourceview3

RUN_DEPENDS=	req:${PORTSDIR}/www/py-requests-oauthlib \
		pillow:${PORTSDIR}/graphics/py-pillow

USES=		python:2.7 gmake gettext libtool:build pkgconfig desktop-file-utils

INSTALLS_ICONS=	yes

do-configure:
	cd ${WRKSRC} && ${SH} autogen.sh && ./configure

.include <bsd.port.mk>
