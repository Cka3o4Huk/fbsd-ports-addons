# $FreeBSD$

PORTNAME=	snzip
PORTVERSION=	1.0.2
CATEGORIES=	archivers

MAINTAINER=	mizhka@gmail.com
COMMENT=	Compression/decompression tool based on snappy library

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	kubo

LIB_DEPENDS=	libsnappy.so:${PORTSDIR}/archivers/snappy

USES=		autoreconf
CONFIGURE_ARGS=	--with-snappy=/usr/local
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
