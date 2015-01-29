# Created by: Michael Zhilin <mizhka@gmail.com>
# $FreeBSD$

PORTNAME=	tdesktop
PORTVERSION=	0.7.10
CATEGORIES=	www net-im deskutils
MASTER_SITES=	GH

MAINTAINER=	mizhka@gmail.com
COMMENT=	Telegram GUI client based on QT

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	Cka3o4Huk
GH_PROJECT=	tdesktop
GH_COMMIT=	54fedf4
GH_TAGNAME=	${GH_COMMIT}

USE_QT5=	gui network widgets qmake_build buildtools_build
USES=		qmake
QMAKE_SOURCE_PATH= ${WRKSRC}/Telegram/Telegram.pro
QMAKE_ARGS+= 	INCLUDEPATH+=${LOCALBASE}/include \
		LIBS+=-L${LOCALBASE}/lib

BUILD_DEPENDS=	MetaEmoji:www/tdesktop-metaemoji \
		MetaLang:www/tdesktop-metalang \
		MetaStyle:www/tdesktop-metastyle

.include <bsd.port.mk>

