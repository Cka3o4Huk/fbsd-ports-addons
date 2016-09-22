# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/java/eclipse-pydev/Makefile 412347 2016-04-01 14:08:37Z mat $

PORTNAME=	pydev
PORTVERSION=	5.2.0
CATEGORIES=	java devel python
MASTER_SITES=	https://dl.bintray.com/fabioz/${PORTNAME}/${PORTVERSION}/ \
		ECLIPSE/releases/neon/201606221000:base
PKGNAMEPREFIX=	eclipse-
DISTFILES=	${BUNDLES} \
		${BUNDLE_DEPS:S/$/:base/}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Eclipse plugin for Python and Jython development

LICENSE=	EPL

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:java/eclipse

JYTHON_DESC=	Use Jython as Python interpreter

OPTIONS_DEFINE=	JYTHON

PLUGINDIR=	share/eclipse/dropins/${PORTNAME}/eclipse/plugins
PYDEV_BUNDLES_INFO=	${PREFIX}/${PLUGINDIR}/bundles.info

USES=		python zip
USE_JAVA=	YES
JAVA_OS=	native
JAVA_RUN=	YES
JAVA_VERSION=	1.8+

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}/

BUILDDATE=	20160817
BUILDTIME=	1824

FEATURES=	org.python.pydev.feature \
		org.python.pydev.feature.source

PLUGINS=	com.python.pydev.analysis \
		com.python.pydev.codecompletion \
		com.python.pydev.debug \
		com.python.pydev.fastparser \
		com.python.pydev.refactoring \
		com.python.pydev \
		org.python.pydev.ast \
		org.python.pydev.core \
		org.python.pydev.customizations \
		org.python.pydev.debug \
		org.python.pydev.django \
		org.python.pydev.help \
		org.python.pydev.jython \
		org.python.pydev.parser \
		org.python.pydev.refactoring \
		org.python.pydev.shared_core \
		org.python.pydev.shared_interactive_console \
		org.python.pydev.shared_ui \
		org.python.pydev \
		com.python.pydev.analysis.source \
		com.python.pydev.codecompletion.source \
		com.python.pydev.debug.source \
		com.python.pydev.fastparser.source \
		com.python.pydev.refactoring.source \
		com.python.pydev.source \
		org.python.pydev.ast.source \
		org.python.pydev.core.source \
		org.python.pydev.customizations.source \
		org.python.pydev.debug.source \
		org.python.pydev.django.source \
		org.python.pydev.jython.source \
		org.python.pydev.parser.source \
		org.python.pydev.refactoring.source \
		org.python.pydev.shared_core.source \
		org.python.pydev.shared_interactive_console.source \
		org.python.pydev.shared_ui.source \
		org.python.pydev.source

DEPSLIST=	org.apache.commons.lang_2.6.0.v201404270220.jar \
		org.eclipse.emf.emfstore.common_1.8.0.v20160606-1028.jar \
		org.eclipse.mylyn.commons.core_3.20.0.v20160421-1819.jar \
		org.eclipse.mylyn.commons.screenshots_3.20.0.v20160421-1819.jar \
		org.eclipse.mylyn.commons.ui_3.20.0.v20160421-1819.jar \
		org.eclipse.mylyn.commons.workbench_3.20.0.v20160421-1819.jar \
		org.eclipse.mylyn.context.core_3.20.0.v20160421-1902.jar \
		org.eclipse.mylyn.context.ui_3.20.0.v20160421-1902.jar \
		org.eclipse.mylyn.ide.ui_3.20.0.v20160421-1902.jar \
		org.eclipse.mylyn.monitor.core_3.20.0.v20160421-1819.jar \
		org.eclipse.mylyn.monitor.ui_3.20.0.v20160421-1819.jar \
		org.eclipse.mylyn.resources.ui_3.20.0.v20160421-1902.jar

FEATURESLIST=	${FEATURES:S/$/_${PORTVERSION}.${BUILDDATE}${BUILDTIME}.jar/} \
		org.python.pydev.mylyn.feature_0.6.0.jar
PLUGINSLIST=	${PLUGINS:S/$/_${PORTVERSION}.${BUILDDATE}${BUILDTIME}.jar/} \
		org.python.pydev.mylyn_0.6.0.jar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJYTHON}
RUN_DEPENDS+=	jython:lang/jython
.endif

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
