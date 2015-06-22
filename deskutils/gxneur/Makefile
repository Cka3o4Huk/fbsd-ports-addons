# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD: head/deskutils/gxneur/Makefile 360658 2014-07-04 20:28:31Z tijl $

PORTNAME=	gxneur
PORTVERSION=	0.17.0
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpad.net/~andrew-crew-kuznetsov/+archive/xneur-stable/+files/
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK frontend for XNeur keyboard layout switcher

LICENSE=	GPLv2

BUILD_DEPENDS=	xneur:${PORTSDIR}/deskutils/xneur
RUN_DEPENDS=	xneur:${PORTSDIR}/deskutils/xneur

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	gconf2 gtk20 libglade2
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--without-nls

post-patch:
	@${REINPLACE_CMD} -e '/all_modifiers/d' ${WRKSRC}/src/misc.c
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/configure

.include <bsd.port.mk>
