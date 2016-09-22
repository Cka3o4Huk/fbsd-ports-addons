# Created by: Michael Zhilin <mizhka@gmail.com>
# $FreeBSD$

PORTNAME=	mat
PORTVERSION=	1.6.0
CATEGORIES=	java devel
MASTER_SITES=	ECLIPSE/mat/1.6/update-site \
		ECLIPSE/releases/neon/201606221000:base
PKGNAMEPREFIX=	eclipse-
DISTFILES=	${BUNDLES} \
		${BUNDLE_DEPS:S/$/:base/}

MAINTAINER=	mizhka@gmail.com
COMMENT=	Memory Analyzer plugin for Eclipse IDE

LICENSE=	EPL

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

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

BUILDDATE=	20160531
BUILDTIME=	1117

FEATURES=	org.eclipse.mat.chart.feature \
		org.eclipse.mat.feature
PLUGINS=	org.eclipse.mat.api \
		org.eclipse.mat.chart \
		org.eclipse.mat.chart.ui \
		org.eclipse.mat.dtfj \
		org.eclipse.mat.hprof \
		org.eclipse.mat.ibmdumps \
		org.eclipse.mat.jdt \
		org.eclipse.mat.jruby.resolver \
		org.eclipse.mat.parser \
		org.eclipse.mat.report \
		org.eclipse.mat.ui \
		org.eclipse.mat.ui.help
DEPSLIST=	org.eclipse.birt.chart.device.extension_4.6.0.v201606072122.jar \
		org.eclipse.birt.chart.device.swt_4.6.0.v201606072122.jar \
		org.eclipse.birt.chart.engine_4.6.0.v201606072122.jar \
		org.eclipse.birt.chart.engine.extension_4.6.0.v201606072122.jar \
		org.eclipse.birt.core_4.6.0.v201606072122.jar \
		org.mozilla.javascript_1.7.5.v201504281450.jar

FEATURESLIST=	${FEATURES:S/$/_${PORTVERSION}.${BUILDDATE}${BUILDTIME}.jar/}
PLUGINSLIST=	${PLUGINS:S/$/_${PORTVERSION}.${BUILDDATE}${BUILDTIME}.jar/}

BUNDLES=	${FEATURESLIST:S/^/features\//} \
		${PLUGINSLIST:S/^/plugins\//}
		
BUNDLE_DEPS=	${DEPSLIST:S/^/plugins\//}

FEATURESWRK=	${FEATURESLIST:S/^/${WRKSRC}\//}
PLUGINSWRK=	${PLUGINSLIST:S/^/${WRKSRC}\//}
DEPSWRK=	${DEPSLIST:S/^/${WRKSRC}\//}

PLUGINDIR=	share/eclipse/dropins/${PORTNAME}/eclipse

FEATURESINST=	${FEATURESLIST:S/^/${WRKSRC}\//}
PLUGINSINST=	${PLUGINSLIST:S/^/${WRKSRC}\//}

do-patch:
	@(mkdir -p		${WRKSRC}/features)
	@(mv ${FEATURESWRK}	${WRKSRC}/features/)
	@(mkdir -p		${WRKSRC}/plugins)
	@(mv ${PLUGINSWRK}	${WRKSRC}/plugins/)
	@(mv ${DEPSWRK}		${WRKSRC}/plugins/)

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/${PLUGINDIR})

.include <bsd.port.mk>
