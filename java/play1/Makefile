# Created by: Michael Zhilin <mizhka@gmail.com>
# $FreeBSD$

PORTNAME=	play
PORTVERSION=	1.4.3
CATEGORIES=	java devel
MASTER_SITES=	https://downloads.typesafe.com/play/${PORTVERSION}/
PKGNAMESUFFIX=	1

MAINTAINER=	mizhka@gmail.com
COMMENT=	Java-based Play Framework v1

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.09:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.9:devel/py-simplejson

USES=		zip python
USE_JAVA=	YES
JAVA_OS=	native
JAVA_RUN=	YES
JAVA_VERSION=	1.8+

NO_BUILD=	YES

ECLIPSE_BUNDLE=	org.playframework.playclipse_0.7.0.jar
ECLIPSE_FILE=	support/eclipse/${ECLIPSE_BUNDLE}
ECLIPSE_DROP=	share/eclipse/dropins/play1/eclipse/plugins/

post-patch:
	${RM} -rf ${WRKSRC}/python
	${RM} ${WRKSRC}/play.bat

do-install:
	@(${INSTALL_SCRIPT} ${WRKSRC}/play ${STAGEDIR}${PREFIX}/bin/play1)
	@(cd ${WRKSRC}/framework/pym && ${COPYTREE_SHARE} "play" \
		${STAGEDIR}${PYTHON_LIBDIR}/site-packages)
	@(${RM} -rf ${WRKSRC}/framework/pym)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "modules framework resources" ${STAGEDIR}${PREFIX}/share/play/)
	@(${MKDIR} ${STAGEDIR}${PREFIX}/${ECLIPSE_DROP})
	@(${INSTALL_DATA} ${WRKSRC}/${ECLIPSE_FILE} ${STAGEDIR}${PREFIX}/${ECLIPSE_DROP}/${ECLIPSE_BUNDLE})

.include <bsd.port.mk>
