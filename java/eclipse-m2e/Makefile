# Created by: Michael Zhilin <mizhka@gmail.com>
# $FreeBSD$

PORTNAME=	m2e
PORTVERSION=	1.7.0
CATEGORIES=	java devel
MASTER_SITES=	ECLIPSE/technology/m2e/releases/1.7/${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		ECLIPSE/releases/neon/201606221000:base
PKGNAMEPREFIX=	eclipse-
DISTFILES=	${BUNDLES} \
		${BUNDLE_DEPS:S/$/:base/}

MAINTAINER=	mizhka@gmail.com
COMMENT=	Maven plugin for Eclipse IDE

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

BUILDDATE=	20160603
BUILDTIME=	1933

FEATURES=	org.eclipse.m2e.feature \
		org.eclipse.m2e.logback.feature \
		org.eclipse.m2e.sdk.feature
PLUGINS=	org.eclipse.m2e.archetype.common_${PORTVERSION}.${BUILDDATE}-1931 \
		org.eclipse.m2e.core.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.core.ui.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.core.ui_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.core_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.discovery.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.discovery_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.editor.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.editor.xml.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.editor.xml_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.editor_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.importer_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.jdt.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.jdt.ui.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.jdt.ui_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.jdt_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.launching.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.launching_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.lifecyclemapping.defaults_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.logback.appender.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.logback.appender_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.logback.configuration.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.logback.configuration_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.maven.indexer_${PORTVERSION}.${BUILDDATE}-1931 \
		org.eclipse.m2e.maven.runtime.slf4j.simple_${PORTVERSION}.${BUILDDATE}-1931 \
		org.eclipse.m2e.maven.runtime_${PORTVERSION}.${BUILDDATE}-1931 \
		org.eclipse.m2e.model.edit.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.model.edit_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.profiles.core.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.profiles.core_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.profiles.ui.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.profiles.ui_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.refactoring.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.refactoring_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.scm.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.scm_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.tests.common.source_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.tests.common_${PORTVERSION}.${BUILDDATE}-${BUILDTIME} \
		org.eclipse.m2e.workspace.cli_0.3.1
DEPSLIST=	ch.qos.logback.classic_1.0.7.v20121108-1250.jar \
		ch.qos.logback.core_1.0.7.v20121108-1250.jar \
		ch.qos.logback.slf4j_1.0.7.v201505121915.jar \
		com.google.guava_15.0.0.v201403281430.jar \
		org.apache.xerces_2.9.0.v201101211617.jar \
		org.apache.xml.resolver_1.2.0.v201005080400.jar \
		org.apache.xml.serializer_2.7.1.v201005080400.jar \
		org.eclipse.emf.ecore.edit_2.9.0.v20160526-0356.jar \
		org.eclipse.emf.edit_2.12.0.v20160526-0356.jar \
		org.eclipse.equinox.p2.discovery_1.0.400.v20160504-1450.jar \
		org.eclipse.equinox.p2.discovery.compatibility_1.0.200.v20131211-1531.jar \
		org.eclipse.equinox.p2.ui.discovery_1.0.200.v20160504-1450.jar \
		org.eclipse.jem.util_2.1.200.v201404021757.jar \
		org.eclipse.wst.common.core_1.2.0.v200908251833.jar \
		org.eclipse.wst.common.emf_1.2.400.v201505132009.jar \
		org.eclipse.wst.common.environment_1.0.400.v200912181831.jar \
		org.eclipse.wst.common.frameworks_1.2.200.v201304241450.jar \
		org.eclipse.wst.common.frameworks.ui_1.2.400.v201504292002.jar \
		org.eclipse.wst.common.project.facet.core_1.4.300.v201111030423.jar \
		org.eclipse.wst.common.ui_1.1.500.v200911182011.jar \
		org.eclipse.wst.common.uriresolver_1.2.200.v201505132009.jar \
		org.eclipse.wst.sse.core_1.1.1000.v201604120230.jar \
		org.eclipse.wst.sse.ui_1.3.500.v201605120129.jar \
		org.eclipse.wst.validation_1.2.700.v201508251749.jar \
		org.eclipse.wst.validation.ui_1.2.500.v201310231452.jar \
		org.eclipse.wst.xml.core_1.1.1000.v201605120036.jar \
		org.eclipse.wst.xml.ui_1.1.700.v201604272318.jar \
		org.eclipse.wst.xsd.core_1.1.900.v201401141857.jar \
		org.eclipse.xsd_2.12.0.v20160526-0356.jar \
		org.slf4j.api_1.7.2.v20121108-1250.jar

FEATURESLIST=	${FEATURES:S/$/_${PORTVERSION}.${BUILDDATE}/:S/$/-${BUILDTIME}.jar/}
PLUGINSLIST=	${PLUGINS:S/$/.jar/}

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
