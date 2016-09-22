# Created by: Michael Zhilin <mizhka@gmail.com>
# $FreeBSD$

PORTNAME=	goclipse
PORTVERSION=	0.16.1
CATEGORIES=	java devel
MASTER_SITES=	https://goclipse.github.io/releases/local-repo/
PKGNAMEPREFIX=	eclipse-
DISTFILES=	${BUNDLES}

MAINTAINER=	mizhka@gmail.com
COMMENT=	Go language plugin for Eclipse IDE

LICENSE=	EPL

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/share/eclipse/dropins/cdt/eclipse/features/org.eclipse.cdt_9.0.1.201607151550.jar:${PORTSDIR}/java/eclipse-cdt

USES=		zip
USE_JAVA=	YES
JAVA_OS=	native
JAVA_RUN=	YES
JAVA_VERSION=	1.8+

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}/

BUILDDATE=	20160706
BUILDTIME=	1938

FEATURES=	goclipse_feature
PLUGINS= 	com.googlecode.goclipse.core_${PORTVERSION}.v${BUILDDATE}${BUILDTIME} \
		com.googlecode.goclipse.debug_${PORTVERSION}.v${BUILDDATE}${BUILDTIME} \
		com.googlecode.goclipse.jvmcheck_1.0.0.v${BUILDDATE}${BUILDTIME} \
		com.googlecode.goclipse.tooling_${PORTVERSION}.v${BUILDDATE}${BUILDTIME} \
		com.googlecode.goclipse.ui_${PORTVERSION}.v${BUILDDATE}${BUILDTIME} \
		org.json_1.0.0.v201011060100

FEATURESLIST=	${FEATURES:S/$/_${PORTVERSION}.v${BUILDDATE}${BUILDTIME}.jar/}
PLUGINSLIST=	${PLUGINS:S/$/.jar/}

BUNDLES=	${FEATURESLIST:S/^/features\//} \
		${PLUGINSLIST:S/^/plugins\//}

FEATURESWRK=	${FEATURESLIST:S/^/${WRKSRC}\//}
PLUGINSWRK=	${PLUGINSLIST:S/^/${WRKSRC}\//}

PLUGINDIR=	share/eclipse/dropins/${PORTNAME}/eclipse

FEATURESINST=	${FEATURESLIST:S/^/${WRKSRC}\//}
PLUGINSINST=	${PLUGINSLIST:S/^/${WRKSRC}\//}

do-patch:
	@(mkdir -p		${WRKSRC}/features)
	@(mv ${FEATURESWRK}	${WRKSRC}/features/)
	@(mkdir -p		${WRKSRC}/plugins)
	@(mv ${PLUGINSWRK}	${WRKSRC}/plugins/)
	
do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/${PLUGINDIR})

.include <bsd.port.mk>
