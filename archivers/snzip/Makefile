# $FreeBSD: head/archivers/snzip/Makefile 412344 2016-04-01 13:29:15Z mat $

PORTNAME=	snzip
PORTVERSION=	1.0.4
CATEGORIES=	archivers

MAINTAINER=	mizhka@gmail.com
COMMENT=	Compression/decompression tool based on snappy library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsnappy.so:archivers/snappy

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	kubo
GH_TAGNAME=	03f81bdc55301fdff1c8a459fad7c0a29143a317

USES=		autoreconf
CONFIGURE_ARGS=	--with-snappy=${LOCALBASE}
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/snzip
PORTDOCS=	*

.include <bsd.port.mk>
