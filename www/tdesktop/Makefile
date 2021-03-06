# Created by: Michael Zhilin <mizhka@gmail.com>
# $FreeBSD$

PORTNAME=	tdesktop
PORTVERSION=	0.7.10.2
CATEGORIES=	www net-im deskutils
MASTER_SITES=	GH

MAINTAINER=	mizhka@gmail.com
COMMENT=	Telegram GUI client based on QT

LICENSE=	GPLv3

BUILD_DEPENDS=	MetaEmoji:${PORTSDIR}/www/tdesktop-metaemoji \
		MetaLang:${PORTSDIR}/www/tdesktop-metalang \
		MetaStyle:${PORTSDIR}/www/tdesktop-metastyle
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libopus.so:${PORTSDIR}/audio/opus \
		libopusfile.so:${PORTSDIR}/audio/opusfile \
		libogg.so:${PORTSDIR}/audio/libogg \
		libopenal.so:${PORTSDIR}/audio/openal-soft

USE_GITHUB=	yes
GH_ACCOUNT=	telegramdesktop
GH_PROJECT=	tdesktop
GH_COMMIT=	57db4d5
GH_TAGNAME=	${GH_COMMIT}

WRKSRC_SUBDIR=	Telegram
MAKE_JOBS_UNSAFE=yes

USE_QT5=	gui network widgets qmake_build buildtools_build
USES=		qmake gmake
QMAKE_SOURCE_PATH= ${WRKSRC}/Telegram.pro
QMAKE_ARGS+= 	INCLUDEPATH+=${LOCALBASE}/include \
		LIBS+=-L${LOCALBASE}/lib

SUB_FILES=	Telegram.sh

do-install:
	@${ECHO_MSG} -n ">> Installing Telegram desktop..."
	${INSTALL_PROGRAM} ${WRKSRC}/../Debug/Telegram ${STAGEDIR}/${PREFIX}/bin/Telegram-exec
	${INSTALL_SCRIPT} ${WRKDIR}/Telegram.sh ${STAGEDIR}/${PREFIX}/bin/Telegram

.include <bsd.port.mk>
