# Created by: Michael Zhilin <mizhka@gmail.com>
# $FreeBSD$

PORTNAME=	metastyle
PORTVERSION=	0.8.29
CATEGORIES=	www net-im deskutils
MASTER_SITES=	GH
PKGNAMEPREFIX=	tdesktop-
DISTNAME=	${PKGNAMEPREFIX}${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	mizhka@gmail.com
COMMENT=	Telegram GUI client based on QT

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	telegramdesktop
GH_PROJECT=	tdesktop
GH_COMMIT=	607169c
GH_TAGNAME=	${GH_COMMIT}

WRKSRC?=	${WRKDIR}/${GH_PROJECT}-${GH_COMMIT}

USE_QT5=	core qmake_build buildtools_build
USES=		qmake
QMAKE_SOURCE_PATH= ${WRKSRC}/Telegram/MetaStyle.pro
QMAKE_ARGS+= 	INCLUDEPATH+=${LOCALBASE}/include \
		LIBS+=-L${LOCALBASE}/lib

PLIST_FILES=	bin/MetaStyle

do-install:
	@${ECHO_MSG} -n ">> Installing metastyle..."
	${INSTALL_PROGRAM} ${WRKDIR}/DebugStyle/MetaStyle ${STAGEDIR}/${PREFIX}/bin/MetaStyle

.include <bsd.port.mk>

