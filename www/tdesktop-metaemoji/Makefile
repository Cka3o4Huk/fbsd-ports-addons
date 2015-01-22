# Created by: Michael Zhilin <mizhka@gmail.com>
# $FreeBSD$

PORTNAME=	tdesktop-metaemoji
PORTVERSION=	0.7.8
DISTNAME=	tdesktop-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
CATEGORIES=	www net-im deskutils
MASTER_SITES=	GH

MAINTAINER=	mizhka@gmail.com
COMMENT=	Telegram GUI client based on QT

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	telegramdesktop
GH_PROJECT=	tdesktop
GH_COMMIT=	12f6b34
GH_TAGNAME=	${GH_COMMIT}

USE_QT5=	core qmake_build buildtools_build
USES=		qmake
QMAKE_SOURCE_PATH= ${WRKSRC}/Telegram/MetaEmoji.pro
QMAKE_ARGS+= 	INCLUDEPATH+=${LOCALBASE}/include \
		LIBS+=-L${LOCALBASE}/lib

do-install:
	@${ECHO_MSG} -n ">> Installing metaemoji..."
	@${INSTALL_PROGRAM} ${WRKDIR}/DebugEmoji/MetaEmoji ${STAGEDIR}/${PREFIX}/bin/MetaEmoji

.include <bsd.port.mk>

