# Created by: Karsten Pedersen <kpedersen@opencde.org>
# $FreeBSD: head/devel/radare2/Makefile 418323 2016-07-10 14:48:57Z pi $

PORTNAME=	radare2
PORTVERSION=	0.10.6
CATEGORIES=	devel
MASTER_SITES=	http://rada.re/get/

MAINTAINER=	torres.73a@gmail.com
COMMENT=	Tools to disasm, debug, analyze, and manipulate binary files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS+=		pkg-config:devel/pkgconf
LIB_DEPENDS+=		libcapstone.so:devel/capstone4

CONFIGURE_ARGS+=	--with-syscapstone

USES=		gmake pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAKE_ENV+=	HOST_CC=${CC}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|..LIBDIR./pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/libr/Makefile
	${ECHO_CMD} 'CFLAGS+=-I${LOCALBASE}/include' >> ${WRKSRC}/libr/anal/Makefile
	${ECHO_CMD} 'CFLAGS+=-I${LOCALBASE}/include' >> ${WRKSRC}/libr/asm/Makefile

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's| install-doc ||g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
